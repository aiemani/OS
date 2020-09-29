#include <stdio.h> 
#include <stdlib.h> // Change 1 = library for malloc()

int main() {
  
  char **s;
  char foo[] = "Hello World";

  // Change 2
  // We should allocate memory for 's' beforehand
  // After, the segmentation fault dissapears.
  s = malloc(sizeof(char*));

  *s = foo;
  
  printf("s is %s\n",s);
  
  s[0] = foo;
  
  printf("s[0] is %s\n",s[0]);

  return(0);
}