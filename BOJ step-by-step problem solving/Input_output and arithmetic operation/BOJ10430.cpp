#include <iostream>
using namespace std;

int main(void){
    int a, b, c;

    cin >> a >> b;
    c = b;

    while (b != 0) {
        printf("%d\n", a * (b % 10));
        b /= 10;
    }

    cout << a * c << endl;

    return (0);
}
