#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
  char s[] = "Hello";

	for (int i = 0; i < 5; i++) {
		printf("%c", s[i]);
		sleep(1);
	}
	return 0;
}