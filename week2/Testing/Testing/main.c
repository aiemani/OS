//
//  main.c
//  Testing
//
//  Created by Roman Nabiullin on 25.08.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char c1, c2, *p;
    
    c1 = 'a';
    p = &c1;
    c2 = *p;
    
    printf("Amazing!\n%c equals to %c\n", c1, c2);
    
    return 0;
}
