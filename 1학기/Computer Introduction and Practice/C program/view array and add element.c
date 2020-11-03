#include<stdio.h>

int main() {
    int a[50], i, n;
    printf("How many elements? ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nCurrent elements in array are :");
    for (i = 0; i < n; i++)
        printf("%5d", a[i]);
    printf("\n\nEnter the new element: ");
    scanf("%d", &a[n]);
    n++; // number of elements are incremented by 1
    printf("\n\nThe resultant array is :");
    for (i = 0; i < n; i++)
        printf("%5d", a[i]);
}
