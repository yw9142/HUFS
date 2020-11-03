#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Check(string str) // '('과 ')'의 개수가 우선적으로 일치해야함.
{
    int length = (int)str.length(); // 문자열 길이 측정

    stack<char> Stack; // char 자료형이 들어가는 Stack stack을 생성. (size는 자동)
    int i;

    i = 0;
    while (i < length) // 문자열 길이 만큼 반복
    {
        char ch = str[i]; // 문자열의 문자 한개씩 char형 배열에 입력.

        if (ch == '(') // 배열이 '('이면 stack push
            Stack.push(str[i]);
        else
        {
            if (!Stack.empty()) // 배열이 ')'이면 stack이 비어 있는지 확인
                Stack.pop(); // 비어 있지 않으면 stack pop
            else
                return (false); // 비어 있으면 false return
        }
        i++;
    }
    return (Stack.empty());
}

int     main(void)
{
    int T; // 입력 데이터의 개수 (T)

    cin >> T; // 표준입력
    int i;

    i = 0;
    while (i < T)
    {
        string str; // 빈 문자열을 가지도록 string 객체 생성

        cin >> str; // 입력
        if (Check(str))
            cout << "YES" << "\n"; // Check에 성공하면 YES
        else
            cout << "NO" << "\n"; // 실패하면 NO
        i++;
    }
    return (0); // 함수 종료
}