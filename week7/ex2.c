#include <stdio.h>
#include <stdlib.h>

int main() {

  int n;

  // Reading the size of the array
  printf("Please, input the size of the array: ");
  scanf("%d", &n);

  // Allocating memory for the array
  int* array = malloc(n*sizeof(int));

  // Filling the array
  for (int i = 0; i < n; i++) {
    *(array + i) = i;
  }

  printf("\nHere a generated array:\n");

  // Printing the array
  for (int i = 0; i < n; i++) {
    printf("%d ", *(array + i));
  }

  printf("\n");

  // Deallocating memory for the array
  free(array); 

  return 0;
}