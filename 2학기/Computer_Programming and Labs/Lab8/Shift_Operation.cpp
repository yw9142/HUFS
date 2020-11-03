#include <iostream>
#include <bitset>

using namespace std;

void left_shift(unsigned int num, unsigned int m) {
    num = num << m;
    cout << bitset<8>(num) << endl;
}

void right_shift(unsigned int num, unsigned int m) {
    num = num >> m;
    cout << bitset<8>(num) << endl;
}

int main() {
    unsigned int n;
    unsigned int m;

    cin >> n >> m;

    // cout << bitset<8>(n) << endl;

    left_shift(n, m);
    right_shift(n, m);

    return (0);
}