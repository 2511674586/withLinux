#!/bin/sh
# set -e
# show how to run a java program on linux

echo "removing all class files"
rm ./*.class
echo 

echo "compile the hello word program hello.java"
javac hello.java
echo 

echo "run the compiled program with java"
java Main

# reference: http://docs.oracle.com/javase/tutorial/getStarted/cupojava/unix.html
