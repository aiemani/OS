#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thin_thread(void* something) {
  printf("><><>Thread<><>< is created...\n\n");
}

int main(int argc, const char * argv[]) {

  pthread_t thread_ID;
    
  for (int i = 0; i < 3; i++) {
    pthread_create(&thread_ID, NULL, &thin_thread, NULL);
    printf("Let us create the thread number %d\n", i);
    pthread_join(thread_ID, NULL);
  }

	exit(EXIT_SUCCESS);
}