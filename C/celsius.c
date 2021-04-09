#include <stdio.h>
#define FREEZING_PT 32.0f
/* 
it is important to set this in float, not integer
because if we set this into integer, the value of 
scale factor will be 0 as integer division.
근데 이거 곱하기가 더 빠르다면, 그냥 0.125 곱하는게 
낫지 않을까? 어차피 float 이라 소수로 써야할텐데.
*/
#define SCALE_FACTOR (5.0f * 0.125f)

int main (void){float fahrenheit, celsius;printf("Enter Fahrenheit temperature: ");scanf("%f", &fahrenheit);celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;printf("Celsius equivalent: %.1f", celsius);return 0;}