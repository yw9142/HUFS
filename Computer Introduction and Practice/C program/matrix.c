#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_dice_face(void) {

    static int count = 0;
    static int one = 0;
    static int two = 0;
    static int three = 0;
    static int four = 0;
    static int five = 0;
    static int six = 0;

    int num;
    num = rand();
    num = (int) num % 6;
    num++;

    if (num == 1)
        one++;
    else if (num == 2)
        two++;
    else if (num == 3)
        three++;
    else if (num == 4)
        four++;
    else if (num == 5)
        five++;
    else if (num == 6)
        six++;
    count++;

    if (count % 100 == 0) {
        printf("1 -> %d\n", one);
        printf("2 -> %d\n", two);
        printf("3 -> %d\n", three);
        printf("4 -> %d\n", four);
        printf("5 -> %d\n", five);
        printf("6 -> %d\n", six);
        printf("%d", one + two + three + four + five + six);
    }
}

int main(void) {
    srand((unsigned int) time(NULL));
    for (int i = 0; i < 100; ++i)
        get_dice_face();
    return (0);
}