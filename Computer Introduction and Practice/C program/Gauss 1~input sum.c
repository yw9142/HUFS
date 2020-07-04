#include <stdio.h>

int	Gauss(int n);

int	Gauss(int n)
{
    return (n+1) * n / 2;
}

int main()
{
    int sum, number, UpperLimit;
    sum = 0;
    number = 1;
    scanf("%i", &UpperLimit);

    if (UpperLimit > 65535)
    {
        printf("-1");
        return (0);
    }

    sum = Gauss(UpperLimit);
    printf(" The sum of the first % i integer is % i ", UpperLimit, sum);
    return (0);
}

//#include <stdio.h>
//
//int main()
//{
//    int sum, number, UpperLimit;
//    sum = 0;
//    number = 1;
//    scanf("%i", &UpperLimit);
//
//    while (number <= UpperLimit)
//    {
//        sum += number;
//        number++;
//        if (sum < 0)
//        {
//            printf("-1");
//            return (0);
//        }
//    }
//
//    printf(" The sum of the first % i integer is % i ", UpperLimit, sum);
//    return (0);
//}