#include <iostream>
using namespace std;
int main() {
    int Num1, Num2;
    int Temp, Remainder;
    cin >> Num1 >> Num2;

    if (Num1 < Num2) { // 값 고정을 위한 Swap
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    while (Num2 != 0) {
        Remainder = Num1 % Num2;
        Num1 = Num2;
        Num2 = Remainder;
    }

    cout << Num1 << endl;
    return 0;
}