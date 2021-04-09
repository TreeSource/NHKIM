/* Chapter 11 programming projects */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definitions
//Q4
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define CARD_PROPERTY 2
#define RANK 0
#define SUIT 1

// Prototypes
void pay_amount (int, int *, int *, int *, int *); // Q1
void find_closest_flight (int, int *, int *); // Q2
void reduce (int, int, int *, int *); // Q3
//Q4
void read_card (int [NUM_CARDS][CARD_PROPERTY]);
void analyze_hand (int [NUM_CARDS][CARD_PROPERTY], bool *, bool *, bool *, bool *, bool *, bool *, int *);
void print_result (bool, bool, bool, bool, bool, bool, int);
void quicksort(int [], int, int);
int split(int [], int, int);

// Main function
int main (void)
{
    printf("Chapter 11 Programming Projects");

    printf("\nQuestion 1\n");
    int dollars1, twenties1, tens1, fives1, ones1;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollars1);
    pay_amount(dollars1, &twenties1, &tens1, &fives1, &ones1);
    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n",
    twenties1, tens1, fives1, ones1);

    printf("\nQuestion 2\n");
    int inph2, inpm2, dparth2, dpartm2, arrivh2, arrivm2, dpart2, arriv2, cinp;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &inph2, &inpm2);
    cinp = inph2 * 60 +  inpm2;
    find_closest_flight(cinp, &dpart2, &arriv2);
    dparth2 = dpart2 / 60; arrivh2 = arriv2 / 60;
    dpartm2 = dpart2 % 60; arrivm2 = arriv2 % 60;
    printf("Closest departure time is %d:%d, arriving time at %d:%d\n", dparth2, dpartm2, arrivh2, arrivm2);

    printf("\nQuestion 3\n");
    int num3, denom3;
    printf("Enter a fraction: ");
    scanf("%d/%d", &num3, &denom3);
    reduce (num3, denom3, &num3, &denom3);
    printf("In lowest terms: %d/%d\n", num3, denom3);
    
    printf("\nQuestion 4\n");
    bool ace_low, royal_flush, straight, flush, four, three;
    int pairs, hand[NUM_CARDS][CARD_PROPERTY];
    for (;;)
    {
        read_card(hand);
        analyze_hand(hand, &ace_low, &royal_flush, &straight, &flush, &four, &three, &pairs);
        print_result(ace_low, royal_flush, straight, flush, four, three, pairs);
    }

    return 0;
}

// Functions
void pay_amount (int dollars1, int *twenties1, int *tens1, int *fives1, int *ones1)
{
    *twenties1 = dollars1 / 20;
    *tens1 = (dollars1 % 20) / 10;
    *fives1 = ((dollars1 % 20) % 10) / 5;
    *ones1 = (((dollars1 % 20) % 10) % 5);
}

void find_closest_flight (int desired_time2, int *departure_time2, int *arrival_time2)
{
    if (desired_time2 > 1305) {*departure_time2 = 1305; *arrival_time2 = 1438;} else if (desired_time2 > 1140 || 1140 - desired_time2 < desired_time2 - 945) {*departure_time2 = 1140; *arrival_time2 = 1280;} else if (desired_time2 > 945 || 945 - desired_time2 < desired_time2 - 840) {*departure_time2 = 945; *arrival_time2 = 1075;} else if (desired_time2 > 840 || 840 - desired_time2 < desired_time2 - 767) {*departure_time2 = 840; *arrival_time2 = 968;} else if (desired_time2 > 767 || 767 - desired_time2 < desired_time2 - 679) {*departure_time2 = 767; *arrival_time2 = 900;} else if (desired_time2 > 679 || 679 - desired_time2 < desired_time2 - 583) {*departure_time2 = 679; *arrival_time2 = 811;} else if (desired_time2 > 583 || 583 - desired_time2 < desired_time2 - 480) {*departure_time2 = 583; *arrival_time2 = 712;} else {*departure_time2 = 480; *arrival_time2 = 616;}
}

void reduce (int numerator3, int denominator3, int *reduced_numerator3, int *reduced_denominator3)
{
    int m, n, gcd, temp;
    if (numerator3 == denominator3) {gcd = numerator3;} else if (numerator3 > denominator3) {m = numerator3; n = denominator3;} else {m = denominator3; n = numerator3;}
    while (n != 0) {temp = m % n; m = n; n = temp;}

    gcd = m;
    *reduced_numerator3 = numerator3 / gcd; *reduced_denominator3 = denominator3 / gcd;
}

