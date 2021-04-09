#include <stdio.h>

/* Computes the dimensional weight of a box from input 
provided by the user */

int main (void)
{
    int height, width, length, volume, weight;
    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);
    volume = height * width * length;
    weight = (volume + 165) / 166;

    printf("Volume (Cubic inchies): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);
    
    return 0;
}