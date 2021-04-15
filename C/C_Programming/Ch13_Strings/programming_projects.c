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
//Q8 Ch7-PP5
void Question8(void);
int compute_scrabble_value(const char *word);
//Q9 Ch7-PP10
void Question9(void);
int compute_vowel_count (const char *sentence);
//Q10 Ch7-PP11
void Question10(void);
void reverse_name(char *name);

int main(int argc, char *argv[])
{
    int argi = atoi(argv[1]);
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

    case 8:
        printf("Q8\n");
        Question8();

    case 9:
        printf("Q9\n");
        Question9();

    case 10:
        printf("Q10\n");
        Question10();

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

void Question8(void)
{
    char scrabble[] = "AEILNORSTUDGBCMPFHVWYKJXQZ";
    printf("Scrabble value: %d\n", compute_scrabble_value(scrabble));
}

int compute_scrabble_value(const char *word)
{
    char cin; int res = 0;
    const char *ch_p;
    printf("Enter a word: ");
    while ((cin = getchar()) != '\n')
    {
        for (ch_p = word; *ch_p != 0; ++ch_p) if (*ch_p == toupper(cin)) break;
        if ((ch_p - word) < 10) res += 1;
        else if ((ch_p - word) < 12) res += 2;
        else if ((ch_p - word) < 16) res += 3;
        else if ((ch_p - word) < 21) res += 4;
        else if ((ch_p - word) < 22) res += 5;
        else if ((ch_p - word) < 24) res += 8;
        else res += 10;
    }
    return res;
}

void Question9(void)
{
    char sin[MAX_CHAR1+1];
    printf("Enter a sentence: ");
    read_line2(sin, MAX_CHAR1);
    printf("Your sentence contains %d vowels\n", compute_vowel_count(sin));
}

int compute_vowel_count(const char *sentense)
{
    const char *ch_p = sentense;
    char vowels[] = "aeiou", *ch_p2; int nvowels = 0;
    while (*ch_p++)
    {
        for (ch_p2 = vowels; *ch_p2 != 0; ++ch_p2) if (*ch_p == *ch_p2) {nvowels++; break;}
    }
    return nvowels;
}

void Question10(void)
{
    char sin[MAX_CHAR1 + 1];
    printf("Enter a first and last name: ");
    read_line2(sin, MAX_CHAR1);
    printf("%s\n", sin);
    reverse_name(sin);
    printf("%s\n", sin);
}

void reverse_name(char *name)
{
    char rname[MAX_CHAR1 + 1], *ch_p, *ch_p2;
    for (ch_p = name; *ch_p == ' '; ++ch_p);
    for (; *ch_p != ' '; ++ch_p);
    for (; *ch_p == ' '; ++ch_p);
    for (ch_p2 = rname; *ch_p != 0; *ch_p2++ = *ch_p++);
    *ch_p2++ = ','; *ch_p2++ = ' '; 
    for (ch_p = name; *ch_p == ' '; ++ch_p);
    *ch_p2++ = *ch_p;
    *ch_p2++ = '.'; *ch_p2 = 0;

    strcpy(name, rname);
}

