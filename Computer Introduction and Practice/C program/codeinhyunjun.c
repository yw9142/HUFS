/*
 * start == 프로그램 실행 (시작)
 * Input Array is a[], unsorted == a[]배열에 정수값 입력. (입력)
 * 변수 n의 값을 배열의 길이로 설정 // int n = sizeof(a) / sizeof(int) (준비)
 * (반복) n is greater than 1 == 배열의 크기(길이) 값이 1보다 큰가? (판단)
 * True => Set i is 1
 * False => Return a[]
 *
 * False의 경우 : 변수 a[]를 Return하고 함수 종료 (처리)
 *
 * True의 경우 : i변수의 값을을1로 정의 (처리)
 * (반복) i is less than n (판단)
 * False의 경우 : 변수 n의 값을 n-1로 바꾸고 n is greater than 1로 돌아가서 반복 (처리)
 *
 * True의 경우 : a[i]가 a[i+1]보다 작은지 한번 더 확인 (판단)
 * 그 이후
 *
 * False의 경우 : a[i]값과 a[i+1]값을 교환 그리고 i의 값을 i+1로 변경 후 i is less than n 반복(처리)
 * True의 경우 :
 */
#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a[10];
    int k = 0;

    while (k < 10) {
        scanf("%d", &a[k]);
        k++;
    }

    int n = (sizeof(a) / sizeof(int)); // 배열의 길이 == n
    int i; // i == 배열 숫자

    while (1) {
        if (n > 1) {
            i = 1;
            while (1) {
                if (i < n) {
                    if (a[i] < a[i + 1]) {
                        i++;
                    } else { // a[i] > a[i+1]
                        swap((int *) a[i], (int *) a[i + 1]);
                        i++;
                    }
                } else {
                    n--;
                    break;
                }
            }
        } else {
            printf("%d : %d : %d\n", i, a[i], n);
            printf("Yay!!");
            return (a[i]);
        }
    }
}



