#include <iostream>

using namespace std;

int main() {
    int count = 0;
    char string[30];
    cin >> string;

    while (string[count] != '\0') {
        count++;
    }

    cout << count << endl;
    return (0);
}