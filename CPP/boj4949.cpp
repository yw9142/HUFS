#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    while (true) { // 무한 반복 후 조건에 따라 break로 탈출
        stack<char> Stack; // 괄호를 담는 스택
        string s; // 균형 잡힌지 알고 싶은 문자열
        bool check = true; // 균형 잡힌 상태인지 나타내는 변수

        getline(cin, s); //공백을 포함한 입력

        // 입력의 종료조건으로 맨 마지막에 점 하나(".")가 들어온다.
        if (s == ".") {
            break;
        }

        //문자열을 조사하여 스택에 하나씩 '('나 '['를 넣는다.
        unsigned int i = 0;
        while (i < s.size())
        {
            if (Stack.size() == 0 && (s[i] == ']' || s[i] == ')')) //문자열이 비었는데 닫는 괄호를 만나면
            {
                check = false; //잘못된 균형
                break; //탐색 종료
            }
            if (s[i] == '(' || s[i] == '[') //여는 괄호를 만났다면
                Stack.push(s[i]); //스택에 넣는다.
            else if (s[i] == ')')  //')'를 만났을 때
            {
                if (Stack.top() == '(') //스택 맨 꼭대기에 '('가 있다면
                    Stack.pop(); //꼭대기를 빼준다.
                else if(Stack.top() == '[') //스택 맨 꼭대기에 '['가 있다면
                {
                    check = false; //잘못된 균형
                    break; //탐색 종료
                }
            }
            else if (s[i] == ']') //']'를 만났을 때
            {
                if (Stack.top() == '[')  //스택 맨 꼭대기에 '['가 있다면
                    Stack.pop(); //꼭대기를 빼준다.
                else if (Stack.top() == '(') //스택 맨 꼭대기에 '('가 있다면
                {
                    check = false; //잘못된 균형
                    break; //탐색 종료
                }
            }
            i++;
        }

        if (check == false || Stack.size() != 0)  //탐색 결과가 틀렸거나 스택에 원소가 쌓여 있으면
            cout << "no" << '\n';
        else //탐색 결과가 맞고 스택에 원소가 없으면
            cout << "yes" << '\n';
    }
}