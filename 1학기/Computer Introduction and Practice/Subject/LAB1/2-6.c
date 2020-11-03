#include <stdio.h>
#include <math.h>

double  output(int x)
{
    return ((((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x) - 6);
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