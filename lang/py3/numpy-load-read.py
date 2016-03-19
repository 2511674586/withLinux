#!/usr/bin/python3
# @see http://docs.scipy.org/doc/numpy/reference/routines.io.html

import numpy as np

a = np.zeros( (10,3) )
np.savez('junk.npz', a)
np.savetxt('junk.txt', a)

x = np.load('junk.npz')
print (x)
for k,v in x.iteritems():
    print (k, v)

y = np.loadtxt('junk.txt')
print (y)
