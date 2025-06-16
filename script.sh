#!/bin/bash

echo "Starting..."

clear
reset
sleep 1

make clean
gcc -o client client.c
make
modinfo example_dev.ko

lsmod | grep example_dev
sudo dmesg -C
sudo insmod example_dev.ko
sleep 1
lsmod | grep example_dev
if lsmod | grep -q 'example_dev'; then
  echo "Found Module!"
fi
sudo ./client
sleep 1
sudo rmmod example_dev.ko
lsmod | grep example_dev
sudo dmesg

make clean
echo "Finishing..."
