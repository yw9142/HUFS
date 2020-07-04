#include <stdio.h>
#include <math.h>

double  output(int x)
{
    return ((3 * pow(x, 5)) + (2 * pow(x, 4)) - (5 * pow(x, 3)) - (pow(x, 2)) + (7 * x) - 6);
}

int   main(void)
{
    int x;
    printf("enter the X value : ");
    scanf("%d", &x);

    int result;
    result = output(x);

    printf("%d", result);
}