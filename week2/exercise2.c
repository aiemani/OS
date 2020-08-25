//
//  main.c
//  Exercise 2
//
//  Created by Roman Nabiullin on 25.08.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int length = 10000;
    char string[length];
    
    gets(string);
    
    for (int i = strlen(string) - 1; 0 <= i; i--) {
        putchar(string[i]);
    }
    
    printf("\n");
    
    return 0;
}

