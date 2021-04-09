/*
Add two fractions
*/

#include <stdio.h>

int main (void)
{
    int num1, denom1, num2, denom2, resultNum, result_denom, smnum, lrgnum, lgstrm;
    int rmnum[10];

    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &denom1);

    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &denom2);

    resultNum = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    if (resultNum > result_denom) {smnum = result_denom; lrgnum = resultNum;} else {lrgnum = result_denom; smnum = resultNum;}

    for (int h = 0; h < 10; ++h) {rmnum[h] = -1;}

    for (int i = 1; i < smnum; ++i) {if (!(smnum % i)) rmnum[i-1] = i;}
    for (int j = 0; j < 10; ++j) {
        if (rmnum[j] == -1)
        {
            break;
        }

        else
        {
            if (lrgnum % rmnum[j] == 0)
            {
                lgstrm = rmnum[j];
            }
        }
    }
    resultNum = resultNum / lgstrm;
    result_denom = result_denom / lgstrm;
    printf("The sum is %d/%d\n", resultNum, result_denom);
    
    return 0;
}