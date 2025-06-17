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
https://www.oreilly.com/library/view/linux-device-drivers/0596005903/ch02.html

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
https://xcellerator.github.io/posts/docker_escape/
https://github.com/xcellerator/linux_kernel_hacking/tree/079d97b8e0b25e437ea4d5aa2fa4e85feff67583
https://iximiuz.com/en/posts/from-docker-container-to-bootable-linux-disk-image/
https://blog.pentesteracademy.com/abusing-sys-module-capability-to-perform-docker-container-breakout-cf5c29956edd
https://stackoverflow.com/questions/33013539/docker-loading-kernel-modules
https://www.rancher.com/docs/os/v1.2/en/configuration/kernel-modules-kernel-headers/
https://www.reddit.com/r/LiveOverflow/comments/ugbjvf/unable_to_execute_insmod_on_docker_container/
https://medium.com/@xUr00U/docker-container-breakout-part-1-d364fede4209


https://askubuntu.com/questions/1500017/ubuntu-22-04-default-gcc-version-does-not-match-version-that-built-latest-defaul
https://stackoverflow.com/questions/16360689/invalid-parameters-error-when-trying-to-insert-module-that-accesses-exported-s
https://askubuntu.com/questions/1150155/unknown-symbol-in-module-but-what-symbol
https://stackoverflow.com/questions/16360689/invalid-parameters-error-when-trying-to-insert-module-that-accesses-exported-s
https://discussion.fedoraproject.org/t/insmod-permission-error-when-being-ran-from-systemd-service/74145/4
https://stackoverflow.com/questions/67525731/error-unknown-symbol-copy-to-user-during-module-load
https://slavamoskvin.com/finding-bugs-in-kernel.-part-1-crashing-a-vulnerable-driver-with-syzkaller/
https://community.intel.com/t5/Nios-V-II-Embedded-Design-Suite/MODPOST-copy-from-user-module-compilation-issue/td-p/73584




sudo docker run -it --privileged --hostname docker ubuntu

sudo docker run -it --privileged --hostname docker --mount "type=bind,src=$PWD,dst=/root" ubuntu

sudo docker run -it --privileged --hostname docker ubuntu
exit
sudo docker run --rm -it --privileged example:1 bash
cat /proc/kallsyms | grep copy_to_user
--cap-add SYS_MODULE
--cap-add=ALL

sudo apt install --reinstall gcc-12
sudo apt install libmodule-info-perl


sudo docker pull docker.io/kalilinux/kali-rolling
sudo docker image ls
  kali: 729006db3366
sudo docker run --cap-add SYS_MODULE -it --name breakout  729006db3366 /bin/bash
apt update -y && apt install \
	gcc -y && apt install nano -y && apt-get install libcap2-bin -y && \
	apt install make -y && apt install net-tools -y 
capsh --print
  cap_sys_module
nano reverse-shell.c
  code
ifconfig
apt-get install linux-headers-$(uname -r)
find / -name kmod.h 2>/dev/null
nano Makefile
  code
make
nc -nlvp 4444
insmod reverse-shell.ko


******************

https://xcellerator.github.io/posts/docker_escape/
https://github.com/xcellerator/linux_kernel_hacking/tree/079d97b8e0b25e437ea4d5aa2fa4e85feff67583/3_RootkitTechniques/3.8_privileged_container_escaping
https://blog.pentesteracademy.com/abusing-sys-module-capability-to-perform-docker-container-breakout-cf5c29956edd
https://www.reddit.com/r/LiveOverflow/comments/ugbjvf/unable_to_execute_insmod_on_docker_container/
https://medium.com/@xUr00U/docker-container-breakout-part-1-d364fede4209


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
exit

From Host:
sudo ./script_docker.sh

sudo apt update && sudo apt upgrade -y
sudo apt install -y ca-certificates curl gnupg
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt update
sudo apt install -y docker-ce docker-ce-cli containerd.io
sudo usermod -aG docker $USER
sudo curl -L "https://github.com/docker/compose/releases/download/$(curl -s https://api.github.com/repos/docker/compose/releases/latest | grep 'tag_name' | cut -d'"' -f4)/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
docker-compose --version
sudo systemctl enable docker

sudo docker build . -t example:1
sudo docker run --rm -it --cap-add SYS_MODULE --privileged example:1

******************

*/
