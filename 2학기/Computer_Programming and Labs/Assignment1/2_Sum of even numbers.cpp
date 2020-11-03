#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int number = 1;
    int UpperLimit;
    cout << "Please enter the upper limit for which you want to sum \n";
    cin >> UpperLimit;
    while(number <= UpperLimit)
    {
        if(number % 2 == 0)
            sum = sum + number;
        number = number + 1;
    }
    cout << "The sum of all even integer between 1 and " << UpperLimit << " is " << sum;
    return (0);
}
