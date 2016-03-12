#!/usr/bin/python3
# http://deeplearning.net/software/theano/tutorial/examples.html

from theano import *
from theano.tensor.shared_randomstreams import RandomStreams

'''
adding two scalars
'''
x = tensor.dscalar('x')
y = tensor.dscalar('y')
z = x + y
f = function([x, y], z)
print (f(2,3))
print (numpy.allclose(f(16.3, 12.1), 28.4))

'''
adding two matrices
'''
x = tensor.dmatrix('x')
y = tensor.dmatrix('y')
z = x + y
f = function([x, y], z)
print (f([[1, 2], [3, 4]], [[10, 20], [30, 40]]))
print (f(numpy.array([[1, 2], [3, 4]]), numpy.array([[10, 20], [30, 40]])))

'''
implement logistic function
 s(x) = \frac{1}{1+e^{-x}}
'''
x = tensor.dmatrix('x')
s = 1 / (1+tensor.exp(-x))
logistic = theano.function([x], s)
print (logistic([[0,1],[-1,-2]]))

'''
implement 2
'''
s2 = (1+tensor.tanh(x/2)) / 2
logistic2 = theano.function([x], s2)
print (logistic2([[0,1],[-1,-2]]))

'''
compute more than one thing at the same time
'''
a, b = tensor.dmatrices('a', 'b')
diff = a - b
abs_diff = abs(diff)
diff_sq = diff**2
f = theano.function([a, b], [diff, abs_diff, diff_sq])
print (f([[1,1], [1,1]], [[0,1],[2,3]]))

'''
settting default value for an argument
'''
x, y = tensor.dscalars('x', 'y')
z = x + y
f = function([x, In(y, value=1)], z)
print (f(33))
print (f(33,2))

'''
using shared variables
'''
state = shared(0)
inc = tensor.iscalar('inc')
accumulator = function([inc], state, updates=[(state, state+inc)])
print (state.get_value())
accumulator(1)
print (state.get_value())
accumulator(300)
print (state.get_value())
state.set_value(-1)
accumulator(3)
print (state.get_value())
decrementor = function([inc], state, updates=[(state, state-inc)])
decrementor(2)
print (state.get_value())

'''
using random numbers
'''
srng = RandomStreams(seed=234)
rv_u = srng.uniform((2,2))
rv_n = srng.normal((2,2))
f = function([], rv_u)
g = function([], rv_n, no_default_updates=True)
nearly_zeros = function([], rv_u + rv_u - 2 * rv_u)
f_val0 = f()
f_val1 = f()
g_val0 = g()
g_val1 = g()
for i in [f_val0, f_val1, g_val0, g_val1]:
    print (i)
