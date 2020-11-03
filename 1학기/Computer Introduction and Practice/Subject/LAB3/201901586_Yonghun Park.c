#include <stdio.h>
#include <ctype.h>

// Chapter5
void digit(void);
void time(void);
void beaufort(void);
void tax(void);
void large_small(void);
void hour(void);
void grade(void);
int numtostr(void);

// Chapter6
void largest(void);
void GCD(void);
void abbreviation(void);
void broker(void);
void euler(void);


// Chapter5 Project 1
void digit(void) {
    int num;
    int digit;

    num = 0;
    digit = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num >= 0 && num <= 9)
        digit = 1;
    else if (num >= 10 && num <= 99)
        digit = 2;
    else if (num >= 100 && num <= 999)
        digit = 3;
    else if (num >= 1000 && num <= 9999)
        digit = 4;

    if (num < 0 || num > 9999)
        printf("Input outside the limit.");
    else
        printf("The number %d has %d digits\n", num, digit);
}

// Chapter5 Project 2
void time(void) {
    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    if (hour == 0)
        printf("Equivalent 12-hour time: 12:%.2d AM\n", minute);
    else if (hour < 12)
        printf("Equivalent 12-hour time: %d:%d AM\n", hour == 0 ? 12 : hour, minute);
    else if (hour == 12)
        printf("Equivalent 12-hour time: %d:%.2d PM\n", hour, minute);
    else
        printf("Equivalent 12-hour time: %d:%d PM\n", hour == 12 ? 12 : hour - 12, minute);
}

// Chapter5 Project 4
void beaufort(void) {
    int speed;

    printf("Enter a wind speed: ");
    scanf("%d", &speed);
    printf("Wind description: ");

    if (speed < 1)
        printf("Calm\n");
    else if (speed <= 3)
        printf("Light air\n");
    else if (speed <= 27)
        printf("Breeze\n");
    else if (speed <= 47)
        printf("Gale\n");
    else if (speed <= 63)
        printf("Storm\n");
    else
        printf("Hurricane\n");
}

// Chapter5 Project 5
void tax(void) {
    float income, tax;

    printf("Enter taxable income: ");
    scanf("%f", &income);

    if (income <= 750.00f)
        tax = .01f * income;
    else if (income <= 2250.00f)
        tax = 7.50f + (0.02f * (income - 750.00f));
    else if (income <= 3750.00f)
        tax = 37.50f + (0.03f * (income - 2250.00f));
    else if (income <= 5250.00f)
        tax = 82.50f + (0.04f * (income - 3750.00f));
    else if (income <= 7000)
        tax = 142.50f + (0.05f * (income - 5250.00f));
    else
        tax = 230.00f + (0.06f * (income - 7000.00f));

    printf("Tax: $%.2f\n", tax);
}

// Chapter5 Project 7
void large_small(void) {
    int i1, i2, i3, i4, swap = 0;

    printf("Enter Four Integers: ");
    scanf("%d %d %d %d", &i1, &i2, &i3, &i4);


    if (i1 > i2) { // smallest
        swap = i1;
        i1 = i2;
        i2 = swap;
    }

    if (i3 > i4) { // largest
        swap = i3;
        i3 = i4;
        i4 = swap;
    }

    printf("Largest: %d\n", i2 > i4 ? i2 : i4);
    printf("Smallest: %d\n", i1 > i3 ? i3 : i1);
}

// Chapter5 Project 8
void hour(void) {
    int user_time, hour, minute,
            d1 = 480,
            d2 = 583,
            d3 = 679,
            d4 = 767,
            d5 = 840,
            d6 = 945,
            d7 = 1140,
            d8 = 1305;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    user_time = hour * 60 + minute;

    printf("Closest departure time is ");

    if (user_time <= d1 + (d2 - d1) / 2)
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (user_time < d2 + (d3 - d2) / 2)
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (user_time < d3 + (d4 - d3) / 2)
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (user_time < d4 + (d5 - d4) / 2)
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (user_time < d5 + (d6 - d5) / 2)
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (user_time < d6 + (d7 - d6) / 2)
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (user_time < d7 + (d8 - d7) / 2)
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
}

// Chapter5 Project 10
void grade(void) {
    int grade;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if (grade > 100 || grade < 0)
        grade = -11; /* To be properly caught in default case */

    switch (grade / 10) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Letter grade: F\n");
            break;
        case 6:
            printf("Letter grade: D\n");
            break;
        case 7:
            printf("Letter grade: C\n");
            break;
        case 8:
            printf("Letter grade: B\n");
            break;
        case 9:
        case 10:
            printf("Letter grade: A\n");
            break;
        default:
            printf("Error\n");
            break;
    }
}

