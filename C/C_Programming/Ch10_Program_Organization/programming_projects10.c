/* Chapter 10 programming projects */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/* definitions */
/*
//Question 2.
#define NUM_RANKS2 13
#define NUM_SUITS2 4
#define NUM_CARDS2 5
*/
//Question 3.
#define NUM_RANKS3 13
#define NUM_SUITS3 4
#define NUM_CARDS3 5
#define CARD_PROPERTY 2
#define RANK3 0
#define SUIT3 1

/* external variables */
/*
// Question 1.
int braces1[3];

// Question 2.
bool straight2, flush2, four2, three2;
int pairs2; 
*/
// Question 3.
bool straight3, flush3, four3, three3, royal_flush4, ace_low5;
int pairs3;

/* prototypes */
/*
// Question 1.
void read_braces1 (void);
void check_braces1 (void);

// Question 2.
void read_cards2 (int [NUM_RANKS2], int [NUM_SUITS2]);
void analyze_hand2 (int [NUM_RANKS2], int [NUM_SUITS2]);
void print_result2 (void);
*/
// Question 3.
void read_card3 (int [NUM_CARDS3][CARD_PROPERTY]);
void analyze_hand3 (int [NUM_CARDS3][CARD_PROPERTY]);
void print_result3 (void);
void quicksort3(int a[], int low, int high);
int split3(int a[], int low, int high);

/* main function: call the other functions to achieve the questions. */
int main (void)
{
/*
    //Question 1.
    read_braces1();
    check_braces1();

    //Question 2.
    int num_in_ranks2 [NUM_RANKS2], num_in_suit2 [NUM_SUITS2];
    for(;;)
    {
        read_cards2(num_in_ranks2, num_in_suit2);
        analyze_hand2(num_in_ranks2, num_in_suit2);
        print_result2();
    }
*/
    //Question 3.
    int hand[NUM_CARDS3][CARD_PROPERTY];
    for (;;)
    {
        read_card3(hand);
        analyze_hand3(hand);
        print_result3();
    }

    return 0;
}

/* functions */

