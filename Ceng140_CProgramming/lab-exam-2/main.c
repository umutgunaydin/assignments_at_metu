#include <stdio.h>
#include "lab_2.h"

int main(){
    /* Initialize your own inputs like this */
    float arr[] = {9.2, 11.82, 5.32};
    float l;
    int size = 3;
    int i;
    
    /* Call any function that you have implemented in lab_2.c and test the results */
    minMaxNorm(arr, size);
    
    /* Print updated contents of arr */
    for(i=0; i<size; i++)
    {
        printf("%.2f ", arr[i]);
    }
    return 0;
}