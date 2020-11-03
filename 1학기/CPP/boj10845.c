#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 1000

typedef int Data;

typedef struct  _queue
{
    Data arr[MAX_SIZE];
    int front; //  큐의 맨 앞의 위치(인덱스), 다음 서비스를 받을 손님의 번호
    int rear; // 큐의 맨 뒤의 위치(인덱스), 마지막에 온 손님의 번호
    int size; // 큐의 사이즈
}               Queue;

void InitQueue(Queue *cq) // 구조체 전부 초기화
{
    cq -> size = 0;
    cq -> front = 0;
    cq -> rear = 0;
}

int getNextIdx(int idx) //
{
    if(idx + 1 >= MAX_SIZE)
        return (0);
    return (idx + 1);
}

void setNextIdx(int *idx)
{
    if(*idx + 1 >= MAX_SIZE)
        *idx = 0;
    else
        (*idx)++;
}

int Empty(Queue * cq)
{
    if (cq -> front == cq -> rear) // front == rear
        return (TRUE);
    return (FALSE);
}

int Full(Queue *cq) // 큐가 가득 차 있는지 확인
{
    if(getNextIdx(cq -> rear) == cq -> front) // (rear + 1) % Queue Max size == front
        return (TRUE);
    return (FALSE);
}

Data Front(Queue *cq)
{
    if(Empty(cq) == TRUE)
        return (-1);
    return (cq -> arr[cq -> front]);
}

Data Back(Queue *cq)
{
    if (Empty(cq) == TRUE)
        return (-1);
    return (cq -> arr[cq -> front]);
}

void Push(Queue *cq, Data data) // push X: 정수 X를 큐에 넣는 연산이다.
{
    if (Full(cq) == TRUE)
        return;
    cq -> arr[cq -> rear] = data;
    setNextIdx(&(cq -> rear));
    (cq -> size)++;
}

Data Pop(Queue *cq)
{
    if (Empty(cq) == TRUE)
        return (-1);
    int data = cq -> arr[cq -> front];
    setNextIdx(&(cq -> front));
    (cq -> size)--;
    return (data);
}

int     main(void)
{
    int i;
    int N; // 명령의 수
    scanf("%d", &N);

    char str[6];

    Queue q; // 구조체 변수
    InitQueue(&q); // 구조체 초기화
    Data data; // 구조체 변수 // 1

    i = 0;
    while (i < N) // 명령의 수 만큼 반복
    {
        scanf("%s", str); // 명령이 한 개씩 주어짐.
//strcmp는 문자열이 같다면 0 값을 반환하는데 부정연산자를 사용할 경우 0을 거짓으로 판별함.
        if (!strcmp(str, "push")) // push 명령어 일 때
        {
            scanf("%d", &data); // 위에서 불러온 구조체 변수에 값을 입력 // 1
            Push(&q, data);
        }
        else if (!strcmp(str, "pop"))
            printf("%d\n", Pop(&q));
        else if (!strcmp(str, "size"))
            printf("%d\n", q.size);
        else if (!strcmp(str, "empty"))
            printf("%d\n", Empty(&q));
        else if (!strcmp(str, "Front"))
            printf("%d\n", Front(&q));
        else if (!strcmp(str, "back"))
            printf("%d\n", Back(&q));
    }
    return (0);
}