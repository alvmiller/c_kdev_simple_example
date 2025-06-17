#!/bin/bash

sudo apt-get update && apt-get -y install \
	dkms openssl xxd linux-headers-$(uname -r) \
	gcc make build-essential libncurses-dev bison flex libssl-dev libelf-dev dwarves kmod \
	linux-headers-`uname -r`

clear
reset

echo "Starting..."
sleep 1
echo -e "\n"

sudo rmmod example_dev.ko
make clean
make
modinfo example_dev.ko
sleep 1
echo -e "\n"

gcc -o client client.c
sleep 1
echo -e "\n"

lsmod | grep example_dev
ls -la
sudo dmesg -C
sleep 1
echo -e "\n"

sudo insmod example_dev.ko
sleep 1
echo -e "\n"

lsmod | grep example_dev
if lsmod | grep -q 'example_dev'; then
  echo "Found Module!"
else
	echo "Not Found Module!"
	sudo dmesg | tail -1
	sleep 1
	echo -e "\n"
	exit 1
fi
sleep 1
echo -e "\n"

sudo ./client
sleep 1
echo -e "\n"

make clean
sudo rmmod example_dev.ko
lsmod | grep example_dev
sudo dmesg
sleep 1
echo -e "\n"

echo "Finishing..."
sleep 1
echo -e "\n"
