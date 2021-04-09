/* Chapter 3 programming projects */
#include <stdio.h>

int main (void)
{

    //Question 1.
    int day, month, year;
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("You entered the date %4.4d%2.2d%2.2d\n", year, month, day);

    //Question 2.
    int in;
    float up;
    printf("Enter item number: ");
    scanf("%d", &in);
    printf("Enter unit price: ");
    scanf("%f", &up);
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%7.2f\t%2.2d/%2.2d/%4.4d\n",
     in, up, day, month, year);

    //Question 3.
    int gsiPre, grpId, pubCode, itemNum, checkDig;
    printf("Enter ISBN: ");
    scanf("%d - %d - %d - %d - %d", &gsiPre, &grpId, &pubCode, &itemNum, &checkDig);
    printf("GSI Prefix: %d\nGroup Identifier: %d\nPublisher Code: %d\nItem Number: %d\nCheck digit: %d\n",
    gsiPre, grpId, pubCode, itemNum, checkDig);

    //Question 4.
    int fdig, sdig, tdig;
    printf("Enter phone number [(xxx) xxx - xxxx]: ");
    scanf("(%d) %d - %d", &fdig, &sdig, &tdig);
    printf("%d.%d.%d\n", fdig, sdig, tdig);

    //Question 5.
    int one, two, three, four, five, six, seven, eight, nine;
    printf("Enter the numbers from 1 to 9 in any order: ");
    scanf("%d%d%d%d%d%d%d%d%d", &one, &two, &three, &four, &five, &six, &seven, &eight, &nine);
    printf("%d %d %d\n", one, two, three);
    printf("%d %d %d\n", four, five, six);
    printf("%d %d %d\n", seven, eight, nine);
    printf("Sum of rows: %d %d %d\n", (one + two + three), (four + five + six), (seven + eight + nine));
    printf("Sum of columns: %d %d %d\n", (one + four + seven), (two + five + eight), (three + six + nine));
    printf("Sum of diagnals: %d %d\n", (one + five + nine), (three + five + seven));

    //Question 6.
    int num1, denom1, num2, denom2;

    printf("Enter equation: ");
    scanf("%d/%d + %d/%d", &num1, &denom1, &num2, &denom2);
    printf("The sum is %d/%d\n", (num1 * denom2 + num2 * denom1), (denom1 * denom2));
    
    return 0;
}