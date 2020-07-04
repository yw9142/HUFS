#include <stdio.h>
#include <stdlib.h>

int main() {

    srand((unsigned int)time(NULL));

    int one, two, three, four, five, six, seven, eight, nine, ten;
    one = 0;
    two = 0;
    three = 0;
    four = 0;
    five = 0;
    six = 0;
    seven = 0;
    eight = 0;
    nine = 0;
    ten = 0;
    int eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty;
    eleven = 0;
    twelve = 0;
    thirteen = 0;
    fourteen = 0;
    fifteen = 0;
    sixteen = 0;
    seventeen = 0;
    eighteen = 0;
    nineteen = 0;
    twenty = 0;
    for (int i = 0; i < 1000; ++i)
    {
        int num = rand();
        num = (int)num % 20;
        num += 1;
        if (num == 1)
            one += 1;
        else if (num == 2)
            two += 1;
        else if (num == 3)
            three += 1;
        else if (num == 4)
            four += 1;
        else if (num == 5)
            five += 1;
        else if (num == 6)
            six += 1;
        else if (num == 7)
            seven += 1;
        else if (num == 8)
            eight += 1;
        else if (num == 9)
            nine += 1;
        else if (num == 10)
            ten += 1;
        else if (num == 11)
            eleven += 1;
        else if (num == 12)
            twelve += 1;
        else if (num == 13)
            thirteen += 1;
        else if (num == 14)
            fourteen += 1;
        else if (num == 15)
            fifteen += 1;
        else if (num == 16)
            sixteen += 1;
        else if (num == 17)
            seventeen += 1;
        else if (num == 18)
            eighteen += 1;
        else if (num == 19)
            nineteen += 1;
        else if (num == 20)
            twenty += 1;
        printf("%d\n", num);
    }
    printf("1의 빈도는 : %d 입니다.\n", one);
    printf("2의 빈도는 : %d 입니다.\n", two);
    printf("3의 빈도는 : %d 입니다.\n", three);
    printf("4의 빈도는 : %d 입니다.\n", four);
    printf("5의 빈도는 : %d 입니다.\n", five);
    printf("6의 빈도는 : %d 입니다.\n", six);
    printf("7의 빈도는 : %d 입니다.\n", seven);
    printf("8의 빈도는 : %d 입니다.\n", eight);
    printf("9의 빈도는 : %d 입니다.\n", nine);
    printf("10의 빈도는 : %d 입니다.\n", ten);
    printf("11의 빈도는 : %d 입니다.\n", eleven);
    printf("12의 빈도는 : %d 입니다.\n", twelve);
    printf("13의 빈도는 : %d 입니다.\n", thirteen);
    printf("14의 빈도는 : %d 입니다.\n", fourteen);
    printf("15의 빈도는 : %d 입니다.\n", fifteen);
    printf("16의 빈도는 : %d 입니다.\n", sixteen);
    printf("17의 빈도는 : %d 입니다.\n", seventeen);
    printf("18의 빈도는 : %d 입니다.\n", eighteen);
    printf("19의 빈도는 : %d 입니다.\n", nineteen);
    printf("20의 빈도는 : %d 입니다.\n", twenty);
    printf("%d", one + two + three + four + five + six + seven + eight + nine + ten + eleven + twelve + thirteen + fourteen + fifteen + sixteen + seventeen + eighteen + nineteen + twenty);

    return 0;
}
