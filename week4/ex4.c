#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char request[100];
  
    while(1){

        printf(">>> ");
        fgets(request, 100,stdin);

        // Here we create a fork process
        int f = fork();

        // Execution is done from child process
        if(f == 0){
            system(request);
            break;
        }
    }
    
    return 0;
}
