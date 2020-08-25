//
//  main.c
//  Exercise 1
//
//  Created by Roman Nabiullin on 25.08.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(int argc, const char * argv[]) {
    
    int a = INT_MAX;
    double b = DBL_MAX;
    float c = FLT_MAX;
    
    printf("max int = %d, its size =  %lu\n\n", a, sizeof(a));
    printf("max double = %g, its size =  %lu\n\n", b, sizeof(b));
    printf("max float = %g, its size =  %lu\n\n\n", c, sizeof(c));
    
    return 0;
}

