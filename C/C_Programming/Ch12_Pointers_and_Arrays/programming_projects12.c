/* Chapter 12 programming projects */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definitions
#define MAX_STR 100

// Prototypes


// main function
int main (void)
{

    //Q1
    char inp1[MAX_STR], *p1 = inp1, cinp1;
    for (; p1 < inp1 + MAX_STR - 1; ++p1) {cinp1 = getchar(); if (cinp1 != '\n') {*p1 = cinp1;} else break;}
    for (; p1 >= inp1; --p1) printf("%c", *p1);
    printf("\n");

    //Q2
    char inp2[MAX_STR], *p2 = inp2, *p22 = inp2, cinp2;
    printf("Enter a message: ");
    while ((cinp2 = getchar()) != '\n')
    {
        if (p2 > inp2 + MAX_STR - 1) break;
        else if (cinp2 > 'A' && cinp2 < 'Z') {*p2++ = cinp2;}
        else if (cinp2 > 'a' && cinp2 < 'z') {*p2++ = ((cinp2 - 'a') + 'A');}
    }
    --p2;
    for (; p2 >= p22;) {if (*p22 == *p2) {--p2; p22++;} else break;}
    if (p2 < p22) printf("Palindrome\n"); else printf("Not a palindrome\n");

}

// Functions