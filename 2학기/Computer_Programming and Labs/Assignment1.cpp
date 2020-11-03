#include <iostream>

using namespace std;

int main() {
    int sum;
    int students;
    int average;
    int grade;

    sum = 0;
    students = 0; // 학생 수
    grade = 0;
    // 변수는 do 외부에 선언되어야한다. 그렇지 않으면 do 블록이 종료될 때 변수가 소멸하기 때문이다.
    do {
        cin >> grade;
        if (grade > 0) {
            sum += grade;
            students++;
        }
    } while (grade >= 0);

//  논리적 오류는 do while에서 0이하면 연산되면 안되는 것인데 연산이 되서 결과값이 도출됨.
    average = sum / students;
    cout << average;
    return (0);
}
