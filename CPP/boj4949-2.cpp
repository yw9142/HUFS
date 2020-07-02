#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
using std::string;

string Check(string str) // '('과 ')'의 개수가 우선적으로 일치해야함.
{
    int length = (int)str.length(); // 문자열 길이 측정
    bool state = false;

    stack<char> Stack; // char 자료형이 들어가는 Stack stack을 생성. (size는 자동) [], () 담을 스택
    int i;

    i = 0;
    while (i < length) // 문자열 길이 만큼 반복, 문자면 증가만하고 다시 반복
    {
        if (str[i] == '[' || str[i] == '(') // 배열 값이 여는 대괄호 or 소괄호이면 값 스택에 push
            Stack.push(str[i]);
        else if (str[i] == ']') // 배열 값이 닫는 대괄호이고
        {
            if (!Stack.empty() && Stack.top() == '[') // 스택이 비어있지 않고, top값이 '['이면 // top 값이여야 하는 이유는 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
                Stack.pop(); // pop
            else
            {
                state = true; // no bool변수를 true로 바꿈.
                break; // 반복문 탈출
            }
        }
        else if (str[i] == ')') // 배열 값이 닫는 소괄호이고
        {
            if (!Stack.empty() && Stack.top() == '(') // 스택이 비어있지 않고, top값이 '('이면
                Stack.pop(); // pop
            else
            {
                state = true; // no bool변수를 true로 바꿈.
                break; // 반복문 탈출
            }
        }
        i++;
    }
    return (!state && Stack.empty()) ? "yes" : "no"; // 상태가 true이며 스택이 비어있으면 "yes"리턴 아니면 "no" 리턴
}

int     main(void)
{
    string input = ""; // 비어있는 string 변수 선언

    while (true) // 무한 반복
    {
        getline(cin, input); // string 변수 안에 값 입력
        if (input == ".") // 입력의 종료조건으로 맨 마지막에 점 하나(".")가 들어온다.
            break; // 반복문 탈출
        else
            cout << Check(input) << "\n"; // Check 값 + \n
    }
    return (0); // 함수 종료
}