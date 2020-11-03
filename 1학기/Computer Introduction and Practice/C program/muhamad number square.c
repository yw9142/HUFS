#include <stdio.h>

int main() {
    int row;//행
    int col;//열
    int N;//입력하는 수

    scanf("%d", &N);//입력받는 수 입력하기
    int A[N][N];//a의 행렬


    for (row = 0; row < N; row++)//행 i까지
    {
        for (col = 0; col < N; col++)//열 i까지
        {
            scanf("%d", &A[row][col]);
        }
    }

    int B[N][N];

    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            B[i][j] = A[j][i];
        }
    }

    for (int q = 0; q < N; q++)
    {
        for (int w = 0; w < N; w++)
            printf("%d\t", B[q][w]);
        printf("\n");
    }

}