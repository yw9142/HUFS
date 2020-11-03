#include <iostream>

using namespace std;

void check_digit(int first_integer, int second_integer);

int main(void) {
    int first_integer, second_integer;

    cin >> first_integer;
    cin >> second_integer;

    check_digit(first_integer, second_integer);
}

void check_digit(int first_integer, int second_integer) {
    int f_first, f_second, f_third, f_fourth, f_fifth, f_sixth;
    int s_first, s_second, s_third, s_fourth, s_fifth, s_sixth;

    f_sixth = first_integer % 10;
    first_integer /= 10;
    f_fifth = first_integer % 10;
    first_integer /= 10;
    f_fourth = first_integer % 10;
    first_integer /= 10;
    f_third = first_integer % 10;
    first_integer /= 10;
    f_second = first_integer % 10;
    first_integer /= 10;
    f_first = first_integer % 10;

    s_sixth = second_integer % 10;
    second_integer /= 10;
    s_fifth = second_integer % 10;
    second_integer /= 10;
    s_fourth = second_integer % 10;
    second_integer /= 10;
    s_third = second_integer % 10;
    second_integer /= 10;
    s_second = second_integer % 10;
    second_integer /= 10;
    s_first = second_integer % 10;

//    cout << f_first << '\n' << f_second << '\n' << f_third << '\n' << f_fourth << '\n' << f_fifth << '\n' << f_sixth << endl;
//    cout << s_first << '\n' << s_second << '\n' << s_third << '\n' << s_fourth << '\n' << s_fifth << '\n' << s_sixth << endl;


    if (f_first == s_first) {
        cout << "Equal : 1th digit." << endl;
    } else {
        cout << "Different : 1th digit." << endl;
    }

    if (f_second == s_second) {
        cout << "Equal : 2th digit." << endl;
    } else {
        cout << "Different : 2th digit." << endl;
    }

    if (f_third == s_third) {
        cout << "Equal : 3th digit." << endl;
    } else {
        cout << "Different : 3th digit." << endl;
    }

    if (f_fourth == s_fourth) {
        cout << "Equal : 4th digit." << endl;
    } else {
        cout << "Different : 4th digit." << endl;
    }

    if (f_fifth == s_fifth) {
        cout << "Equal : 5th digit." << endl;
    } else {
        cout << "Different : 5th digit." << endl;
    }

    if (f_sixth == s_sixth) {
        cout << "Equal : 6th digit." << endl;
    } else {
        cout << "Different : 6th digit." << endl;
    }
}