#include <stdio.h>

int     reverse_two(void);
int     reverse_three(void);
void    octal(void);
void    upc(void);
void    ean(void);

int     reverse_two(void)
{
    int num;

    num = 0;
    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    if (num < 10 || num > 99)
    {
        printf("Not two digits");
        return (0);
    }

    int first = num / 10;
    int second = num % 10;

    if (second != 0)
        printf("The reversal is:%d", ((second * 10) + first));
    else
        printf("The reversal is:%d", first);
    return 0;
}

int     reverse_three(void)
{
    int num;

    num = 0;
    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    if (num < 100 || num > 999)
    {
        printf("Not three digits");
        return (0);
    }

    int first = num / 100; // 백의자리 123 23
    int re = num % 100; // 23
    int three = re / 10; // 십의자리
    int third = re % 10;

    printf("The reversal is:%d%d%d", third,three,first);
    return 0;
}

void    octal(void)
{
    int n;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    printf("In octal, your number is: %d%d%d%d%d", (n/4096)%8, (n/512)%8, (n/64)%8, (n/8)%8, n%8);
}

void    upc(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5);

    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    printf("Check digit: %d", 9 - ((total - 1) % 10));
}

void    ean(void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, sum1, sum2, total;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);

    sum1 = n2 + n4 + n6 + n8 + n10 + n12;
    sum2 = n1 + n3 + n5 + n7 + n9 + n11;
    total = 3 * sum1 + sum2;

    printf("Check digit: %d", 9 - ((total - 1) % 10));
}

int     main(void) {
    reverse_two();
    printf("\n");
    reverse_three();
    printf("\n");
    octal();
    printf("\n");
    upc();
    printf("\n");
    ean();
    return (0);
}
