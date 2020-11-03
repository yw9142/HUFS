#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void even(void);

void odd(void);

void primenum(void);

void betweenprime(void);

int factorial(void);

long long helpfac(long long n);

long long betweenfac(void);

void fibonacci(void);

void sum(void);

// 1: Display a list of even numbers.
void even(void) {
    int count;

    printf("Enter the number :");
    scanf("%d", &count);
    int i = 1;

    while (i <= count) {
        if (i % 2 == 0)
            printf("%d\n", i);
        i++;
    }
}

// 2: Display a list of odd numbers.
void odd(void) {
    int count;

    printf("Enter the number :");
    scanf("%d", &count);
    int i = 1;

    while (i <= count) {
        if (i % 2 != 0)
            printf("%d\n", i);
        i++;
    }
}

// 3: For a given number n check if n  is a prime number.
void primenum(void) {
    int num;

    printf("Enter the number :");
    scanf("%d", &num);
    int i = 2;

    while (i < num) {
        if (num % i == 0)
            break;
        i++;
    }

    if (i == num)
        printf("Prime number\n");
    else
        printf("Not Prime number\n");
}

// 4: Display a list of prime numbers between numbers n and m.
void betweenprime(void) {
    int num1, num2;

    printf("Enter the two number :");
    scanf("%d %d", &num1, &num2);
    int swap;

    if (num1 > num2) {
        swap = num1;
        num1 = num2;
        num2 = swap;
    }
    int i;

    while (num1 <= num2) {
        i = 2;
        while (i < num1) {
            if (num1 % i == 0)
                break;
            i++;
        }
        if (num1 == i)
            printf("%d\n", num1);
        num1++;
    }
}

// 5: Display a factorial of a given number n.
int factorial(void) {
    long long num;
    printf("Enter the number :");
    scanf("%lld", &num);
    long long result, i;

    if (num == 1) {
        printf("%llu", num);
        return (0);
    } else if (num < 0) {
        printf("Error");
        return (1);
    } else {
        result = num;
        i = num - 1;
        while (i > 0) {
            result *= i;
            i--;
        }
        printf("%llu! == %llu\n", num, result);
        return (result);
    }
}

long long helpfac(long long n) {
    long long f = 1;
    long long i;

    i = 1;
    while (i <= n) {
        f *= i;
        i++;
    }
    return (f);
}

// 6: Find factorial of all numbers between numbers n and m.
long long betweenfac(void) {
    long long num1, num2;

    printf("Enter the two number :");
    scanf("%lld %lld", &num1, &num2);
    long long fac;
    while (num1 <= num2) {
        fac = helpfac(num1);
        printf("%lld! == %llu \n", num1, fac);
        num1++;
    }
    return (0);
}

// 7: Generate the Fibonacci sequence up to a number n.
void fibonacci(void) {
    int i, num, head, mid, rear;

    head = 1; // head == n - 2
    mid = 0; // mid == n
    rear = 1; // rear == n - 1

    printf("Enter the fibonacci number :");
    scanf("%d", &num);

    i = 1;
    while (i <= num) {
        printf("%d fibo == %d\n", i, head);
        mid = head + rear;
        head = rear;
        rear = mid;
        i++;
    }
}

// 8: Find the sum of the series [ x - x^3 + x^5 +...]
void sum(void) {
    int x, n;
    int sum, squared, p, minus, m;

    printf("Input the value of x :");
    scanf("%d", &x);

    printf("Input number of terms :");
    scanf("%d", &n);
    int i = 1;

    sum = x; // sum에 x값 넣어놔서 n이 1로 들어오면 반복문을 돌지 않고 1출력
    m = -1;
    while (i < n) {
        squared = (2 * i + 1); // 2번째 부터 3승, 5승 7승, 9승~~~
        p = pow(x, squared); // 제곱변환 x^squared
        minus = p * m; // 짝수항 마이너스
        sum += minus; // 구한 값 계속 더하기
        m = m * (-1); // 다음 차수때 다시 플러스로
        i++;
    }
    printf("Sum[ x - x^3 + x^5 +...] = %d\n", sum);
}

int main(void) {

    int num;

    while (1) {
        printf("1: Display a list of even numbers.\n2: Display a list of odd numbers.\n3: For a given number n check if n  is a prime number.\n4: Display a list of prime numbers between numbers n and m.\n5: Display a factorial of a given number n.\n6: Find factorial of all numbers between numbers n and m.\n7: Generate the Fibonacci sequence up to a number n.\n8: Find the sum of the series [ x - x^3 + x^5 +...]\n9: Exit Program\nEnter the number :");
        scanf("%d", &num);

        switch (num) {
            case 1:
                even();
                printf("===============================================================\n");
                break;
            case 2:
                odd();
                printf("===============================================================\n");
                break;
            case 3:
                primenum();
                printf("===============================================================\n");
                break;
            case 4:
                betweenprime();
                printf("===============================================================\n");
                break;
            case 5:
                factorial();
                printf("===============================================================\n");
                break;
            case 6:
                betweenfac();
                printf("===============================================================\n");
                break;
            case 7:
                fibonacci();
                printf("===============================================================\n");
                break;
            case 8:
                sum();
                printf("===============================================================\n");
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Enter a number from 1 to 9.\n");
                printf("===============================================================\n");
                break;
        }
    }
}