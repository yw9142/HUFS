#include <iostream>

using namespace std;

int main() {
    int A;
    int B;
    cin >> A >> B;

    if ((A != 1 && A != 0) || (B != 1 && B != 0)) {
        cout << "Error!" << endl;
        return (0);
    }

    cout << "Sum : " << (A ^ B) << endl;
    cout << "Carry : " << (A & B) << endl;

    return (0);
}