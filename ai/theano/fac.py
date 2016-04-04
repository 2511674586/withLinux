# @ref http://deeplearning.net/software/theano/faq.html#what-are-theano-s-limitations
# Theano supports for- or while- loop within its symbolic graph,
# but it doesn't support neither recursion, nor goto!

# 1. traditional recursion
def factorial(x):
    if x == 0:
        return 1
    else:
        return x * factorial(x-1)

print (factorial(10))

# 2. theano's symbolic graph cannot perform recursion
from theano import *
x = tensor.dscalar('x')
f = function([x], tensor.switch(tensor.eq(x, 0), 1, f(x-1)))

