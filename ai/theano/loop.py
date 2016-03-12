#!/usr/bin/python3
# http://deeplearning.net/software/theano/tutorial/loop.html

import numpy as np
import theano as tn

'''
example 1
'''
k = 10
A = 2

result = 1
for i in range(k):
    result = result * A
print (result)

k = tn.tensor.iscalar('k')
A = tn.tensor.vector('A')
result, updates = tn.scan(
    fn=lambda prior_result, A : prior_result * A,
    outputs_info=tn.tensor.ones_like(A),
    non_sequences=A,
    n_steps=k
)
final_result = result[-1]
power = tn.function(
    inputs=[A,k],
    outputs=final_result,
    updates=updates
)
print (power(range(10),2))
print (power(range(10),4))


'''
example 2
'''
X = tn.tensor.matrix('X')
W = tn.tensor.matrix('W')
b_sym = tn.tensor.vector('b_sym')

results, updates = tn.scan(
    lambda v: tn.tensor.tanh(tn.tensor.dot(v, W) + b_sym),
    sequences=X
)
compute_elementwise = tn.function(
    inputs=[X,W,b_sym],
    outputs=[results]
)

x = np.eye(2, dtype=tn.config.floatX)
w = np.ones((2,2), dtype=tn.config.floatX)
b = np.ones((2), dtype=tn.config.floatX)
b[1] = 2

print (compute_elementwise(x, w, b)[0])
print (np.tanh(x.dot(w)+b))