/*
// Question 1.

void read_braces1 (void)
{
    for (int i = 0; i < 3; ++i)
    {
        braces1[i] = 0;
    }
    char cin1;
    printf("Enter parentheses and/or braces: ");
    do
    {
        cin1 = getchar();
        if (cin1 == '(') ++braces1[0];
        else if (cin1 == '{') ++braces1[1];
        else if (cin1 == '[') ++braces1[2];
        else if (cin1 == ')') --braces1[0];
        else if (cin1 == '}') --braces1[1];
        else if (cin1 == ']') --braces1[2];
    } while (cin1 != '\n');
}

void check_braces1 (void)
{
    for (int i = 0; i < 3; ++i)
    {
        if (braces1[i] != 0) {printf("Parentheses/braces are not nested properly.\n"); return;}
    }
    printf("Parentheses/braces are nested properly.\n");
}

// Question 2.
void read_cards2 (int num_in_ranks2[NUM_RANKS2], int num_in_suits2[NUM_SUITS2])
{
    bool card_exists2[NUM_RANKS2][NUM_SUITS2];
    char ch2, rank_ch2, suit_ch2;
    int rank2, suit2;
    bool bad_card2;
    int card_read2 = 0;

    for (rank2 = 0; rank2 < NUM_RANKS2; ++rank2)
    {
        num_in_ranks2[rank2] = 0;
        for (suit2 = 0; suit2 < NUM_SUITS2; ++suit2) card_exists2[rank2][suit2] = false;
    }

    for (suit2 = 0; suit2 < NUM_SUITS2; ++suit2) num_in_suits2[suit2] = 0;
    
    while (card_read2 < NUM_CARDS2)
    {
        bad_card2 = false;

        printf("Enter a card: ");

        rank_ch2 = getchar();
        switch (rank_ch2)
        {
        case '0': exit(EXIT_SUCCESS);
        case '2': rank2 = 0; break;
        case '3': rank2 = 1; break;
        case '4': rank2 = 2; break;
        case '5': rank2 = 3; break;
        case '6': rank2 = 4; break;
        case '7': rank2 = 5; break;
        case '8': rank2 = 6; break;
        case '9': rank2 = 7; break;
        case 't': case 'T': rank2 = 8; break;
        case 'j': case 'J': rank2 = 9; break;
        case 'q': case 'Q': rank2 = 10; break;
        case 'k': case 'K': rank2 = 11; break;
        case 'a': case 'A': rank2 = 12; break;
        default: bad_card2 = true; break;
        }
        suit_ch2 = getchar();
        switch (suit_ch2)
        {
        case '0': exit(EXIT_SUCCESS);
        case 'c': case 'C': suit2 = 0; break;
        case 'd': case 'D': suit2 = 1; break;
        case 'h': case 'H': suit2 = 2; break;
        case 's': case 'S': suit2 = 3; break;
        default: bad_card2 = true; break;
        }

        while ((ch2 = getchar()) != '\n')
        {
            if (ch2 != ' ') bad_card2 = true;
        }

        if (bad_card2 == true)
        {
            printf("Bad card; ignored.\n");
        } else if (card_exists2[rank2][suit2]) printf("Duplicate card; ignored.\n");
        else
        {
            ++num_in_ranks2[rank2];
            ++num_in_suits2[suit2];
            ++card_read2;
            card_exists2[rank2][suit2] = true;
        }
    }
}
void analyze_hand2 (int num_in_ranks2[NUM_RANKS2], int num_in_suits2[NUM_SUITS2])
{
    int num_consec2 = 0;
    int rank2, suit2;

    straight2 = false;
    flush2 = false;
    four2 = false;
    three2 = false;
    pairs2 = 0;

    for (suit2 = 0; suit2 < NUM_SUITS2; ++suit2) if (num_in_suits2[suit2] == NUM_CARDS2) flush2 = true;

    rank2 = 0;
    while (num_in_ranks2[rank2] == 0) ++rank2;
    for (; rank2 < NUM_RANKS2 && num_in_ranks2[rank2] > 0; ++rank2) ++num_consec2;
    if (num_consec2 == NUM_CARDS2) straight2 = true; return;


    for (rank2 = 0; rank2 < NUM_RANKS2; ++rank2)
    {
        if (num_in_ranks2[rank2] == 4) four2 = true;
        if (num_in_ranks2[rank2] == 3) three2 = true;
        if (num_in_ranks2[rank2] == 2) ++pairs2;
    }
}
void print_result2 (void)
{
    if (straight2 && flush2) printf("Straight flush");
    else if (four2)  printf("Four of a kind");
    else if (three2 && pairs2 == 1)  printf("Full house");
    else if (flush2)  printf("Flush");
    else if (straight2)  printf("Straight");
    else if (three2) printf("Three of a kind");
    else if (pairs2 == 2)  printf("Two pairs");
    else if (pairs2 == 1)  printf("Pair");
    else printf("High card");

    printf("\n\n");
}
*/

