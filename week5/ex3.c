#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define MAX_BUFFER_SIZE 999999

// It was asked not to use protection mechanisms.
// So then one may see that some outputs of a thread after outputs of another thread contains wrong buffer size value. 

// This happens since during the printf execution the thread is blocked, and after the activation it contains old value that might have changed .

int buffer_size;

// producer thread function
void* producer(void* argument) {

  int iter = 0;

  while(TRUE) {

    // wait if the buffer is full
    while (buffer_size == MAX_BUFFER_SIZE);

    // print the size of the buffer and some value
    if (iter % 37 == 0) {
      printf("Producer:  %d - buffer size, %d - value\n", buffer_size, iter * iter);
    }

    // producer creates a new value
    if (iter < MAX_BUFFER_SIZE) {
      buffer_size++;
      iter++;
    }
  }
}

// The behavior of this function is similar to the one above
void* consumer(void* argument) {
  int iter = 0;

  while(TRUE) {

    // wait if the buffer is empty
    while (buffer_size == 0);

    // print the size of the buffer and some value
    if (iter % 37 == 0) {
      printf("Consumer:  %d - buffer size, %d - value\n", buffer_size, iter * iter);
    }

    // consumer consumes a value
    if (iter < MAX_BUFFER_SIZE) {
      buffer_size--;
      iter++;
    }
  }
}

int main() {

  // initial buffer size value
  buffer_size = 0;

  pthread_t producer_thread;
  pthread_t consumer_thread;
  
  // creating threads
  pthread_create(&producer_thread, NULL, &producer, NULL);
  pthread_create(&consumer_thread, NULL, &consumer, NULL);

  pthread_join(producer_thread, NULL);

  // exits
  pthread_exit(NULL);
  exit(EXIT_SUCCESS);
}
