#include <iostream>
#include <cstring>
using namespace std;

int stack[10001]; // Global variable
int top = -1; // Global variable

void push(int x)
{
    stack[++top] = x; // 첫번째면? stack[0] = 1?
}

int empty() // 상태 return 해줘야해서 int
{
    if (top < 0) // 비어 있다면 (1) 이상숫자 리턴
        return (1);
    else // 아니라면 (0) 정상 리턴
        return (0);
}

void pop()
{
    if (empty() == 1)
        cout << "-1" << "\n";
    else
    {
        cout << stack[top] << "\n"; // 출력하고
        stack[top--] = 0; // 가장 윗부분에 0을 넣고, --연산
    }
}

int     main()
{
    int n; // 첫째 줄 주어지는 명령의 수

    n = 0;
    cin >> n;
    int i; // 명령의 수 만큼 반복문 돌리기위한 변수

    i = 0;
    while(i < n)
    {
        char *str = new char; // 동적할당 써봄, c에서는 malloc이였는데 c++에서는 new연산자가 추가된듯.

        cin >> str; // 입력값 받기
        if (!strcmp(str, "push")) // push 명령어 일때
        {
            int x;

            x = 0;
            cin >> x;
            push(x);
        }
        else if (!strcmp(str, "top")) // top 명령어 일때 // strcmp는 문자열이 같다면 0 값을 반환하는데 부정연산자를 사용할 경우 0을 거짓으로 판별함.
        {
            if (empty() == 1)
                cout << "-1" << "\n"; // 정수가 비어있다면 -1 출력
            else
                cout << stack[top] << "\n"; // 정상적 리턴이 되었다면 스택의 가장 윗부분 출력
        }
        else if (!strcmp(str, "pop")) // pop 명령어 일때
            pop();
        else if (!strcmp(str, "empty")) // empty 명령어 일때
            cout << empty() << "\n";
        else
            cout << top + 1 << "\n"; // 아무것도 아니면 스택 최상부 +1 출력
        i++;
        delete str; // 메모리 반환
    }
    return (0); // 함수 종료
}
// 시간복잡도는 O(N) Linear?