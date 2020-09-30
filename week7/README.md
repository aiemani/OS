Hello,

Comments are present in all `.c` files

About garbage in the ex4:

1. As i understand, it is impossible to deduce the initial size of an array from 

    `void* reallocate_memory(int* p, int size);` 
  
  just by using a pointer `int* p` to this array. 

2. If **a new size is bigger than an old one**, then garbage may appear in the changed array. This happens after copying the data from an old array into a new one. As it was mentioned above, we cannot do copying within a loop 

  `for (int i = 0; i < min(old_size, new_size); i++);`

  just because we do not know `old_size`.

3. Hence, we cannot get rid from garbage in this case.

Have a nice day!