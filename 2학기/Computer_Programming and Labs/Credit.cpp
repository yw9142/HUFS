#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int number = 1;
    int UpperLimit;

    cout << "Please enter the upper limit for which you want the sum" << endl;
    cin >> UpperLimit;

    while (number <= UpperLimit) {
        if (number % 2 == 0)
            sum = sum + number;
        if (sum < 0)
            break;
        number = number + 1;
    }
    cout << sum << " " << number << endl;
    cout << "The sum of all even integer between 1 and " << UpperLimit << " is " << sum;
    return (0);
}
// 	2147483647
// Upperlimit == 92681
// sum = 2147441940