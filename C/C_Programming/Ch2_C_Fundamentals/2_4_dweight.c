#include <stdio.h>

/* Computes the dimensional weight of 12" X 10" X 8" Box */
int main (void)
{
    int height, width, length, volume, weight;
    height = 8;
    width = 10;
    length = 12;
    volume = height * width * length;
    weight = (volume + 165) / 166;

    printf("Dimensions (inchies): %dx%dx%d\n", length, width, height);
    printf("Volume (Cubic inchies): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);
    return 0;
}