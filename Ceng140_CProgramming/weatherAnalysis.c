#include <stdio.h>

int main() {
    
    /* TODO: Implement here */
    float fahrenheit1, fahrenheit2, fahrenheit3, fahrenheit4, fahrenheit5;
    float celsius1, celsius2, celsius3, celsius4, celsius5;
    float total_celsius = 0;

    scanf("%f", &fahrenheit1);
    scanf("%f", &fahrenheit2);
    scanf("%f", &fahrenheit3);
    scanf("%f", &fahrenheit4);
    scanf("%f", &fahrenheit5);

    celsius1 = (fahrenheit1 - 32) / 1.8;
    celsius2 = (fahrenheit2 - 32) / 1.8;
    celsius3 = (fahrenheit3 - 32) / 1.8;
    celsius4 = (fahrenheit4 - 32) / 1.8;
    celsius5 = (fahrenheit5 - 32) / 1.8;
    
    printf("Celsius on Mon: %.2f\n", celsius1);
    printf("Celsius on Tue: %.2f\n", celsius2);
    printf("Celsius on Wed: %.2f\n", celsius3);
    printf("Celsius on Thu: %.2f\n", celsius4);
    printf("Celsius on Fri: %.2f\n", celsius5);

    total_celsius = celsius1 + celsius2 + celsius3 + celsius4 + celsius5;
    printf("Average: %.2f\n", total_celsius / 5);

    
    return 0;
}