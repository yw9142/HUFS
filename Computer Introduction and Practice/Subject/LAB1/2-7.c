#include <stdio.h>

int Calculation(int value)
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

int   main(void)
{
    int dollar;

    printf("enter the dollar : ");
    scanf("%d", &dollar);

    printf("%d", Calculation(dollar));
    return (0);
}