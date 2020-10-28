#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	char *p;
	struct stat buffer;

	// Open the file
	int fd = open("ex1.txt", O_RDWR);

	// Its Status
	if (fstat(fd, &buffer)) {
		fprintf(stderr, "Error : %s\n", strerror(errno));
		return -1;
	}

	// mmap
	p = mmap(NULL, buffer.st_size, PROT_WRITE, MAP_SHARED, fd, 0);

	// Rewriting
	strncpy(p, "This is a nice day", buffer.st_size);

  printf("%ld", buffer.st_size);

	// Exit	
	munmap(p, buffer.st_size);
	close(fd);
	return 0;
}