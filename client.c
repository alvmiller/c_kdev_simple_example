#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

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
