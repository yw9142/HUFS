#include <stdio.h>

float Calculate(float loan, float interest_rate, float monthly_payment)
{
    loan = loan + (loan * (interest_rate / 100) / 12);
    loan = loan - monthly_payment;

    printf("balance remaining after first payment : %.2f\n", loan);
    loan = loan + (loan * (interest_rate / 100) / 12);
    loan = loan - monthly_payment;

    printf("balance remaining after second payment : %.2f\n", loan);
    loan = loan + (loan * (interest_rate / 100) / 12);
    loan = loan - monthly_payment;

    printf("balance remaining after third payment : %.2f\n", loan);
    loan = loan + (loan * (interest_rate / 100) / 12);
    loan = loan - monthly_payment;
}

int     main(void)
{
    float loan;
    float interest_rate;
    float monthly_payment;

    printf("Enter amount of loan : ");
    scanf("%f", &loan);

    printf("Enter interest rate : ");
    scanf("%f", &interest_rate);

    printf("Enter monthly payment : ");
    scanf("%f", &monthly_payment);

    Calculate(loan, interest_rate, monthly_payment);
    return (0);
}