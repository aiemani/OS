//
//  main.c
//  XCode Lab 3
//
//  Created by Roman Nabiullin on 01.09.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>
int main()
{
    int arri[] = {1, 2 ,3};
    int *ptri = arri;
 
    char arrc[] = {1, 2 ,3};
    char *ptrc = arrc;
 
    printf("sizeof arri[] = %lu \n\n", sizeof(arri));
    printf("sizeof ptri = %lu \n\n", sizeof(ptri));
 
    printf("sizeof arrc[] = %lu \n\n", sizeof(arrc));
    printf("sizeof ptrc = %lu \n\n", sizeof(ptrc));
 
    return 0;
}
