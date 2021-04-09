/* Chapter 8 programming projects */
#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>
#include <time.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00
#define MAX_STRINGS 256

int min(int, int);
int max(int, int);

int main (void)
{
    srand((unsigned) time(NULL));

    //Question 1.

    int digit_seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    for (; n > 0; n /= 10) {
        digit = n % 10;
        digit_seen[digit] += 1;
    }

    printf("Q2) The repeated number(s) are:");

    for (int i = 0; i < (sizeof(digit_seen) / sizeof(digit_seen[0])); ++i)
    {
        if (digit_seen[i] > 1)
        {
            printf("\t%d", i);
        }
    }

    //Question 2.
    printf("Q3) Digit:\t");
    for (int i = 0; i < (sizeof(digit_seen) / sizeof(digit_seen[0])); ++i) {printf("\t%d", i);}
    printf("\nQ3) Occurrences:\t");
    for (int i = 0; i < (sizeof(digit_seen) / sizeof(digit_seen[0])); ++i) {printf("\t%d", digit_seen[i]);}
    printf("\n");

    //Question 4.
    int a[10], i;
    printf("Enter %d numbers: ", sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) scanf("%d", &a[i]);
    printf("In inverse order: ");
    for (int i = sizeof(a) / sizeof(a[0]); i >0; --i) printf("%d", a[i - 1]);
    printf("\n");

    //Question 5.
    int i, low_rate, num_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; ++i)
    {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; ++year)
    {
        printf("%3d       ", year);
        for (i = 0; i < NUM_RATES; ++i)
        {
            for (int j = 0; j < 12; ++j)
            {
                value[i] += (low_rate + i) / 100.00 * value [i];
            }
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }


    //Question 6.
    char inp6[MAX_STRINGS] = "";
    printf("Enter message: ");
    scanf("%[^\n]s", inp6);
    for (int inpl = 0; inpl < MAX_STRINGS; inpl++)
    {
        if (inp6[inpl] == 'A' || inp6[inpl] == 'a')
        {
            printf("4");
        }
        else if (inp6[inpl] == 'B' || inp6[inpl] == 'b')
        {
            printf("8");
        }
        else if (inp6[inpl] == 'E' || inp6[inpl] == 'e')
        {
            printf("3");
        }
        else if (inp6[inpl] == 'I' || inp6[inpl] == 'i')
        {
            printf("1");
        }
        else if (inp6[inpl] == 'O' || inp6[inpl] == 'o')
        {
            printf("0");
        }
        else if (inp6[inpl] == 'S' || inp6[inpl] == 's')
        {
            printf("5");
        }
        else 
        {
            if ((int) inp6[inpl] > 90)
            {
                printf("%c", inp6[inpl] - 32);
            }
            else printf("%c", inp6[inpl]);
        }
    }
    printf("!!!!!!!!!!\n");


    //Question 7.
    int inp7[5][5], row = 0, col = 0;
    for (int j = 0; j < 5; ++j)
    {
        printf("Enter row %d: ", j + 1);
        for (int i = 0; i < 5; ++i)
        {
            scanf("%d", &inp7[j][i]);
        }
    }
    printf("Row totals: ");
    for (int j = 0; j < 5; ++j)
    {
        row = 0;
        for (int i = 0; i < 5; ++i)
        {
            row += inp7[j][i];
        }
        printf(" %d", row);
    }
    printf("\nColumn totals: ");
    for (int i = 0; i < 5; ++i)
    {
        col = 0;
        for (int j = 0; j < 5; ++j)
        {
            col += inp7[j][i];
        }
        printf(" %d", col);
    }
    printf("\n");

    //Question 8.
        int inp8[5][5], row = 0, col = 0;
    for (int j = 0; j < 5; ++j)
    {
        printf("Enter student No.%d's marks: ", j + 1);
        for (int i = 0; i < 5; ++i)
        {
            scanf("%d", &inp8[j][i]);
        }
    }
    printf("Each student's total: \n\n");
    for (int j = 0; j < 5; ++j)
    {
        row = 0;
        for (int i = 0; i < 5; ++i)
        {
            row += inp8[j][i];
        }
        printf("student No.%d: %d\n", j + 1, row / 5);
    }
    printf("\nQuiz's averages: \n\n");
    for (int i = 0; i < 5; ++i)
    {
        col = 0;
        for (int j = 0; j < 5; ++j)
        {
            col += inp8[j][i];
        }
        printf("Quiz No.%d: %d\n", i + 1, col / 5);
    }

    //Question 9.
    int dir9 = 0, crow9 = 0, ccol9 = 0;
    char chr9 = 'A';
    char dotground9[10][10];
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            dotground9[i][j] = '.';
        }
    }
    dotground9[crow9][ccol9] = chr9++;
    for (; (int) chr9 < 91;)
    {
        if (
            (min(crow9 + 1, 10) == 10 &&
            max(crow9 - 1, 0) == 0 &&
            dotground9[crow9][ccol9 + 1] != '.' &&
            dotground9[crow9 - 1][ccol9] != '.')||
            (min(crow9 + 1, 10) == 10 &&
            min(crow9 + 1, 0) == 0 &&
            dotground9[crow9][ccol9 - 1] != '.' &&
            dotground9[crow9 - 1][ccol9] != '.')||
            (max(crow9 - 1, 0) == 0 &&
            min(crow9 + 1, 10) == 10 &&
            dotground9[crow9][ccol9 - 1] != '.' &&
            dotground9[crow9 + 1][ccol9] != '.')||
            (max(crow9 - 1, 0) == 0 &&
            max(crow9 - 1, 0) == 0 &&
            dotground9[crow9][ccol9 + 1] != '.' &&
            dotground9[crow9 + 1][ccol9] != '.')||
            (max(crow9 - 1, 0) == 0 &&
            dotground9[crow9][ccol9 - 1] != '.' &&
            dotground9[crow9 + 1][ccol9] != '.' &&
            dotground9[crow9][ccol9 + 1] != '.')||
            (max(ccol9 - 1, 0) == 0 &&
            dotground9[crow9][ccol9 + 1] != '.' &&
            dotground9[crow9 + 1][ccol9] != '.' &&
            dotground9[crow9 - 1][ccol9] != '.')||
            (min(ccol9 + 1, 10) == 10 &&
            dotground9[crow9][ccol9 - 1] != '.' &&
            dotground9[crow9 + 1][ccol9] != '.' &&
            dotground9[crow9 - 1][ccol9] != '.')||
            (min(crow9 + 1, 10) == 10 &&
            dotground9[crow9][ccol9 - 1] != '.' &&
            dotground9[crow9 - 1][ccol9] != '.' &&
            dotground9[crow9][ccol9 + 1] != '.')||
            (dotground9[crow9][ccol9 - 1] != '.' &&
            dotground9[crow9][ccol9 + 1] != '.' &&
            dotground9[crow9 - 1][ccol9] != '.' &&
            dotground9[crow9 + 1][ccol9] != '.')
            )
        {
            break;
        }
        dir9 = rand() % 4;
        switch (dir9)
        {
        case 0:
            crow9 = crow9 - 1;
            break;
        case 1:
            ccol9 = ccol9 + 1;
            break;
        case 2:
            crow9 = crow9 + 1;
            break;
        default:
            ccol9 = ccol9 - 1;
            break;
        }
        if (crow9 > -1 && crow9 < 10 && ccol9 > -1 && ccol9 < 10 && dotground9[crow9][ccol9] == '.')
        {
            dotground9[crow9][ccol9] = chr9++;
        }
        else if (dir9 == 0)
        {
            crow9++;
        }
        else if (dir9 == 1)
        {
            ccol9--;
        }
        else if (dir9 == 2)
        {
            crow9--;
        }
        else if (dir9 == 3)
        {
            ccol9++;
        }
        
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf(" %c", dotground9[i][j]);
        }
        printf("\n");
    }

    //Question 14.
    char ip14[MAX_STRINGS];
    char cip14 = '\n', cop14 = '\n';
    int icur14 = 0, ocur14 = 0;
    printf("Enter a sentence: ");
    for (int i = 0; i < MAX_STRINGS; ++i)
    {
        scanf("%c", &cip14);
        if (cip14 != '.' && cip14 != '?' && cip14 != '!')
        {
            ++icur14;
            ip14[i] = cip14;
        } else {
            ip14[i] = cip14;
            break;
        }
    }
    ocur14 = icur14;
    for (int i = icur14; i >= 0; --i)
    {
        if (ip14[i] == ' ' || i == 0)
        {
            if (i == 0)
            {
                printf(" ");
            }
            for (int j = i; j < ocur14; ++j)
            {
                printf("%c", ip14[j]);
            }
            
            ocur14 = i;
        } else if (ip14[i] == '!' || ip14[i] == '?' || ip14[i] == '.')
        {
            cop14 = ip14[i];
        }
    }
    printf("%c\n", cop14);

    //Question 15.
    char ip15[MAX_STRINGS], cip15 = '\n';
    int iip15 = 0, cur15 = 0;
    printf("Enter message to be encrypted: ");
    for (int i = 0; i < MAX_STRINGS; ++i)
    {
        scanf("%c", &cip15);
        if (cip15 != '.'&&cip15 != '!'&&cip15 != '?')
        {
            ip15[i] = cip15;
            ++cur15;
        } 
        else {
            ip15[i] = cip15;
            ++cur15;
            break;
        }
    }
    printf("Enter shift amount (1-25): ");
    scanf("%d", &iip15);
    printf("Encrypted message: ");
    for (int i = 0; i < cur15; ++i)
    {
        if ((ip15[i] >= 'A' && ip15[i] <= 'Z')||(ip15[i] >= 'a' && ip15[i] <= 'z'))
        {
            if (ip15[i] < 'a')
            {
                printf("%c", (((ip15[i] - 'A') + iip15) % 26 + 'A'));
            }
            else {
                printf("%c", (((ip15[i] - 'a') + iip15) % 26 + 'a'));
            }
        } else {
            printf("%c", ip15[i]);
        }
    }
    printf("\n");


    
    //Question 16.
    int ip16[26] = {0}, tf = 1;
    char cip16;
    printf("Enter first word: ");
    while(true)
    {
        scanf("%c", &cip16);
        if (cip16 == '\n') { break; }
        else if (cip16 >= 'a' && cip16 <= 'z') {cip16 -= ('a' - 'A');}
        ip16[cip16 - 'A']++;
    }
    printf("Enter second word: ");
    while(true)
    {
        scanf("%c", &cip16);
        if (cip16 == '\n') { break; }
        else if (cip16 >= 'a' && cip16 <= 'z') {cip16 -= ('a' - 'A');}
        ip16[cip16 - 'A']--;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (ip16[i] != 0)
        {
            tf = 0;
            break;
        }
    }
    if (tf)
    {
        printf("The words are anagrams\n");
    } else {
        printf("The words are not anagrams\n");
    }



    //Question 17.
    long lip17, size, curn17 = 1, curr17 = 0, curc17;
    printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 to 99.\nEnter size of magic square: ");
    scanf("%ld", &lip17);
    long msq17[lip17][lip17];
    for (long l = 0; l < lip17; ++l)
    {
        for (long m = 0; m < lip17; ++m)
        {
            msq17[l][m] = 0;
        }
    }
    size = lip17 * lip17;
    curc17 = lip17 / 2;
    while (curn17 <= size)
    {
        if (msq17[curr17][curc17] == 0)
        {
            msq17[curr17--][curc17++] = curn17++;
            if (curr17 < 0) {curr17 = lip17 - 1;}
            if (curc17 > lip17 - 1) {curc17 = 0;}
        } else {
            curc17--;
            curr17++;
            if (curc17 < 0) {curc17 = lip17 - 1;}
            if (curr17 > lip17 - 1) {curr17 = 0;}
            curr17++;
            if (curr17 > lip17 - 1) {curr17 = 0;}
        }
    }
    for (long l = 0; l < lip17; ++l)
    {
        for (long m = 0; m < lip17; ++m)
        {
            printf("%ld\t", msq17[l][m]);
        }
        printf("\n");
    }

    return 0;
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}