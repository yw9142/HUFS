#include <iostream>

using namespace std;

int GCD(int Num1, int Num2);

int main() {
    int num;
    int GCD_num;
    int i = 0;

    do {
        cin >> num;
        if (num == -1)
            break;
        if (i == 0) {
            GCD_num = num;
            i++;
        }
        GCD_num = GCD(GCD_num, num);
    } while (true);

    cout << GCD_num << endl;
    return 0;
}

int GCD(int Num1, int Num2) {
    if (Num1 == 0)
        return 0;

    int Temp, Remainder;

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
    return Num1;
}