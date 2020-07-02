#include <stdio.h>
#include <stdlib.h>

int intersection_cal(int a[], int l_a, int b[], int l_b, int result[]);

void Find_intersection(void);

void Find_union(void);

int union_cal(int a[], int s_a, int b[], int s_b, int result[]);

void MAX(void);

void MIN(void);

int intersection_cal(int a[], int l_a, int b[], int l_b, int result[]) {
    int i, j, count = 0;
    i = 0;
    while (i < l_a) {
        j = 0;
        while (j < l_b) {
            if (a[i] == b[j]) {
                result[count] = a[i];
                count++;
            }
            j++;
        }
        i++;
    }
    return count;
}

// 1 - Write a C program to find intersection of two sets.
void Find_intersection(void) {
    int a[1000];
    int b[1000];
    int intersection[1000];
    int i, j, count = 0;
    int an, bn;

    printf("How many elements a? : "); // 원소 A 개수 받기
    scanf("%d", &an);
    printf("Please enter the elements of set a = "); // 원소 A 입력 받기
    for (i = 0; i < an; i++) {
        scanf("%d", &a[i]);
    }

    printf("How many elements b? : "); // 원소 B 개수 받기
    scanf("%d", &bn);
    printf("Please enter the elements of set b = "); // 원소 B 입력 받기
    for (j = 0; j < bn; j++) {
        scanf("%d", &b[j]);
    }

    count = intersection_cal(a, an, b, bn, intersection); // count == 교집합의 계수

    printf("Elements of set A = {"); // A 원소 다시 보여주고
    for (i = 0; i < an; i++)
        printf("%d,", a[i]);
    printf("\b}\n");

    printf("Elements of set B = {"); // B 원소 다시 보여주고
    for (i = 0; i < bn; i++)
        printf("%d,", b[i]);
    printf("\b}\n");

    printf("Element of intersection C = {"); // 교집합 C의 원소 보여주기
    for (i = 0; i < count; i++)
        printf("%d,", intersection[i]);
    printf("\b}\n");
}

int union_cal(int a[], int s_a, int b[], int s_b, int result[]) {
    int i, j, count1 = 0, count2 = 0;

    for (i = 0; i < s_a; i++) // result에 a원소 넣고
        result[i] = a[i];

    for (i = 0; i < s_b; i++) // result에 b원소 넣고
        result[s_a + i] = b[i];

    for (i = 0; i < s_a; i++) //
        for (j = 0; j < s_b; j++)
            if (a[i] == b[j]) {
                result[s_a + j] = 0;
                count1++;
            }
    for (i = 0; i < s_b; i++)
        if (result[s_a + i] != 0)
            result[s_a + count2++] = result[s_a + i];
    return count1;
}

// 2 - Write a C program to find union of two sets.
void Find_union(void) {
    int a[10000];
    int b[10000];
    int ft_union[20000];
    int i, j, count = 0;
    int an, bn;

    printf("How many elements a? : "); // 원소 A 개수 받기
    scanf("%d", &an);
    printf("Please enter the elements of set a = "); // 원소 A 입력 받기
    for (i = 0; i < an; i++) {
        scanf("%d", &a[i]);
    }

    printf("How many elements b? : "); // 원소 B 개수 받기
    scanf("%d", &bn);
    printf("Please enter the elements of set b = "); // 원소 B 입력 받기
    for (j = 0; j < bn; j++) {
        scanf("%d", &b[j]);
    }

    count = union_cal(a, an, b, bn, ft_union); // count == 합집합의 계수

    printf("Elements of set A = {"); // A 원소 다시 보여주고
    for (i = 0; i < an; i++)
        printf("%d,", a[i]);
    printf("\b}\n");

    printf("Elements of set B = {"); // B 원소 다시 보여주고
    for (i = 0; i < bn; i++)
        printf("%d,", b[i]);
    printf("\b}\n");

    printf("Element of union C = {"); // 합집합 C의 원소 보여주기
    for (i = 0; i < an + bn - count; i++)
        printf("%d,", ft_union[i]);
    printf("\b}\n");
}

// 3 - Write a C program to find largest element in a list.
void MAX(void) {
    int arrn;
    int arr[10000];
    int max, min;
    int i;

    printf("How many elements? : "); // 원소 개수 받기
    scanf("%d", &arrn);
    printf("Please enter the elements of set a = "); // 원소 A 입력 받기
    for (i = 0; i < arrn; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 0; i < arrn; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("max = %d\n", max);
}

// 4 - Write a C program to find smallest element in a list.
void MIN(void) {
    int arrn;
    int arr[10000];
    int max, min;
    int i;

    printf("How many elements? : "); // 원소 개수 받기
    scanf("%d", &arrn);
    printf("Please enter the elements of set a = "); // 원소 A 입력 받기
    for (i = 0; i < arrn; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 0; i < arrn; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("min = %d\n", min);
}

int main(void) {

    int num;

    while (1) {
        printf("1: Find the intersection\n2: Find the union\n3: Find largest element\n4: Find smallest element\n5: Exit Program\nEnter the number :");
        scanf("%d", &num);

        switch (num) {
            case 1:
                Find_intersection();
                printf("===============================================================\n");
                break;
            case 2:
                Find_union();
                printf("===============================================================\n");
                break;
            case 3:
                MAX();
                printf("===============================================================\n");
                break;
            case 4:
                MIN();
                printf("===============================================================\n");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter a number from 1 to 5.\n");
                printf("===============================================================\n");
                break;
        }
    }
}