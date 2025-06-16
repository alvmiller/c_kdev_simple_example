# c_kdev_simple_example
c_kdev_simple_example

IN PROGRESS...

/*

https://github.com/alvmiller/cpp_helloworld_docker_naive_example
https://github.com/alvmiller/cpp_client_server_one_docker_example
https://github.com/alvmiller/cpp_client_server_multi_docker_example

https://github.com/alvmiller/hello_drv
https://github.com/alvmiller/hello_module
https://github.com/alvmiller/cpp_client_server_one_docker_example

https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-programming/
https://olegkutkov.me/2018/03/14/simple-linux-character-device-driver/
https://embetronicx.com/tutorials/linux/device-drivers/ioctl-tutorial-in-linux/
https://stackoverflow.com/questions/22632713/how-to-write-a-simple-linux-device-driver
https://www.apriorit.com/dev-blog/195-simple-driver-for-linux-os
https://embetronicx.com/tutorials/linux/device-drivers/device-file-creation-for-character-drivers/
https://jvgd.medium.com/how-to-write-a-device-driver-76d0584a4be3
https://www.acmesystems.it/compile_a_device_driver
https://github.com/Techogenius/Linux-device-driver-code/tree/master
https://faun.pub/building-the-simple-kernel-module-from-linux-device-drivers-on-arch-linux-9a8374a502a3
https://devarea.com/linux-kernel-development-and-writing-a-simple-kernel-module/
https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234

https://www.kernel.org/doc/html/v4.10/process/coding-style.html
https://kworkflow.org/tutorials/codestyle.html

https://gist.github.com/brenns10/65d1ee6bb8419f96d2ae693eb7a66cc0
https://olegkutkov.me/2018/03/14/simple-linux-character-device-driver/
https://collaborationbetterstheworld.com/insights/from-novice-to-expert-building-robust-linux-character-device-drivers
https://gist.github.com/itrobotics/063aea3c72d1f7d7fb94
https://linux-kernel-labs.github.io/refs/heads/master/labs/device_drivers.html
https://embetronicx.com/tutorials/linux/device-drivers/device-file-creation-for-character-drivers/
https://flusp.ime.usp.br/kernel/char-drivers-intro/
https://olegkutkov.me/2018/03/14/simple-linux-character-device-driver/
https://chrizog.com/linux-device-driver-tutorial-ultrasonic-sensor-2

https://embetronicx.com/tutorials/linux/device-drivers/ioctl-tutorial-in-linux/
https://github.com/pokitoz/ioctl_driver
https://linux.die.net/lkmpg/x892.html
https://github.com/Tristaan/linux-driver-ioctl-example/blob/main/userspace.c
https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-ioctl-control-device

https://embetronicx.com/tutorials/linux/device-drivers/sending-signal-from-linux-device-driver-to-user-space/
https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-part-13-interrupt-example-program-in-linux-kernel/
https://www.c-pointers.com/LinuxDeviceDriver/basic_ldd/chapter2_kthreads/kthread_signal/kthread_signal.html
https://www.oreilly.com/library/view/linux-device-drivers/0596005903/ch10.html

https://embetronicx.com/tutorials/linux/device-drivers/linux-device-drivers-tutorial-kernel-thread/
https://girishjoshi.io/post/creating-linux-kernel-threads/
https://cylab.be/blog/347/linux-kernel-threads-and-processes-management-task-struct
https://www.linuxtoday.com/blog/kernel-threads/
https://github.com/muratdemirtas/Linux-Kernel-Examples/blob/master/kernel-threads.c
https://embitude.in/index.php/2021/05/29/kernel-threads/
https://www.ibm.com/docs/en/aix/7.2.0?topic=environment-understanding-kernel-threads

https://stackoverflow.com/questions/62455239/making-building-a-kernel-module-inside-a-docker-container
https://projectatomic.io/blog/2018/06/building-kernel-modules-with-podman/
https://www.baeldung.com/linux/docker-container-kernel-modules
https://github.com/djs55/docker-desktop-example-kernel-module
https://mgalgs.io/2021/03/23/how-to-build-a-custom-linux-kernel-for-qemu-using-docker.html

https://askubuntu.com/questions/1500017/ubuntu-22-04-default-gcc-version-does-not-match-version-that-built-latest-defaul


sudo apt-get install \
     gcc make build-essential libncurses-dev bison flex libssl-dev libelf-dev dwarves \
     linux-headers-`uname -r`
chmod +x script.sh
gcc -o client client.c
make
modinfo example_dev.ko
lsmod | grep example_dev
sudo insmod ./example_dev.ko
sudo dmesg
lsmod | grep example_dev
sudo ./client
sudo rmmod example_dev
lsmod | grep example_dev
make test

sudo su
echo Test0 >/dev/example_dev
cat /dev/example_dev


sudo apt install --reinstall gcc-12

sudo apt install libmodule-info-perl

*/
