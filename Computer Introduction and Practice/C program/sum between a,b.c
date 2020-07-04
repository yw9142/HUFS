#include <stdio.h>

int solution(int a, int b);

int solution(int a, int b)
{
    int sum = 0;
    sum = b - a + 1;
    return sum * (a + b) / 2;
}


int main()
{
    int lower, upper;

    scanf("%d%d", &lower, &upper);
    int lower2 = lower;
    int sum = solution(lower, upper);
    printf("The sum between %d and %d is %d", lower2, upper, sum);
    return (0);
}
//
//    if (upper > 65535)
//    {
//        printf("-1");
//        return (0);
//    }
//
//    while (lower <= upper)
//    {
//        sum += lower;
//        lower++;
//    }