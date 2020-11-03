#include <iostream>
using namespace std;
int main() {
    int year;
    cin >> year;

    if ((year % 400) == 0 || ((year % 100) != 0 && (year % 4) == 0))
        cout << 1;
    else if(year < 0)
        cout << "Input should be greater than 0";
    else
        cout << 0;

    return 0;
}
