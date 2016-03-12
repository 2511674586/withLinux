#!/usr/bin/python3
# http://deeplearning.net/software/theano/tutorial/gradients.html

import numpy as np
import theano as tn

x = tn.tensor.dscalar('x')
y = x**2
gy = tn.tensor.grad(y, x)
print ('dump gradient function')
print (tn.pp (gy))
print ('--> fill((x ** 2), 1.0) means ones(size(x**2))')

f = tn.function([x], gy)
print (tn.pp (f.maker.fgraph.outputs[0]))
print (f(4))
print (np.allclose(f(94.2), 188.4))

'''
derivative of logistic?
'''
x = tn.tensor.dscalar('x')
s = 1 / (1+tn.tensor.exp(-x))
gs = tn.tensor.grad(s, x)
ds = tn.function([x], gs)
print (tn.pp(ds.maker.fgraph.outputs[0]))

'''
my test
'''
x = tn.tensor.dscalar('x')
y = 4*x**3 + 2*x +1
gy = tn.tensor.grad(y, x)
dy = tn.function([x], gy)
print (tn.pp(dy.maker.fgraph.outputs[0]))
