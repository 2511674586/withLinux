#!/usr/bin/python3
# http://deeplearning.net/software/theano/tutorial/examples.html

import numpy as np
import theano as tn
import logging

logging.basicConfig(format='%(levelno)s %(asctime)s %(process)d %(filename)s:%(lineno)d] %(message)s', level=logging.DEBUG)


rng = np.random
N = 400
feats = 784

'''
Generate dataset
'''
D = (rng.randn(N, feats), rng.randint(size=N, low=0, high=2))
training_steps = 10000

'''
theano symbolic variables
'''
x = tn.tensor.matrix('x')
y = tn.tensor.vector('y')

'''
initialize weight vector w and bias term randomly
'''
w = tn.shared(rng.randn(feats), name='w')
b = tn.shared(0., name='b')

print ("dump initial model")
for i in [w.get_value(), b.get_value()]:
    print (i)

'''
construct theano expression graph
'''
# prob that target = 1
p_1 = 1 / (1+tn.tensor.exp(-tn.tensor.dot(x,w) -b))
# prediction thresholded
prediction = p_1 > 0.5 
# cross entropy loss function
xent = -y * tn.tensor.log(p_1) - (1-y) * tn.tensor.log(1-p_1)
# cost to minimize
cost = xent.mean() + 0.01 * (w**2).sum()
# compute gradient of cost w.r.t w and b
gw, gb = tn.tensor.grad(cost, [w, b])
print (gw, gb)

'''
compile
'''
train = tn.function(
    inputs=[x,y],
    outputs=[prediction, xent],
    updates=((w, w-0.1*gw), (b, b-0.1*gb)))
predict = tn.function(
    inputs=[x],
    outputs=prediction)

'''
train
'''
for i in range(training_steps):
    if (i < training_steps*.1):
        if i%100==0: logging.info("iter %d"%i)
    elif (i < training_steps*.9):
        if i%500==0: logging.info("iter %d"%i)
    else:
        if i%100==0: logging.info("iter %d"%i)

    pred, err = train(D[0], D[1])

print ("Final model: ")
for i in [w.get_value(), b.get_value()]:
    print (i)
print ("target values for D:")
print (D[1])
print ("prediction on D:")
print (predict(D[0]))
