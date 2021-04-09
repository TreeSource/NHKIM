/* Chapter 9 programming projects */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

//Question1.
void selsort(int a1[], int n1) 
{
    int lrgesti = 0, temp;

    if (n1 >= 1)
    {
        for (int i = 0; i < n1; ++i)
        {
            if (a1[lrgesti] < a1[i]) lrgesti = i;
        }
        temp = a1[n1 - 1];
        a1[n1 - 1] = a1[lrgesti];
        a1[lrgesti] = temp;
        selsort(a1, (n1 - 1));
    }
    else {return;}
}
//Question2.
void printincome(float inp2)
{
    printf("Amount of tax of $%.2f is: ", inp2);
    if (inp2 > 7000.00f) printf("$%.2f\n", 230.00f + ((inp2 - 7000.00f) * .06f));
    else if (inp2 > 5250.00f) printf("$%.2f\n", 142.50f + ((inp2 - 5250.00f)* .05f));
    else if (inp2 > 3750.00f) printf("$%.2f\n", 82.50f + ((inp2 - 3750.00f) * 0.04f));
    else if (inp2 > 2250.00f) printf("$%.2f\n", 37.50f + ((inp2 - 2250.00f) * 0.03f));
    else if (inp2 > 750.00f) printf("$%.2f\n", 7.50f + ((inp2 - 750.00f) * 0.02f));
    else printf("$%.2f\n", inp2 * 0.01f);
}

