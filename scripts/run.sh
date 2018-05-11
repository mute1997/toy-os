#!/bin/sh

if uname | grep Darwin > /dev/null ; then
  make clean && make osx && make qemu
elif uname | grep Linux > /dev/null ; then
  make clean && make && make image && make qemu
fi
