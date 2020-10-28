#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>


int main() {
  struct stat buffer;
	char *source, *destination;

	// Open ex1.txt, ex1_memcp.txt
  int destinationfd = open("ex1_memcp.txt", O_CREAT | O_RDWR);
	int sourcefd = open("ex1.txt", O_RDONLY);

	// Status of ex1.txt
	if (fstat(sourcefd, &buffer)) {
		fprintf(stderr, "Error occurs: %s\n\n", strerror(errno));
		return 1;
	}

	// Mmap
	source = mmap(NULL, buffer.st_size, PROT_READ, MAP_SHARED, sourcefd, 0);
	ftruncate(destinationfd, buffer.st_size);
	destination = mmap(NULL, buffer.st_size, PROT_WRITE, MAP_SHARED, destinationfd, 0);

	// Writing
	memcpy(destination, source, buffer.st_size);

	// Exit	
	munmap(source, buffer.st_size);
	munmap(destination, buffer.st_size);
	close(sourcefd);
	close(destinationfd);
	return 0;
}