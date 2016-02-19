#!/usr/bin/python

import socket

s = socket.socket (socket.AF_INET, socket.SOCK_STREAM)
s.connect (('localhost', 2333))
s.send ('hello, server')
data = s.recv (1024)
s.close()
print ('recieved :', data)


