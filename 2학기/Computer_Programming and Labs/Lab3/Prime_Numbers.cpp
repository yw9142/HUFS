#include <iostream>
using namespace std;

int main() {
    int number;
    int i, j;

    cin >> number;

    for (i = 1; i <= number; i++) {
        for (j = 2; j < i; j++) { // 2 ~ number까지의 수로 i를 나눠보면서 소수 판별 | 소수가 아니라면 break;
            if (i % j == 0)
                break;
        }
        if (j == i) // 하나도 안걸리고 i와 j만 나누어 떨어지면 소수이므로 출력
            cout << j << " ";
    }
    return (0);
}