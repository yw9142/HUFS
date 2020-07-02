//없는 데이터도 확인하여 알려줌.

#include<stdio.h>
//Prosto
int main(void) {
    int data[10] = { 1, 3, 4, 6, 8, 10, 13, 14, 15, 16 }; //정렬된 데이터.
    int keyValue; //찾고 싶은 값.

    int startNum;
    int endNum;
    int midNum;
    while (1) { //무한 루프 계속 탐색을 위해.
        for (int i = 0; i < 10; i++) {
            printf("%d ", data[i]);
        }
        printf("\n어떤 값을 찾고싶나요?  : ");
        scanf_s("%d", &keyValue);
        //위는 검색 전 처리.
        startNum = 0;
        endNum = 9; //동적 할당 시엔 배열의 마지막 자리.
        while (1) { //찾을 때까지 무한루프..
            midNum = (startNum + endNum) / 2;
            if (startNum < endNum) { //(<인 이유는 같아지거나 반대가 되면 예외이기 때문)
                //마지막 검사 위치가 아니라면.
                if (data[midNum] < keyValue) {
                    //키 값과 같은지 확인. 데이터가 더 작다면.
                    startNum = midNum + 1;
                }
                else if (data[midNum] > keyValue) {
                    //키 값과 같은지 확인. 데이터가 더 크다면.
                    endNum = midNum - 1;
                }
                else { //키 값과 같다면.
                    printf("Key값(%d)은 data[%d]에 있습니다.\n\n", keyValue, midNum);
                    break;
                }
            }
            else { //마지막 검사위치에서는 따로.
                if (data[midNum] != keyValue) {
                    //같지 않다면 존재하지 않는 데이터.
                    printf("Key값(%d)은 data 배열에 존재하지 않습니다.\n\n", keyValue);
                }
                else { //키 값과 같다면.
                    printf("Key값(%d)은 data[%d]에 있습니다.\n\n", keyValue, midNum);
                }
                break;
            }
        }
    }
    return 0;
}



출처: https://prosto.tistory.com/165 [Prosto]