// Chapter5 Project 11
int numtostr(void) {

    int n;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    switch (n / 10) {
        case 1:
            switch (n % 10) {
                case 0:
                    printf("You entered the number ten\n");
                    break;
                case 1:
                    printf("You entered the number eleven\n");
                    break;
                case 2:
                    printf("You entered the number twelve\n");
                    break;
                case 3:
                    printf("You entered the number thirteen\n");
                    break;
                case 4:
                    printf("You entered the number fourteen\n");
                    break;
                case 5:
                    printf("You entered the number fifteen\n");
                    break;
                case 6:
                    printf("You entered the number sixteen\n");
                    break;
                case 7:
                    printf("You entered the number seventeen\n");
                    break;
                case 8:
                    printf("You entered the number eighteen\n");
                    break;
                case 9:
                    printf("You entered the number nineteen\n");
                    break;
                default:
                    break;
            }
            break;
        case 2:
            printf("You entered the number twenty");
            break;
        case 3:
            printf("You entered the number thirty");
            break;
        case 4:
            printf("You entered the number forty");
            break;
        case 5:
            printf("You entered the number fifty");
            break;
        case 6:
            printf("You entered the number sixty");
            break;
        case 7:
            printf("You entered the number seventy");
            break;
        case 8:
            printf("You entered the number eighty");
            break;
        case 9:
            printf("You entered the number ninety");
            break;
        default:
            printf("Your number is out of range 10-99\n");
            return (0);
    }

    if (n / 10 != 1) {
        switch (n % 10) {
            case 0:
                printf("\n");
                break;
            case 1:
                printf("-one\n");
                break;
            case 2:
                printf("-two\n");
                break;
            case 3:
                printf("-three\n");
                break;
            case 4:
                printf("-four\n");
                break;
            case 5:
                printf("-five\n");
                break;
            case 6:
                printf("-six\n");
                break;
            case 7:
                printf("-seven\n");
                break;
            case 8:
                printf("-eight\n");
                break;
            case 9:
                printf("-nine\n");
                break;
            default:
                break;
        }
    }
    return (0);
}

// Chapter6 Project 1
void largest(void) {

    float largest = 0.0f;
    float current;

    do {
        printf("Enter a number: ");
        scanf("%f", &current);

        if (current > largest)
            largest = current;
    } while (current > 0);

    printf("\nThe largest number entered was %.2f\n", largest);
}

// Chapter6 Project 2 // Euclidean algorithm
void GCD(void) {
    int m, n, swap;

    printf("Enter two integers: ");
    scanf("%d%d", &m, &n);

    if (m < n) {
        swap = m;
        m = n;
        n = swap;
    }

    while (n != 0) {
        swap = m % n;
        m = n;
        n = swap;
    }

    printf("Greatest common divisor: %d\n", m);
}

// Chapter6 Project 3
void abbreviation(void) {
    int numerator, denominator, n, m, r;

    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denominator);

    m = numerator;
    n = denominator;

    while (n != 0) { //GCD
        r = m % n;
        m = n;
        n = r;
    }

    printf("In lowest terms: %d/%d\n", numerator / m, denominator / m);
}

// Chapter6 Project 4
void broker(void) {
    float commission, value;

    printf("Enter value of trade: ");
    scanf("%f", &value);

    while (value > 0) {

        if (value < 2500.00f)
            commission = 30.00f + .017f * value;
        else if (value < 6250.00f)
            commission = 56.00f + .0066f * value;
        else if (value < 20000.00f)
            commission = 76.00f + .0034f * value;
        else if (value < 50000.00f)
            commission = 100.00f + .0022f * value;
        else if (value < 500000.00f)
            commission = 155.00f + .0011f * value;
        else
            commission = 255.00f + .0009f * value;

        if (commission < 39.00f)
            commission = 39.00f;

        printf("Commission: $%.2f\n\nEnter value of trade: ", commission);
        scanf("%f", &value);
    }
}

// Chapter6 Project 11 // euler
void euler(void) {
    int i, n, denominator;
    float e;

    printf("Enter integer n: ");
    scanf("%d", &n);

    i = 1;
    denominator = 1;
    e = 1.0f;
    while (i <= n) {
        e += 1.0f / (denominator *= i);
        i++;
    }
    printf("Approximation of e: %f\n", e);
}

int main(void) {
    digit();
    printf("\n");
    time();
    printf("\n");
    beaufort();
    printf("\n");
    tax();
    printf("\n");
    large_small();
    printf("\n");
    hour();
    printf("\n");
    grade();
    printf("\n");
    numtostr();
    printf("\n");
    largest();
    printf("\n");
    GCD();
    printf("\n");
    abbreviation();
    printf("\n");
    broker();
    printf("\n");
    euler();

    return (0);
}