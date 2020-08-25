//
//  main.c
//  Exercise 4
//
//  Created by Roman Nabiullin on 25.08.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b) {
    
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int main(int argc, const char * argv[]) {
    
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    swap(&a, &b);
    
    printf("%d %d\n\n", a, b);
    
    return 0;
}
