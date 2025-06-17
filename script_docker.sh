#!/bin/bash

clear
reset

echo "Starting..."
sleep 1
echo -e "\n"

rmmod example_dev.ko
make clean
make
modinfo example_dev.ko
sleep 1
echo -e "\n"

gcc -o client client.c
sleep 1
echo -e "\n"

xxd -i example_dev.ko >example_dev.ko.h
gcc -o init init_ko.c
sleep 1
echo -e "\n"

lsmod | grep example_dev
ls -la
dmesg -C
sleep 1
echo -e "\n"

./init
#insmod example_dev.ko
sleep 1
echo -e "\n"

lsmod | grep example_dev
if lsmod | grep -q 'example_dev'; then
  echo "Found Module!"
else
	echo "Not Found Module!"
	dmesg | tail -1
	sleep 1
	echo -e "\n"
	exit 1
fi
sleep 1
echo -e "\n"

./client
sleep 1
echo -e "\n"

make clean
rmmod example_dev.ko
lsmod | grep example_dev
dmesg
sleep 1
echo -e "\n"

echo "Finishing..."
sleep 1
echo -e "\n"
