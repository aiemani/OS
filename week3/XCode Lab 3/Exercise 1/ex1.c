//
//  ex1.c
//  Exercise 1
//
//  Created by Roman Nabiullin on 01.09.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>

int main(){
    int* pc;
    int c;
    c = 22;
    printf("Address of c:%d\n",&c);
    printf("Value of c:%d\n\n",c);
    
    pc = &c;
    
    printf("Address of pointer pc:%d\n",pc);
    printf("Content of pointer pc:%d\n\n",*pc);
    
    c = 11;
    
    printf("Address of pointer pc:%d\n",pc);
    printf("Content of pointer pc:%d\n\n",*pc);
    
    *pc=2;
    
    printf("Address of c:%d\n",&c);
    printf("Value of c:%d\n\n",c);
    
    return 0;
}
