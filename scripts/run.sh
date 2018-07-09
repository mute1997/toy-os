#!/bin/sh

if [ ! -e build ] ; then
  mkdir build
fi

# make clean
if uname | grep Darwin > /dev/null ; then
  make osx && make qemu
elif uname | grep Linux > /dev/null ; then
  make && make image && make qemu
fi