//Q4

void read_card (int hand[NUM_CARDS][CARD_PROPERTY])
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card, duplicated;
    int card_read = 0;

    for (int i = 0; i < NUM_CARDS; ++i)
    {
        for (int j = 0; j < CARD_PROPERTY; ++j)
        {
            hand[i][j] = 0;
        }
    }

    while (card_read < NUM_CARDS)
    {
        bad_card = false;
        duplicated = false;

        printf("Enter a card: ");
        rank_ch = getchar();
        switch (rank_ch)
        {   
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 'T': case 't': rank = 8; break;
            case 'J': case 'j': rank = 9; break;
            case 'Q': case 'q': rank = 10; break;
            case 'K': case 'k': rank = 11; break;
            case 'A': case 'a': rank = 12; break;

        default: bad_card = true; break;
        }
        suit_ch = getchar();
        switch (suit_ch)
        {
            case '0': exit(EXIT_SUCCESS);
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default: bad_card = true; break;
        }

        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ') bad_card = false;
        }

        for (int i = 0; i < card_read; ++i)
        {
            if (hand[i][RANK] == rank && hand[i][SUIT] == suit) duplicated = true;
        }

        if (bad_card) printf("Bad card; ignored.\n");
        else if (duplicated) printf("Duplicate card; ignored.\n");
        else 
        {
            hand[card_read][RANK] = rank;
            hand[card_read++][SUIT] = suit;
        }
    }
}
void analyze_hand (int hand[NUM_CARDS][CARD_PROPERTY], bool *ace_low, bool *royal_flush, bool *straight, bool *flush, bool *four, bool *three, int *pairs)
{
    int cur, count = 0, straight_array[NUM_CARDS];

    *royal_flush = false;
    *ace_low = false;
    *straight = true;
    *flush = true;
    *four = false;
    *three = false;
    *pairs = 0;

    // *flush
    for (int i = 0; i < NUM_CARDS - 1; ++i)
    {
        if (hand[i][1] != hand[i + 1][1]) *flush = false; break;
    }

    // *pairs
    for (int i = 0; i < NUM_CARDS; ++i)
    {
        for (int j = i + 1; j < NUM_CARDS; ++j)
        {
            if (hand[i][0] == hand[j][0]) ++*pairs;
        }
    }

    // *four or **three
    for (int i = 0; i < NUM_CARDS; ++i)
    {
        cur = hand[i][0];
        for (int j = 0; j < NUM_CARDS; ++j)
        {
            if (hand[i][0] == cur) ++count;
        }
        if (count == 4) {*four = true; break;}
        else if (count == 3) {*three = true; break;}
    }

    // *straight
    for (int i = 0; i < NUM_CARDS; ++i) straight_array[i] = hand[i][0];
    quicksort(straight_array, 0, NUM_CARDS - 1);
    for (int i = 0; i < NUM_CARDS - 1; ++i)
    {
        if ((straight_array[i] + 1) != straight_array[i + 1]) { *straight = false; break;}
        else if (i == NUM_CARDS - 1 && straight_array[0] == 0 && straight_array[i + 1] == 12) *ace_low = true; break;
    }

    if (*straight && *flush)
    {
        if (straight_array[0] == 8) *royal_flush = true;
    }

}
void print_result (bool ace_low, bool royal_flush, bool straight, bool flush, bool four, bool three, int pairs)
{
    if (ace_low) printf("Ace low");
    else if (straight && flush && royal_flush) printf("Royal straight flush");
    else if (royal_flush) printf("Royal flush");
    else if (straight && flush) printf("straight flush");
    else if (four)  printf("Four of a kind");
    else if (three && pairs == 1)  printf("Full house");
    else if (flush)  printf("Flush");
    else if (straight)  printf("Straight");
    else if (three) printf("three of a kind");
    else if (pairs == 2)  printf("Two pairs");
    else if (pairs == 1)  printf("Pair");
    else printf("High card");

    printf("\n\n");
}

void quicksort(int a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}
int split(int a[], int low, int high)
{
    int part_element = a[low];

    for (;;)
    {
        while (low < high && part_element <= a[high]) --high;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element) ++low;
        if (low >= high) break;
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}