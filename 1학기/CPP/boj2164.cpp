#include <iostream>
#include <queue>

using namespace std;

int     main(void)
{
    int count;
    queue<int> Queue; // 큐 생성

    scanf("%d", &count); // 카드 개수 입력 // 속도 cin < scanf //
    int i = 1;

    while(i <= count) // 카드개수만큼 큐 원소 추가
    {
        Queue.push(i);
        ++i;
    }
// 마지막 카드가 남을 때 까지 반복.
    while (Queue.size() > 1) // front 원소 제거 -> front원소 back으로 이동 -> 다시 front 원소 제거 반복
    {
        Queue.pop();
        Queue.push(Queue.front()); // 이동이 아닌 추가임.
        Queue.pop(); // 그렇기에 앞의 원소는 남아있어서 삭제해야줘야함.
        if (Queue.size() == 1) // 원소가 하나 남으면 종료. 혹시 몰라서 설정함.
            break;
    } // 1234 234 2342 342 42 424 24 4
// 큐의 가장 앞에 있는 원소 값 출력 == 마지막에 남은 카드
    printf("%d\n", Queue.front()); // 속도 cout < printf

    return (0);
}
// 시간복잡도 == O(n)