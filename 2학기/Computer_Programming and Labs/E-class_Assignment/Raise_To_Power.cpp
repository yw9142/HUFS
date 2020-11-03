#include <iostream>

using namespace std;

double raiseToPow(double x, int power);

int main(void) {
    cout << "if power is 0 : " << raiseToPow(2, 0) << endl; // if power is 0
    cout << "if power is negative : " << raiseToPow(2, -4) << endl; // if power is negative
    cout << "if power is positive : " << raiseToPow(2, 4) << endl; // if power is positive

    return (0);
}

double raiseToPow(double x, int power) {
    int origin_power = power;
    if (power < 0)
        power *= -1;
    double result;
    int i;

    result = 1.0;
    for (i = 1; i <= power; i++) // braces first
    {
        result *= x; // result = result *x
    }

    if (origin_power < 0)
        return (1.0 / result);
    else
        return (result);
}