//Question3.
void generate_random_walk(char walk[10][10])
{
    int size5 = (int) sizeof(walk[0]) / sizeof(walk[0][0]);
    for (int i = 0; i < size5; ++i)
    {
        for (int j = 0; j < size5; ++j)
        {
            walk[i][j] = '.';
        }
    }
}
void print_array(char walk[10][10])
{
    int size5 = (int) sizeof(walk[0]) / sizeof(walk[0][0]);
    for (int i = 0; i < size5; ++i)
    {
        for (int j = 0; j < size5; ++j)
        {
            printf(" %c", walk[i][j]);
        }
        printf("\n");
    }
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

//Question4.
void read_word(int counts[26])
{
    char cip4;
    while(1)
    {
        scanf("%c", &cip4);
        if (cip4 == '\n') { break; }
        else if (cip4 >= 'a' && cip4 <= 'z') {cip4 -= ('a' - 'A');}
        counts[cip4 - 'A']++;
    }
}
bool equal_array(int counts1[26], int counts2[26])
{
    for (int i = 0; i < 26; ++i)
    {
        if (counts1[i] != counts2[i])
        {
            return false;
        }
    }
    return true;
}

//Qeustion5.
void create_magic_square(long n, long magic_square[n][n])
{
    long size5 = n * n, curn5 = 1, curr5 = 0, curc5;
    curc5 = n / 2;
    for (long l = 0; l < n; ++l)
    {
        for (long m = 0; m < n; ++m)
        {
            magic_square[l][m] = 0;
        }
    }
     while (curn5 <= size5)
    {
        if (magic_square[curr5][curc5] == 0)
        {
            magic_square[curr5--][curc5++] = curn5++;
            if (curr5 < 0) {curr5 = n - 1;}
            if (curc5 > n - 1) {curc5 = 0;}
        } else {
            curc5--;
            curr5++;
            if (curc5 < 0) {curc5 = n - 1;}
            if (curr5 > n - 1) {curr5 = 0;}
            curr5++;
            if (curr5 > n - 1) {curr5 = 0;}
        }
    }
}
void print_magic_square(long n, long magic_square[n][n])
{
    for (long l = 0; l < n; ++l)
    {
        for (long m = 0; m < n; ++m)
        {
            printf("%ld\t", magic_square[l][m]);
        }
        printf("\n");
    }
}

//Question7.
long power(long x, long num)
{
    long rtn;
    if (num <= 1)
    {
        return x;
    }
    else
    {
        if (num % 2 == 1)
        {
        rtn = x * power(x, num - 1);
        }
        else
        {
        rtn = power(x, num / 2) * power(x, num / 2);
        }
        return rtn;
    }
}

//Question6.
long compute_pol(long x)
{
    return 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6;
}

//Question8.
int roll_dice(void)
{
    int rtn1 = rand() % 6 + 1, rtn2 = rand() % 6 + 1;
    return rtn1 + rtn2;
}
bool play_game(void)
{
    char cin8;
    printf("Play again? ");
    scanf("%c", &cin8);
    if (cin8 != 'y' && cin8 != 'Y')
    {
        return false;
    }
    return true;
}

int main(void)
{
    srand((unsigned) time(NULL));

    //Question1
    int a1[N], i1;

    printf("Enter %d numbers to be sorted: ", N);
    for (i1 = 0; i1 < N; ++i1) scanf("%d", &a1[i1]);

    selsort(a1, N);

    printf("In sorted order: ");
    for (i1 = 0; i1 < N; ++i1) printf("%d ", a1[i1]);
    printf("\n");

    //Question 2.
    float inp2;
    printf("Enter the amount of taxable income: ");
    scanf("%f", &inp2);
    printincome(inp2);

    //Question 3.
    int dir3 = 0, row3 = 0, col3 = 0;
    char char3 = 'A', walk3[N][N];
    generate_random_walk(walk3);
    walk3[row3][col3] = char3++;
    for (; (int) char3 < 91;)
    {
        if (
            (min(row3 + 1, 10) == 10 &&
            max(row3 - 1, 0) == 0 &&
            walk3[row3][col3 + 1] != '.' &&
            walk3[row3 - 1][col3] != '.')||
            (min(row3 + 1, 10) == 10 &&
            min(row3 + 1, 0) == 0 &&
            walk3[row3][col3 - 1] != '.' &&
            walk3[row3 - 1][col3] != '.')||
            (max(row3 - 1, 0) == 0 &&
            min(row3 + 1, 10) == 10 &&
            walk3[row3][col3 - 1] != '.' &&
            walk3[row3 + 1][col3] != '.')||
            (max(row3 - 1, 0) == 0 &&
            max(row3 - 1, 0) == 0 &&
            walk3[row3][col3 + 1] != '.' &&
            walk3[row3 + 1][col3] != '.')||
            (max(row3 - 1, 0) == 0 &&
            walk3[row3][col3 - 1] != '.' &&
            walk3[row3 + 1][col3] != '.' &&
            walk3[row3][col3 + 1] != '.')||
            (max(col3 - 1, 0) == 0 &&
            walk3[row3][col3 + 1] != '.' &&
            walk3[row3 + 1][col3] != '.' &&
            walk3[row3 - 1][col3] != '.')||
            (min(col3 + 1, 10) == 10 &&
            walk3[row3][col3 - 1] != '.' &&
            walk3[row3 + 1][col3] != '.' &&
            walk3[row3 - 1][col3] != '.')||
            (min(row3 + 1, 10) == 10 &&
            walk3[row3][col3 - 1] != '.' &&
            walk3[row3 - 1][col3] != '.' &&
            walk3[row3][col3 + 1] != '.')||
            (walk3[row3][col3 - 1] != '.' &&
            walk3[row3][col3 + 1] != '.' &&
            walk3[row3 - 1][col3] != '.' &&
            walk3[row3 + 1][col3] != '.')
            )
        {
            break;
        }
        dir3 = rand() % 4;
        switch (dir3)
        {
        case 0:
            row3 = row3 - 1;
            break;
        case 1:
            col3 = col3 + 1;
            break;
        case 2:
            row3 = row3 + 1;
            break;
        default:
            col3 = col3 - 1;
            break;
        }
        if (row3 > -1 && row3 < 10 && col3 > -1 && col3 < 10 && walk3[row3][col3] == '.')
        {
            walk3[row3][col3] = char3++;
        }
        else if (dir3 == 0)
        {
            row3++;
        }
        else if (dir3 == 1)
        {
            col3--;
        }
        else if (dir3 == 2)
        {
            row3--;
        }
        else if (dir3 == 3)
        {
            col3++;
        }
    }
    print_array(walk3);


    //Question 4.
    int fip4[26] = {0}, sip4[26] = {0};
    printf("Enter first word: ");
    read_word(fip4);
    printf("Enter second word: ");
    read_word(sip4);
    if (equal_array(fip4, sip4))
    {
        printf("The words are anagrams\n");
    } else {
        printf("The words are not anagrams\n");
    }


    //Question 5.
    long lip5;
    printf("This program creates a magic square of a specified size5.\nThe size5 must be an odd number between 1 to 99.\nEnter size5 of magic square: ");
    scanf("%ld", &lip5);
    long magic_square[lip5][lip5];
    create_magic_square(lip5, magic_square);
    print_magic_square(lip5, magic_square);


    //Question 6. with Question 7.
    long lip6;
    printf("Enter an x value: ");
    scanf("%ld", &lip6);
    printf("The answer is: %ld\n", compute_pol(lip6));


    //Question 8.
    int pnt8 = 0, win8 = 0, los8 = 0, dice;
    char som;
    do
    {
        for (;;)
        {
            dice = roll_dice();
            if (pnt8 == 0)
            {
                printf("You rolled: %d\n", dice);
                if (dice == 7 || dice == 11)
                {
                    win8++;
                    printf("You win!\n");
                    scanf("%c", &som);
                    break;
                }
                else if (dice == 2 || dice == 3 || dice == 11)
                {
                    los8++;
                    printf("You lose.\n");
                    scanf("%c", &som);
                    break;
                }
                else pnt8 = dice; printf("Your point is: %d\n", pnt8); scanf("%c", &som);
            }
            else
            {
                printf("You rolled: %d\n", dice);
                if (dice == pnt8)
                {
                    win8++;
                    printf("You win!\n");
                    scanf("%c", &som);
                    break;
                }
                else if (dice == 7)
                {
                    los8++;
                    printf("You lose.\n");
                    scanf("%c", &som);
                    break;
                }
                scanf("%c", &som);
            }
            
        }
        if(play_game()) pnt8 = 0;
        else break;
    } while (true);
    printf("Wins: %d\tLose: %d\n", win8, los8);
    

    return 0;
}