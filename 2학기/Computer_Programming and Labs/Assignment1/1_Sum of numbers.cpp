#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int number = 1;
    int UpperLimit;

    cout << "Please enter the upper limit for which you want to sum " << endl;
    cin >> UpperLimit;

    while (number <= UpperLimit) {
        sum = sum + number;
        number = number + 1;
    }
    cout << "The sum of the first " << UpperLimit << " integer is " << sum;
    return (0);
}
