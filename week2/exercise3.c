//
//  main.c
//  Exercise 3
//
//  Created by Roman Nabiullin on 25.08.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <=n; i++) {
        
        int spaces = n - i;
        int stars = 2*i - 1;

        while (spaces > 0) {
            spaces--;
            putchar(' ');
        }
        
        while (stars > 0) {
            stars--;
            putchar('*');
        }
        
        putchar('\n');
    }

    
    return 0;
}

