#include <iostream>

using namespace std;

int main() {
    unsigned int pw, sec, store, restore;

    cin >> pw;
    sec = 80245425;

    cout << "Password is " << pw << endl;
    cout << "Masking with " << sec << endl;

    store = pw ^ sec;
    restore = store ^ sec;

    cout << "encryted password is " << store << endl;
    cout << "restored password is " << restore;

    return 0;
}
