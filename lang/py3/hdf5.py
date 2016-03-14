#!/usr/bin/python3
# > http://docs.h5py.org/en/latest/quick.html

import logging as log
log.basicConfig(
  format='\x1b[36;1mL%(asctime)s %(process)d %(filename)s:%(lineno)d]'
    +' %(message)s\x1b[m',
  datefmt='%m%d %I:%M:%S',
  level=log.DEBUG
)

import h5py
import numpy as np

'''
Groups work like dictionaries, and datasets work like NumPy arrays
'''

log.info('create hdf5 file')
f = h5py.File ('tmpfile.hdf5', 'w')

log.info('create dataset')
dataset = f.create_dataset ('dataset', (100,), dtype='i')

log.info('assign data')
dataset[...] = np.arange(100)

log.info('dump database information')
print (dataset[1:10])
print (dataset.shape)
print (dataset.dtype)
print (dataset.size)
print (f.name)
print (dataset.name)

log.info('create groups')
group = f.create_group ('group')
dataset2 = group.create_dataset('another_dataset', (50,), dtype='f')
print (dataset2.name)
dataset3 = f.create_dataset('group2/data2', (10,), dtype='d')
print (dataset3.name)

log.info('retrieve data2')
data2 = f['group2/data2']
print (data2.name)

log.info('dump level 1 database entry')
for name in f:
    print (name)

log.info('dump all database entries')
f.visit(lambda x: print (x))
print (f.keys())

log.info('assign attribute')
dataset.attrs['temperature'] = 123.4

log.info('hard link')
f['hard/data1'] = f['dataset']
print (f['hard/data1'] == f['dataset'])

log.info('soft link')
f['soft/data1'] = h5py.SoftLink('/dataset')
print (f['soft/data1'] == f['/dataset'])

print()
log.info('re-reading hdf5 database')
f.close()
f = h5py.File ('tmpfile.hdf5', 'r')
dset = f.require_dataset ('dataset', (100,), dtype='i')
print (dset[1:10])

log.info('again, dump the tree of database')
f.visit(lambda x: print(x))
f.close()

log.info('demo end')
