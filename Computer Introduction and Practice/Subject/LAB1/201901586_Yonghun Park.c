#include <stdio.h>
#include <math.h>

#define PI 3.14

// helper
int Cal1(float radius);
float taxadded(int ic);
double Cal2(int x);
double Cal3(int x);
int Cal4(int value);
float Cal5(float loan, float interest_rate, float monthly_payment);

// function prototype
void volume1(void); // 2-2
void volume2(void); // 2-3
void tax(void); // 2-4
void output1(void); // 2-5
void output2(void); // 2-6
void Calculation(void); // 2-7
void Calculate(void); // 2-8

int     main(void)
{
    volume1();
    printf("\n");
    volume2();
    printf("\n");
    tax();
    printf("\n");
    output1();
    printf("\n");
    output2();
    printf("\n");
    Calculation();
    Calculate();
    return(0);
}

// exercise 2
int     Cal1(float radius)
{
    return ((4.0f * (PI) * radius * radius * radius) / (3.0f));
}

void    volume1(void)
{
    float radius;

    radius = 10;
    float result;

    result = Cal1(radius);
    printf("%f", result);
}

// exercise 3
void     volume2(void)
{
    float radius;

    printf("enter the radius : ");
    scanf("%f", &radius);
    float result;

    result = Cal1(radius);

    printf("%f", result);
}

// exercise 4
float     taxadded(int ic)
{
    return (ic * (1.05));
}

void     tax(void)
{
    float income;

    printf("enter the income : ");
    scanf("%f", &income);

    float result;

    result = taxadded(income);
    printf("%f", result);
}

// exercise 5
double  Cal2(int x)
{
    return ((3 * pow(x, 5)) + (2 * pow(x, 4)) - (5 * pow(x, 3)) - (pow(x, 2)) + (7 * x) - 6);
}

void   output1(void)
{
    int x;
    printf("enter the X value : ");
    scanf("%d", &x);

    int result;
    result = Cal2(x);

    printf("%d", result);
}

// exercise 6
double  Cal3(int x)
{
    return ((((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x) - 6);
}

void   output2(void)
{
    int x;
    printf("enter the X value : ");
    scanf("%d", &x);

    int result;
    result = Cal3(x);

    printf("%d", result);
}

// exercise 7
int Cal4(int value)
{
    int twenty = value / 20;
    int twre = value % 20;

    int ten = twre / 10;
    int tere = twre % 10;

    int five = tere / 5;
    int fire = tere % 5;

    int one = fire / 1;
    int onre = fire / 1;

    printf("$20 bills : %d\n", twenty);
    printf("$10 bills : %d\n", ten);
    printf("$5 bills : %d\n", five);
    printf("$1 bills : %d\n", one);
}

void   Calculation(void)
{
    int dollar;

    printf("enter the dollar : ");
    scanf("%d", &dollar);
    int result;
    Cal4(dollar);
}

// exercise 8
float Cal5(float loan, float interest_rate, float monthly_payment)
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

void     Calculate(void)
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

    Cal5(loan, interest_rate, monthly_payment);
}