// Question 3.
void read_card3 (int hand[NUM_CARDS3][CARD_PROPERTY])
{
    char ch3, rank_ch3, suit_ch3;
    int rank3, suit3;
    bool bad_card3, duplicated;
    int card_read3 = 0;

    for (int i = 0; i < NUM_CARDS3; ++i)
    {
        for (int j = 0; j < CARD_PROPERTY; ++j)
        {
            hand[i][j] = 0;
        }
    }

    while (card_read3 < NUM_CARDS3)
    {
        bad_card3 = false;
        duplicated = false;

        printf("Enter a card: ");
        rank_ch3 = getchar();
        switch (rank_ch3)
        {   
            case '0': exit(EXIT_SUCCESS);
            case '2': rank3 = 0; break;
            case '3': rank3 = 1; break;
            case '4': rank3 = 2; break;
            case '5': rank3 = 3; break;
            case '6': rank3 = 4; break;
            case '7': rank3 = 5; break;
            case '8': rank3 = 6; break;
            case '9': rank3 = 7; break;
            case 'T': case 't': rank3 = 8; break;
            case 'J': case 'j': rank3 = 9; break;
            case 'Q': case 'q': rank3 = 10; break;
            case 'K': case 'k': rank3 = 11; break;
            case 'A': case 'a': rank3 = 12; break;

        default: bad_card3 = true; break;
        }
        suit_ch3 = getchar();
        switch (suit_ch3)
        {
            case '0': exit(EXIT_SUCCESS);
            case 'c': case 'C': suit3 = 0; break;
            case 'd': case 'D': suit3 = 1; break;
            case 'h': case 'H': suit3 = 2; break;
            case 's': case 'S': suit3 = 3; break;
            default: bad_card3 = true; break;
        }

        while ((ch3 = getchar()) != '\n')
        {
            if (ch3 != ' ') bad_card3 = false;
        }

        for (int i = 0; i < card_read3; ++i)
        {
            if (hand[i][RANK3] == rank3 && hand[i][SUIT3] == suit3) duplicated = true;
        }

        if (bad_card3) printf("Bad card; ignored.\n");
        else if (duplicated) printf("Duplicate card; ignored.\n");
        else 
        {
            hand[card_read3][RANK3] = rank3;
            hand[card_read3++][SUIT3] = suit3;
        }
    }
}

void analyze_hand3 (int hand[NUM_CARDS3][CARD_PROPERTY])
{
    int cur3, count3 = 0, straight_array3[NUM_CARDS3];

    royal_flush4 = false;
    ace_low5 = false;
    straight3 = true;
    flush3 = true;
    four3 = false;
    three3 = false;
    pairs3 = 0;

    // flush
    for (int i = 0; i < NUM_CARDS3 - 1; ++i)
    {
        if (hand[i][1] != hand[i + 1][1]) flush3 = false; break;
    }

    // pairs
    for (int i = 0; i < NUM_CARDS3; ++i)
    {
        for (int j = i + 1; j < NUM_CARDS3; ++j)
        {
            if (hand[i][0] == hand[j][0]) ++pairs3;
        }
    }

    // four or three
    for (int i = 0; i < NUM_CARDS3; ++i)
    {
        cur3 = hand[i][0];
        for (int j = 0; j < NUM_CARDS3; ++j)
        {
            if (hand[i][0] == cur3) ++count3;
        }
        if (count3 == 4) {four3 = true; break;}
        else if (count3 == 3) {three3 = true; break;}
    }

    // straight
    for (int i = 0; i < NUM_CARDS3; ++i) straight_array3[i] = hand[i][0];
    quicksort3(straight_array3, 0, NUM_CARDS3 - 1);
    for (int i = 0; i < NUM_CARDS3 - 1; ++i)
    {
        if ((straight_array3[i] + 1) != straight_array3[i + 1]) { straight3 = false; break;}
        else if (i == NUM_CARDS3 - 1 && straight_array3[0] == 0 && straight_array3[i + 1] == 12) ace_low5 = true; break;
    }

    if (straight3 && flush3)
    {
        if (straight_array3[0] == 8) royal_flush4 = true;
    }

}

void print_result3 (void)
{
    if (straight3 && flush3) printf("Straight flush");
    else if (four3)  printf("Four of a kind");
    else if (three3 && pairs3 == 1)  printf("Full house");
    else if (flush3)  printf("Flush");
    else if (straight3)  printf("Straight");
    else if (three3) printf("Three of a kind");
    else if (pairs3 == 2)  printf("Two pairs");
    else if (pairs3 == 1)  printf("Pair");
    else printf("High card");

    printf("\n\n");
}


void quicksort3(int a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split3(a, low, high);
    quicksort3(a, low, middle - 1);
    quicksort3(a, middle + 1, high);
}

int split3(int a[], int low, int high)
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
