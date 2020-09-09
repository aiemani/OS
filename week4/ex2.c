#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*

init─┬─bash───bash─┬─ex2───ex2
     │             └─pstree

init─┬─bash───bash─┬─ex2───ex2
     │             └─pstree

init─┬─bash───bash─┬─ex2─┬─ex2───ex2
     │             │     └─ex2
     │             └─pstree

init─┬─bash───bash─┬─ex2─┬─ex2─┬─ex2───ex2
     │             │     │     └─ex2
     │             │     ├─ex2───ex2
     │             │     └─ex2
     │             └─pstree

init─┬─bash───bash─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
     │             │     │     │     └─ex2
     │             │     │     ├─ex2───ex2
     │             │     │     └─ex2
     │             │     ├─ex2─┬─ex2───ex2
     │             │     │     └─ex2
     │             │     ├─ex2───ex2
     │             │     └─ex2
     │             └─pstree

init─┬─bash───bash─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
     │             │     │     │     │     └─ex2
     │             │     │     │     ├─ex2───ex2
     │             │     │     │     └─ex2
     │             │     │     ├─ex2─┬─ex2───ex2
     │             │     │     │     └─ex2
     │             │     │     ├─ex2───ex2
     │             │     │     └─ex2
     │             │     ├─ex2─┬─ex2─┬─ex2───ex2
     │             │     │     │     └─ex2
     │             │     │     ├─ex2───ex2
     │             │     │     └─ex2
     │             │     ├─ex2─┬─ex2───ex2
     │             │     │     └─ex2
     │             │     ├─ex2───ex2
     │             │     └─ex2
     │             └─pstree
*/

// The output above(5 souce fork() calls) stands for the following:
//    We have a process that has to execute N forks and N corresponding processes
//        that have to execute N-1, N-2, N-3, N-4 and up to 0 forks

// That is why for 3 source fork() calls we have 2^3 = 8 processes created,
//    for 5 source fork() calls we have 2^5 = 32 processes created,

// And for N source fork() calls, we have 2^N processes created.

int main(int argc, char *argv[]) {

	for (int i = 0; i < 5; i++) {
		fork();
    sleep(5);
	}
  
  return 0;
}