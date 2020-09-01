//
//  ex2.c
//  Exercise 2
//
//  Created by Roman Nabiullin on 01.09.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b);
void bubble_sort(int* array, int size);

void bubble_sort(int* array, int size) {
    
    bool swapped = true;
    
    while (swapped){
        
        swapped = false;
        
        for (int i = 0; i < size - 1; i++) {
            
            if (array[i] > array[i+1]) {
                swapped = true;
                swap(&array[i], &array[i+1]);
            }
            
        }
    }
}

void swap (int* a, int* b) {
    int tmp = *a;
    
    *a = *b;
    *b = tmp;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {9, 2, 4, 1, 90, -5, 2};
    int n = 7;
    
    printf("Source array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    bubble_sort(a, n);
    
    printf("\n\ndSorted:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    
    return 0;
}
