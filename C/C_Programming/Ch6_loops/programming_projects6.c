/* Chapter 5 programming projects */
#include <stdio.h>

int gcd(int, int);
int converty(int);

int main (void)
{/*
    //Question 1.
    float max, n;
    max = 0;
    do
    {
        printf("Enter a number: ");
        scanf("%f", &n);
        if (max < n || max == 0) max = n;
    } while (n != 0);
    printf("\nThe largest number entered was %f\n", max);
   
    //Question 2.
    int one, two;
    printf("Enter two integers: ");
    scanf("%d %d", &one, &two);
    printf("Greatest common divider: %d\n", gcd(one, two));
    

    //Question 3.
    int num, denom, cd;
    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);
    cd = gcd(num, denom);
    num /= cd;
    denom /= cd;
    printf("In lowest terms: %d/%d\n", num, denom);
    
    //Question 4.
    float commission, value;
    int first;
    
    printf("Enter a value of trade: ");
    scanf("%f", &value);
    
    while (value != 0)
    {

        if (value < 2500.00f) commission = 30.00f + .017f * value;
        else if (value < 6250.00f) commission = 56.00f + .0066f * value;
        else if (value < 20000.00f) commission = 76.00f + .0034f * value;
        else if (value < 50000.00f) commission = 100.00f + .0022f * value;
        else commission = 255.00f + .0009f * value;
        if (commission < 39.00f) commission = 39.00f;

        printf("Commission: $%.2f\n", commission);

        printf("Enter a value of trade: ");
        scanf("%f", &value);
    }
    
    //Question 5.
    long i;
    int temp;
    printf("Enter a number: ");
    scanf("%ld", &i);
    printf("The reversed number: ");
    do
    {
        temp = i % 10;
        printf("%d", temp);
        i /= 10;
    } while (i != 0);
    printf("\n");
    
    //Question 6.
    long i, n, odd, square, ceven;
    printf("This program prints the even squares before entered number.\n");
    printf("Enter number of entries in table: ");
    scanf("%ld", &n);
    i = 1;
    odd = 3;
    for (square = 1; square <= n; odd += 2)
    {
        ceven = square % 2;
        if (ceven == 0) {printf("%ld\n", square);}
        ++i;
        square += odd;
    }
    
    //Question 7.
    int i1, n1, odd1, square1;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n1);
    for (odd1 = 3, i1 = 1, square1 = 1; i1 <= n1; odd1 += 2, ++i1)
    {
        printf("%10d%10d\n", i1, square1);
        square1 += odd1;
    }
    
    //Question 8.
    int stday, mnday;
    printf("Enter number of days in month: ");
    scanf("%d", &mnday);
    printf("Enter starting day of the week (1=Sun, 7=sat): ");
    scanf("%d", &stday);
    for (int i = 0; i < stday; ++i)
    {
        if ((i % 7) == 0) { printf("  \n"); }
        printf("  ");
    }
    for (int i = 1; i <= mnday; ++i)
    {
        if (((i + stday - 1) % 7) == 0) { printf("%3d\n", i); }
        else { printf("%3d", i); }   
    }
    printf("\n");
    
    //Question 9.
    float loan, interest, pay;
    int num, cur;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &pay);
    printf("Enter the number of the payments: ");
    scanf("%d", &num);

    cur = 1;
    while (num != 0)
    {
        loan = (loan * (1 + ((interest / 100) / 12))) - pay;
        printf("Balance remaining after payment #%d: %.2f\n", cur++, loan);
        --num;
    }
    
    //Question 10.
    int day, month, year, rday = 0, rmonth = 0, ryear = 21;
    for (;;)    
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &day, &year);
        if ((month + day + year) == 0) {break;}
        else
        {
            if (converty(year) > converty(ryear))
            {
                continue;
            }
            else if (converty(year) < converty(ryear))
            {
                rday = day;
                rmonth = month;
                ryear = year;
            }
            else
            {
                if (month < rmonth) {rday = day; rmonth = month; ryear = year; continue;}
                if (day < rday) {rday = day; rmonth = month; ryear = year; continue;}
            }
            
        }
    }
    printf("%.2d/%.2d/%.2d is the earliest date\n", rmonth, rday, ryear);
    
    //Question 11.
    float e = 1;
    int n, mult = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            mult *=j;
        }
        e += (1 / mult);
    }
    printf("The aproximate natural number: %.5f\n", e);
    */
    //Question 12. ---- skip
    
    return 0;
}

int gcd (int a, int b)
{
    int m, n, temp;
    if (a == b) {return a;}
    else if (a > b) {m = a; n = b;}
    else {m = b; n = a;}
    while (n != 0)
    {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

int converty(int year)
{
    if (year > 21)
    {
        year += 1900;
    }
    else 
    {
        year += 2000;
    }

    return year;
}