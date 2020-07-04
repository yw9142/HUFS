#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 80

void matrix_sum(void);

void grade(void);

void Caesar_cipher(void);

// Project 07
void matrix_sum(void) {
    int i, j, total;
    int n[5][5];

    for (i = 0; i < 5; i++) { // 입력받기
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &n[i][j]);
        }
    }

    printf("Row totals: ");
    for (i = 0; i < 5; i++) {
        total = 0;
        for (j = 0; j < 5; j++) {
            total += n[i][j];
        }
        printf("%d ", total);
    }

    printf("\nColumn totals: ");
    for (i = 0; i < 5; i++) {
        total = 0;
        for (j = 0; j < 5; j++) {
            total += n[j][i];
        }
        printf("%d ", total);
    }
    printf("\n");
}

// Project 08
void grade(void) {
    int i, j, total, high_score, low_score;
    int n[5][5];

    for (i = 0; i < 5; i++) {
        printf("Please enter the quiz score of the %d student :", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &n[i][j]);
        }
    }

    printf("\n");

    printf("Student N's total and average scores: Total / Average\n");
    for (i = 0; i < 5; i++) { // 학생별 총점 및 평균점수
        printf("Student %d's total and average scores: ", i + 1);
        total = 0;
        for (j = 0; j < 5; j++) {
            total += n[i][j];
        }
        printf("%d / %.1f\n", total, (float) total / 5);
    }

    printf("\n");

    printf("Student N's total and average scores: Average / Highest / Lowest\n");
    for (i = 0; i < 5; i++) { // 퀴즈 평균점수, 최고점수, 최저점수
        printf("Average and highest and lowest scores for each quiz in student %d: ", i + 1);
        total = 0;
        high_score = low_score = n[0][i];

        for (j = 0; j < 5; j++) {
            total += n[j][i]; // 합
            if (n[j][i] > high_score) // 크면 high score랑 swap
                high_score = n[j][i];
            if (n[j][i] < low_score) // 작으면 low score랑 swap
                low_score = n[j][i];
        }
        printf("%.1f / %d / %d\n", (float) total / 5, high_score, low_score);
    }
    printf("\n");
}


// Project 15
void Caesar_cipher(void) {
    char sentence[MAX_VALUE];
    int i, n;

    printf("Enter message to be encrypted: ");
    scanf(" %[^\n]", sentence);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);

    printf("Encrypted message: ");
    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z')
            sentence[i] = ((sentence[i] - 'A') + n) % 26 + 'A';
        else if (sentence[i] >= 'a' && sentence[i] <= 'z')
            sentence[i] = ((sentence[i] - 'a') + n) % 26 + 'a';
        putchar(sentence[i]);
    }
    printf("\n");
}

int main() {
    int num;

    while (1) {
        printf("1: Project-07\n2: Project-08\n3: Project-15\n4: Exit Program\nEnter the number : ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                matrix_sum();
                printf("===============================================================\n");
                break;
            case 2:
                grade();
                printf("===============================================================\n");
                break;
            case 3:
                Caesar_cipher();
                printf("===============================================================\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a number from 1 to 4.\n");
                printf("===============================================================\n");
                break;
        }
    }
}