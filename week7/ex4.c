#include <stdio.h>
#include <stdlib.h>

// Reallocation works with new sizes that are greater/less than initial one, 
//    or even with 0.
//
// Also, the case when p = NULL is considered. 
void* reallocate_memory(int* p, int size) {
  if (p == NULL) {            // Just like malloc
    return malloc(size);

  } else if (size == 0) {     // Just like free
    free(p);
    return NULL;

  } else {                    // Reallocation

    // Creating new array
    int* new_array = malloc(size);

    // Copy the data to it
    if (new_array) {
      for (int i = 0; i < size; i++) {
        *(new_array + i) = *(p + i);
      }
    }

    free(p);
    return new_array;
  }
}

int main() {

  int init_size = 5;
  int final_size = 10;

  // Filling the array with init_size
  int *arr = malloc(sizeof(int)*init_size);

  // Printing it
	printf("Ininital Array: ");
  for (int i = 0; i < init_size; ++i) {
    *(arr + i) = i*i;
		printf("%d ", *(arr + i));
	}
	

  // Change the size
  arr = reallocate_memory(arr, sizeof(int)*final_size);

  // Printing it.
  // It may be filled with some junk after increasing the size
	printf("\nTest the realloc implementation: "); 
  for (int i = 0; i < final_size; ++i) {
		printf("%d ", *(arr + i));
	}
	
  printf("\n");

	return 0;
}