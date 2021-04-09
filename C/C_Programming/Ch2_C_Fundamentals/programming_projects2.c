#include <stdio.h>
#include <math.h>

int main (void)
{
    // Question 1.
    printf("Question 1\n");
    printf("       *\n      *\n     *\n*   *\n * *\n  *\n");
    
    //Question 2.
    printf("\nQuestion 2\n");
    float radius = 10.0f, volume;
    volume = (4.0f / 3.0f) * M_PI * radius * radius * radius;
    printf("%.5f\n", volume);

    //Question 3.
    printf("\nQuestion 3\n");
    float radius2, volume2;
    printf("Enter a radius of circle: ");
    scanf("%f", &radius2);
    volume2 = (4.0f / 3.0f) * M_PI * radius2 * radius2 * radius2;
    printf("%.5f\n", volume2);

    //Question 4.
    printf("\nQuestion 4\n");
    float btax, atax, tax;
    printf("Enter any dollars-cents amounts: ");
    scanf("%f", &btax);
    printf("Enter the tax amount (in %% without symbol): ");
    scanf("%f", &tax);
    atax = btax * (1 + (tax / 100));
    printf("With tax added: $%.2f\n", atax);

    //Question 5.
    printf("\nQuestion 5\n");
    int x, ans;
    printf("Enter any x value in integer: ");
    scanf("%d", &x);
    ans = 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
    printf("%d\n", ans);

    //Question 6.
    printf("\nQuestion 6\n");
    int x2, ans2;
    printf("Enter any x value in integer: ");
    scanf("%d", &x2);
    ans2 = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("%d\n", ans2);

    //Question 7.
    printf("\nQuestion 7\n");
    int dollar, twenty, ten, five, one;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollar);
    twenty = dollar / 20;
    ten = (dollar % 20) / 10;
    five = ((dollar % 20) % 10) / 5;
    one = (((dollar % 20) % 10) % 5);
    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n",
    twenty, ten, five, one);
    
    //Question 8.
    printf("\nQuestion 8\n");
    float loan, interest, pay;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &pay);
    loan = (loan * (1 + ((interest / 100) / 12))) - pay;
    printf("Balance remaining after first payment: %.2f\n", loan);
    loan = (loan * (1 + ((interest / 100) / 12))) - pay;
    printf("Balance remaining after second payment: %.2f\n", loan);
    loan = (loan * (1 + ((interest / 100) / 12))) - pay;
    printf("Balance remaining after third payment: %.2f\n", loan);

    return 0;
}