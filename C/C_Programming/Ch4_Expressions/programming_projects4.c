/* Chapter 4 programming projects */
#include <stdio.h>

int main (void)
{
    //Question 1.
    int fir, sec;
    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &fir, &sec);
    printf("The reversal is: %d%d\n", sec, fir);

    //Question 2.
    int fir1, sec1, thr;
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &fir1, &sec1, &thr);
    printf("The reversal is: %d%d%d\n", thr, sec1, fir1);

    //Qestion 3.
    int fir2, sec2, thr1, inp;
    printf("Enter a three-digit number: ");
    scanf("%3d", &inp);
    fir2 = inp / 100;
    sec2 = (inp % 100) / 10;
    thr1 = inp % 10;
    printf("The reversal is: %d%d%d\n", thr1, sec2, fir2);

    //Question 4.
    int inp1, octal1, octal2, octal3, octal4, octal5, cur;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &inp1);
    octal5 = inp1 % 8;
    cur = inp1 / 8;
    octal4 = cur % 8;
    cur = cur / 8;
    octal3 = cur % 8;
    cur = cur / 8;
    octal2 = cur % 8;
    cur = cur / 8;
    octal1 = cur % 8;
    printf("In octal, your number is: %d%d%d%d%d\n",
     octal1, octal2, octal3, octal4, octal5);

    //Question 5.
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, 
    first_sum, second_sum, total, check;
    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
     &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5);
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    check = 9 - ((total - 1) % 10);
    printf("Check digit: %d\n", check);

    //Question 6.
    int fir3, sec3, thr2, four, fiv, six, sev, eig, nin, ten, elev, twel, sum1, sum2, tot, check1;
    printf("Enter the first 12 digits of a EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
    &fir3, &sec3, &thr2, &four, &fiv, &six, &sev, &eig, &nin, &ten, &elev, &twel);
    sum1 = sec3 + four + six + eig + ten + twel;
    sum2 = fir3 + thr2 + fiv + sev + nin + elev;
    tot = 3 * sum1 + sum2;
    check1 = 9 - ((tot - 1) % 10);
    printf("Check digit: %d\n", check1);

    return 0;
}