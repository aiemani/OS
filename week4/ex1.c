#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// One may notice that child and parent messages from processes can be disordered. This happens simply because a number of cores can simultaneously execute processes of this program.

int main(int argc, const char * argv[]) {

    int n = 10;
    long f = fork();
    pid_t pid = getpid();
        
    if (f == 0) {
        printf("Hello from child [%d - %d]\n", pid, n);
    } else if (f > 1){
        printf("Hello from parent [%d - %d]\n", pid, n);
    } else {
        return 1;
    }
    
    return 0;
}