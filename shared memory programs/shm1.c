#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	unsigned char *memptr;
	char memName[] = "SharedMemory";
	int fd,memSize=100;
	fd=shm_open(memName,O_CREAT | O_RDWR,S_IRUSR|S_IWUSR);
	printf("Shared memory object is created as %s\n",memName);
	ftruncate(fd,memSize);
	return 0;
}

