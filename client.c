#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

/*

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
OR
./script_host.sh

sudo docker build . -t example:1
sudo docker run --rm -it --cap-add SYS_MODULE --privileged example:1

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

******************

*/

#define CLIENT_SIZE (128)
const uint8_t write_buf[CLIENT_SIZE] = { 'H', 'e', 'l', 'l', 'o' };
uint8_t read_buf[CLIENT_SIZE];

int main()
{
	int fd = open("/dev/example_dev", O_RDWR);
	if(fd < 0) {
		perror("Can't open Drv");
		return -1;
	}
        
	printf("String to write into driver: %s\n", (char *)write_buf);
	printf("Data Writing ...");
	write(fd, write_buf, strlen(write_buf)+1);
	printf("Done!\n");

	printf("Data Reading ...");
	read(fd, read_buf, CLIENT_SIZE);
	printf("Done!\n");
	printf("Data = %s\n\n", (char *)read_buf);

	close(fd);
	return 0;
}
