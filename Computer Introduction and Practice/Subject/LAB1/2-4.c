#include <stdio.h>

float     taxadded(int ic)
{
    return (ic * (1.05));
}

int     main(void)
{
    float income;

    printf("enter the income : ");
    scanf("%f", &income);

    float result;

    result = taxadded(income);
    printf("%f", result);
}