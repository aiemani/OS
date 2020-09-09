#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char request[100];
    
    while (1) {
        printf(">>> ");
        scanf("%s", request);
        system(request);
    }
    
    return 0;
}
