#include <iostream>

using namespace std;

int find_second_value(void);

int main(void) {

    cout << find_second_value() << endl;
    return 0;
}

int find_second_value(void) {

    int num, first, second;

    first = second = 0;

    int i = 0;
    do {
        cin >> num;
// 1 2 3 4 5
        if (first < num) {
            second = first;
            first = num;
        } else if (second < num)
            second = num;
        i++;
    } while (i < 5);

    return second;
}