/* Chapter 12 programming projects */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

//Definitions
//Q1
#define MAX_CHAR1 20
//Q2
#define MAX_REMIND2 50 // maximum number of reminders.
#define MSG_LEN2 60 // max length of reminder message.
//Q3
#define DIAMOND 0
#define CLUB 1
#define HEART 2
#define SPADE 3
#define NUM_RANKS 13
#define NUM_SUITS 4
//Q7
#define NUM_PLANETS 9

//Prototypes
//Q1
void Question1(void);
//Q2
void Question2(void);
int read_line2 (char str[], int n);
//Q3
void Question3(void);
//Q4
void Question4(int argc, char *argv[]);
//Q5
void Question5(int argc, char *argv[]);
//Q6
void Question6(int argc, char *argv[]);
//Q7
void Question7(void);

int main(int argc, char *argv[])
{
    int argi = *argv[1] - 48;
    switch (argi)
    {
    case 1:
        printf("Q1\n");
        Question1();

        break;
    
    case 2:
        printf("Q2\n");
        Question2();

    case 3:
        printf("Q3\n");
        Question3();
    
    case 4:
        printf("Q4\n");
        Question4(argc, argv);

    case 5:
        printf("Q5\n");
        Question5(argc, argv);

    case 6:        
        printf("Q6\n");
        Question6(argc, argv);

    case 7:
        printf("Q7\n");
        Question7();

    default:
        break;
    }

    return 0;
}

void Question1(void)
{
    char str[MAX_CHAR1 + 1], ch, *str_p = str, smallest_word[MAX_CHAR1 + 1], largest_word[MAX_CHAR1 + 1]; int str_count = 0;
    for(;;)
    {
        while ((ch = getchar()) != '\n')
        {
            *str_p++ = ch;
        }
        *str_p = 0;

        if (str_count == 0) {strcpy(smallest_word, str); strcpy(largest_word, str); str_count++;}
        else
        { 
            if (strcmp(smallest_word, str) > 0) strcpy(smallest_word, str);
            if (strcmp(largest_word, str) < 0) strcpy(largest_word, str);
        }
        str_p = str;
        
        if (strlen(str) == 4) {break;}
    }
    printf("Smallest word: %s\nLargest word: %s\n", smallest_word, largest_word);
}

void Question2(void)
{
    char reminders [MAX_REMIND2][MSG_LEN2 + 3], day_str [3], msg_str [MSG_LEN2 + 1];
    int day, i, j, num_remind = 0;
    for (;;) 
    {
        if (num_remind == MAX_REMIND2) {printf("-- No space left --"); break;}

        printf ("Enter day and reminder: ");
        scanf ("%2d", &day);
        if (day == 0) break;
        else if (day < 0 || day > 31) continue;
        sprintf (day_str, "%2d", day);
        read_line2(msg_str, MSG_LEN2);

        for (i = 0; i < num_remind; ++i) if (strcmp(day_str, reminders[i]) < 0) break; // find the index to put reminder
        for (j = num_remind; j > i; --j) strcpy(reminders[j], reminders[j-1]); // push all other reminder into back to create space for present reminder

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; ++i) printf(" %s\n", reminders[i]);

}

int read_line2 (char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') if (i < n) str[i++] = ch;
    str[i] = '\0';
    return i;        
}

void Question3(void)
{
    
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char *rank_code[] = {"Two","Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    const char *suit_code[] = {"clubs", "diamonds", "hearts", "spades"};

    srand((unsigned) time(NULL));

    printf("Enter a number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Yout hand:\n");
    while(num_cards > 0)
    {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit][rank])
        {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%s of %s\n", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");
}

void Question4(int argc, char *argv[])
{
    for (int i = argc - 1; i >= 2; --i) printf("%s ", argv[i]);
    printf("\n");
}

void Question5(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 2; i < argc; ++i) sum += atoi(argv[i]);
    printf("Total: %d\n", sum);
}

void Question6(int argc, char *argv[])
{
    char *planets[] = {"MERCURY", "VENUS", "EARTH", "MARS", "JUPITER", "SATURN", "URANUS", "NAPTUNE", "PLUTO"}, ch[MAX_CHAR1], *ch_p, *ch_p2;
    int i, j;
    for (i = 2; i < argc; ++i) 
    {
        for (ch_p = argv[i], ch_p2 = ch; *ch_p != 0; *ch_p2++ = toupper(*ch_p), ++ch_p);
        for (j = 0; j < NUM_PLANETS; ++j)
        {
            if (strcmp(ch, planets[j]) == 0) {printf("%s is planet %d\n", argv[i], j + 1); break;}
        }
        if (j == NUM_PLANETS) printf("%s is not a planet\n", argv[i]);
    }
}

void Question7(void)
{
    char *atenth[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *afirst[] = {"", "-One", "-Two", "-Three", "-Four", "-Five", "-Six", "-Seven", "-Eight", "-Nine"};
    char *ateenth[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    int tenth, first = 0;
    printf("Enter a two digit number: ");
    scanf("%1d%1d", &tenth, &first);
    printf("You Entered the Number ");
    if (tenth == 1) {printf("%s", ateenth[first]);}
    else if (tenth > 1) {printf("%s%s", atenth[tenth], afirst[first]);}
    else {printf("Wrong number");}
    printf("\n");
}

