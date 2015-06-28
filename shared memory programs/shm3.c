#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	unsigned char *memptr;
	char memName[] = "SharedMemory", message[100];
	int fd, i, memSize = 100;
	fd = shm_open(memName, O_RDWR, S_IRUSR | S_IWUSR);
	printf("Shared memory object is opened as %s\n", memName);
	ftruncate(fd, 100);
	memptr = mmap(NULL, memSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("Message is: ");
	for(i = 0; memptr[i] != 0; i++)
		printf("%c", memptr[i]);
	printf("\n");
	return 0;
}
