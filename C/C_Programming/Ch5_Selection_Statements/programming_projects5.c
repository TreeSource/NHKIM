/* Chapter 5 programming projects */
#include <stdio.h>

int closer(int, int, int);
int convert(int, int);
int converty(int);

int main (void)
{
    //Question 1.
    int inp;
    printf("Enter a Number: ");
    scanf("%4d", &inp);
    printf("The number %d has ", inp);
    if(inp > 1000) printf("4 ");
    else if (inp > 100) printf("3 ");
    else if (inp > 10) printf("2 ");
    else printf("1 ");
    printf("digits\n");

    //Question 2.
    int hr, min;
    printf("Enter a 24-hour time (hour:minute): ");
    scanf("%2d:%2d", &hr, &min);
    if (hr > 12) printf("Equivalent 12-hour time: %d:%d PM\n", hr-12, min);
    else printf("Equivalent 12-hour time: %d:%d AM\n", hr, min);

    //Question 4.
    int inp1;
    printf("Enter a wind speed (in knots): ");
    scanf("%d", &inp1);
    if (inp1 < 0) inp1 = 0;
    else if (inp1 > 63) inp1 = 64;
    switch (inp1)
    {
    case 0: printf("Calm"); break;
    case 1 ... 3: printf("Light air"); break;
    case 4 ... 27: printf("Breeze"); break;
    case 28 ... 47: printf("Gale"); break;
    case 48 ... 63: printf("Storm"); break;
    case 64: printf("Hurricane"); break;
    }
    printf("\n");

    //Question 5.
    float inp2;
    printf("Enter the amount of taxable income: ");
    scanf("%f", &inp2);
    printf("Amount of tax of $%.2f is: ", inp2);
    if (inp2 > 7000.00f) printf("$%.2f\n", 230.00f + ((inp2 - 7000.00f) * .06f));
    else if (inp2 > 5250.00f) printf("$%.2f\n", 142.50f + ((inp2 - 5250.00f)* .05f));
    else if (inp2 > 3750.00f) printf("$%.2f\n", 82.50f + ((inp2 - 3750.00f) * 0.04f));
    else if (inp2 > 2250.00f) printf("$%.2f\n", 37.50f + ((inp2 - 2250.00f) * 0.03f));
    else if (inp2 > 750.00f) printf("$%.2f\n", 7.50f + ((inp2 - 750.00f) * 0.02f));
    else printf("$%.2f\n", inp2 * 0.01f);

    //Question 6.
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, 
    first_sum, second_sum, total, check, ichk;
    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
     &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5, &ichk);
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    check = 9 - ((total - 1) % 10);
    if (check != ichk) printf("NOT VAILD\n");
    else printf("VALID\n");

    //Qeustion 7.
    int one, two, thr, four, lgt, smt;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &one, &two, &thr, &four);
    lgt = one; smt = one;
    if (lgt < two) lgt = two;
    if (lgt < thr) lgt = thr;
    if (lgt < four) lgt = four;
    if (smt > two) smt = two;
    if (smt > thr) smt = thr;
    if (smt > four) smt = four;
    printf("largest is : %d, smallest is : %d\n", lgt, smt);

    //Question 8.
    int inph, inpm, cinp;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &inph, &inpm);
    cinp = convert(inph, inpm);
    if (convert(21, 45) < cinp
    || closer(convert(21, 45), cinp, convert(19, 0)) == convert(21, 45))
    {
        printf("Closest departure time is 9:45 p.m, arriving time at 11:58 p.m\n");
    }
    else if (convert(19, 0) < cinp
    || closer(convert(19, 0), cinp, convert(15, 45)) == convert(19, 0))
    {
        printf("Closest departure time is 7:00 p.m, arriving at 9:20 p.m\n");
    }
    else if (convert(15, 45) < cinp
    || closer(convert(15, 45), cinp, convert(14, 0)) == convert(15, 45))
    {
        printf("Closest departure time is 3:45 p.m, arriving at 5:55 p.m\n");
    }
    else if (convert(14, 0) < cinp
    || closer(convert(14, 0), cinp, convert(12, 47)) == convert(14, 0))
    {
        printf("Closest departure time is 2:00 p.m, arriving at 4:08 p.m\n");
    }
    else if (convert(12, 47) < cinp
    || closer(convert(12, 47), cinp, convert(11, 19)) == convert(12, 47))
    {
        printf("Closest departure time is 12:47 p.m, arriving at 3:00 p.m\n");
    }
    else if (convert(11, 19) < cinp
    || closer(convert(11, 19), cinp, convert(9, 43)) == convert(11, 19))
    {
        printf("Closest departure time is 11:19 a.m, arriving at 1:31 p.m\n");
    }
    else if (convert(9, 43) < cinp
    || closer(convert(9, 43), cinp, convert(8, 0)) == convert(9, 43))
    {
        printf("Closest departure time is 9:43 a.m, arriving at 11:52 a.m\n");
    }
    else 
    {
        printf("Closest departure time is 8:00 a.m, arriving at 10:16 a.m\n");
    }

    //Question 9.
    int mnth1, day1, year1, cyear1, mnth2, day2, year2, cyear2, cas;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &mnth1, &day1, &year1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &mnth2, &day2, &year2);
    cyear1 = converty(year1);
    cyear2 = converty(year2);
    if (cyear1 > cyear2) cas = 2;
    else if (cyear2 > cyear1) cas = 1;
    else if (mnth1 > mnth2) cas = 2;
    else if (mnth2 > mnth1) cas = 1;
    else if (day1 > day2) cas = 2;
    else if (day2 > day1) cas = 1;
    else cas = 0;
    if (cas == 2)
    {
        printf("%.2d/%.2d/%.2d is earlier than %2d/%2d/%2d\n",
        mnth2, day2, year2, mnth1, day1, year1);
    } 
    else if (cas == 1)
    {
        printf("%.2d/%.2d/%.2d is earlier than %2d/%2d/%2d\n",
        mnth1, day1, year1, mnth2, day2, year2);
    }
    else if (cas == 0)
    {
        printf("The two dates are same date!");    
    }

    //Question 10.
    int grade;
    printf("Enter numerical grade: ");
    scanf("%d", &grade);
    switch (grade)
    {
    case 90 ... 100: printf("Letter grade: A\n"); break;
    case 80 ... 89: printf("Letter grade: B\n"); break;
    case 70 ... 79: printf("Letter grade: C\n"); break;
    case 60 ... 69: printf("Letter grade: D\n"); break;
    case 0 ... 59: printf("Letter grade: F\n"); break;
    default:  printf("Hey, that shouldn't be your grade!\n"); break;
    }

    //Question 11.
    int tenth, first = 0;
    printf("Enter a two digit number: ");
    scanf("%1d%1d", &tenth, &first);
    if (tenth == 1)
    {
        switch (first)
        {
            case 0: printf("You entered the number ten.\n"); break;
            case 1: printf("You entered the number eleven.\n"); break;
            case 2: printf("You entered the number twelve.\n"); break;
            case 3: printf("You entered the number thirteen.\n"); break;
            case 4: printf("You entered the number fourteen.\n"); break;
            case 5: printf("You entered the number fifteen.\n"); break;
            case 6: printf("You entered the number sixteen.\n"); break;
            case 7: printf("You entered the number seventeen.\n"); break;
            case 8: printf("You entered the number eighteen.\n"); break;
            case 9: printf("You entered the number nineteen.\n"); break;
        }
    }
    else
    {
        switch (tenth)
        {
            case 2: printf("You entered the number twenty"); break;
            case 3: printf("You entered the number thirty"); break;
            case 4: printf("You entered the number fourty"); break;
            case 5: printf("You entered the number fifty"); break;
            case 6: printf("You entered the number sixty"); break;
            case 7: printf("You entered the number seventy"); break;
            case 8: printf("You entered the number eighty"); break;
            case 9: printf("You entered the number ninety"); break;
        }
        switch (first)
        {
            case 0: printf("\n"); break;
            case 1: printf("-one.\n"); break;
            case 2: printf("-two.\n"); break;
            case 3: printf("-three.\n"); break;
            case 4: printf("-four.\n"); break;
            case 5: printf("-five.\n"); break;
            case 6: printf("-six.\n"); break;
            case 7: printf("-seven.\n"); break;
            case 8: printf("-eight.\n"); break;
            case 9: printf("-nine.\n"); break;
        }
    }
    

    return 0;
}

int closer(int lgr, int mn, int smr)
{
    if (lgr - mn > mn - smr) return smr;
    else return lgr;
}

int convert(int hr, int mn)
{
    return hr * 60 + mn;
}

int converty(int year)
{
    if (year > 20)
    {
        year += 1900;
    }
    else 
    {
        year += 2000;
    }
}