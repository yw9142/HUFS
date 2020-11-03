#include <stdio.h>
#include <stdlib.h>

int matrix_sum(void);

int matrix_minus(void);

int matrix_multiplication(void);


int matrix_sum(void) {

    int a = 0, b = 0, c = 0, d = 0; // 행렬 크기
    int i, j;
    printf("Enter the size of the first matrix(a X b) = ");
    scanf("%d %d", &a, &b);
    printf("Enter the size of the second matrix(c X d) = ");
    scanf("%d %d", &c, &d);

    if (a - 1 != c - 1 || b - 1 != d - 1) {
        printf("Both matrices must be the same size.\n");
        return (0);
    }

    int A[a][b];
    int B[c][d];
    int S[a + c][b + d];

//12 12 [0][0] [0][1]
    printf("Please enter %d number to fit in the first matrix\n", a * b);
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Please enter %d number to fit in the second matrix\n", c * d);
    for (i = 0; i < c; i++) {
        for (j = 0; j < d; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            S[i][j] = A[i][j] + B[i][j];
            printf("The sum[%d][%d] matrices is %d\n", i, j, S[i][j]);
        }
        printf("\n");
    }
}

int matrix_minus(void) {

    int a = 0, b = 0, c = 0, d = 0; // 행렬 크기
    int i, j;
    printf("Enter the size of the first matrix(a X b) = ");
    scanf("%d %d", &a, &b);
    printf("Enter the size of the second matrix(c X d) = ");
    scanf("%d %d", &c, &d);

    if (a - 1 != c - 1 || b - 1 != d - 1) {
        printf("Both matrices must be the same size.\n");
        return (0);
    }

    int A[a][b];
    int B[c][d];
    int S[a + c][b + d];

//12 12 [0][0] [0][1]
    printf("Please enter %d number to fit in the first matrix\n", a * b);
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Please enter %d number to fit in the second matrix\n", c * d);
    for (i = 0; i < c; i++) {
        for (j = 0; j < d; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            S[i][j] = A[i][j] - B[i][j];
            printf("The minus[%d][%d] matrices is %d\n", i, j, S[i][j]);
        }
        printf("\n");
    }
}

int matrix_multiplication(void) {

    int a = 0, b = 0, c = 0, d = 0; // 행렬 크기
    int i, j;
    printf("Enter the size of the first matrix(a X b) = ");
    scanf("%d %d", &a, &b);
    printf("Enter the size of the second matrix(c X d) = ");
    scanf("%d %d", &c, &d);

    int A[a][b];
    int B[c][d];
    int S[a + c][b + d];

    if (b - 1 != c - 1) {
        printf("The number of columns in matrix A and the number of rows in matrix B must be the same.\n");
        return (0);
    }

//12 12 [0][0] [0][1]
    printf("Please enter %d number to fit in the first matrix\n", a * b);
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Please enter %d number to fit in the second matrix\n", c * d);
    for (i = 0; i < c; i++) {
        for (j = 0; j < d; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    if (((a == 1 && d == 1) && (b == c)) || ((b == 1 && c == 1) && (a == d))) {
        for (i = 0; i < a; i++) {
            int sum = 0;
            for (j = 0; j < b; j++) {
                sum += (A[i][j] * B[i][j]);
            }
            S[0][0] = sum;
        }
        printf("The multiplication[0][0] matrices is %d\n", S[0][0]);
        return (0);
    }

    for (i = 0; i < a; i++) //a*b
    {
        for (j = 0; j < b; j++) {
            int sum = 0;
            for (int n = 0; n < a; n++) {
                sum = sum + A[i][n] * B[n][j];
            }
            S[i][j] = sum;
        }
    }

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf("The multiplication[%d][%d] matrices is %d\n", i, j, S[i][j]);
        }
        printf("\n");
    }
    return (0);
}

int main() {
    int num;

    while (1) {
        printf("1: SUM\n2: MINUS\n3: MULTIPLICATION\n4: Exit Program\nEnter the number : ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                matrix_sum();
                printf("===============================================================\n");
                break;
            case 2:
                matrix_minus();
                printf("===============================================================\n");
                break;
            case 3:
                matrix_multiplication();
                printf("===============================================================\n");
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter a number from 1 to 4.\n");
                printf("===============================================================\n");
                break;
        }
    }
}