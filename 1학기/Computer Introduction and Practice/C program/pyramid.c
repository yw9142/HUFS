#include <stdio.h>

int main() {
    int i, j, s;

    scanf("%d", &s);
    for (i = 0; i < s; i++) {
        for (j = 0; j < s - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j < i + 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}