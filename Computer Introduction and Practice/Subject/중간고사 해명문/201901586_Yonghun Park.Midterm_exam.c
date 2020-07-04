#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h> // strcpy를 사용하기 위해 include했음.

// 프로토타입 설정
// 사실 메인을 맨 아래둬서 할필요는 없었는데 그냥 했음.
void ADD(void);

void DELETE(void);

int SEARCH(void);

void UPDATE(void);

void DISPLAY(void);

int check(int ID);

int findauthor(char name);

int findauthor(char name);

/*
 * 설계
 * 2차원배열 써야할듯?
 * 1. ADD = 추가 (완성)
 * 2. UPDATE = 인덱스를 입력받은 후에 수정할 정보를 추가로 받은 후 전체수정 (완성)
 * 3. DELETE = 삭제 (완성)
 * 4. SEARCH = BOOK ID 넣으면 INDEX return (완성)
 * 5. DISPLAY =
 * (1) 저자(완성)
 * (2) 출판사(완성)
 * (3) ALL(완성)
 */

// 메인에서 굳이 넘기지 않고 편하게 접근하기 위해 글로벌 변수로 선언해놓음.
int Book_ID[10000];
char Book_Name[100][1000];
char Book_date_of_issue[100][1000];
char Publisher_Name[100][1000];
char Publisher_Number[100][1000];
char Author_Name[100][1000];
char Author_eaddress[100][1000];
int count = 0; // 스택처럼 관리하기 위해 count로 지금까지 몇개의 자료가 들어갔는지 관리

int findpublisher(char name) { // 출판사명을 기준으로 책정보를 출력해주는 함수
    printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
    for (int i = 0; i < count; i++) {
        if ((char) *Publisher_Name[i] == name) { // 포인터를 사용해서 전역변수와 매개변수를 비교해서 같다면 출력하도록 설정
            printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, Book_ID[i], Book_Name[i], Book_date_of_issue[i],
                   Publisher_Name[i], Publisher_Number[i], Author_Name[i], Author_eaddress[i]);
        }
    }
    return (0); // not found
}

int findauthor(char name) { // 작가명을 기준으로 책정보를 출력해주는 함수
    printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
    for (int i = 0; i < count; i++) {
        if ((char) *Author_Name[i] == name) { // 포인터를 사용해서 전역변수와 매개변수를 비교해서 같다면 출력하도록 설정
            printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, Book_ID[i], Book_Name[i], Book_date_of_issue[i],
                   Publisher_Name[i], Publisher_Number[i], Author_Name[i], Author_eaddress[i]);
        }
    }
    return (0); // not found
}

int check(int ID) { // 중복조건을 확인해주는 함수
    for (int i = 0; i <
                    count; i++) { // 반복문을 count만큼 돌려 즉 스택의 가장 윗부분 자료가 쌓인 만큼 돌려서 만약 글로벌 변수안에 중복되는 상황이 발생하면 return 1을 하고 아니라면 return 0를 함.
        if (Book_ID[i] == ID)
            return (1); // True
    }
    return (0); // False
}

void ADD(void) { // 도서정보를 추가하는 함수.
    printf("Enter the Book ID : "); // 도서 ID 입력
    scanf("%d", &Book_ID[count]); // ID를 Book_ID 글로벌 변수에 count 위치에 저장

    // BOOK ID가 중복되거나 음수인경우를 이곳에서 걸러냄.
    int bool = check(Book_ID[count]); // Check함수를 통해 bool의 상태를 저장해놓음.
    if (bool == 1 || Book_ID[count] < 0) { // bool = 1은 중복된다는 뜻, Book_ID[count] < 0은 음수값을 의미 둘중 하나라도 걸리면 if문에 진입
        int bool2;
        while (1) { // 올바른 값을 입력할 때 까지 무한루프
            printf("The ID already exists or you entered a negative number.\n");
            printf("Enter the Book ID : ");
            scanf("%d", &Book_ID[count]);
            bool2 = check(Book_ID[count]);
            printf("%d\n", bool2);
            if (bool2 == 0 && Book_ID[count] >= 0) { // 만약 bool = 0이 나와서 중복이 안되고 >=으로 0이상의 수라면 break를 통해 반복문 탈출.
                break;
            }
        }
    }
// 나머지 값들 차례대로 입력.
    printf("Enter the Book Name : ");
    scanf("%s", Book_Name[count]);

    printf("Enter the date of publication of a book : ");
    scanf("%s", Book_date_of_issue[count]);

    printf("Enter the Publisher Name : ");
    scanf("%s", Publisher_Name[count]);

    printf("Enter the Publisher Phone Number : ");
    scanf("%s", Publisher_Number[count]);

    printf("Enter the Author Name : ");
    scanf("%s", Author_Name[count]);

    printf("Enter the Author e-amil address : ");
    scanf("%s", Author_eaddress[count]);

    count++; // 함수의 마지막에 count를 증가시켜 스택 증가
}

void UPDATE(void) { // 업데이트 함수.
    int index; // 인덱스

    printf("Please enter the index of the book you want to modify : "); // 인덱스를 입력받으면 그 위치의 정보들을 전부 새로 입력
    scanf("%d", &index); // 여기서 index는 count랑 비슷하다고 보면 됨.

    printf("Book ID : ");
    scanf("%d", &Book_ID[index]); // 여기서부터는 ADD함수랑 똑같지만 보면 count부분이 index인 것을 알 수 있음. ex) Book_ID[index]

    int bool = check(Book_ID[count]);
    if (bool == 1 || Book_ID[count] < 0) {
        int bool2;
        while (1) {
            printf("The ID already exists or you entered a negative number.\n");
            printf("Enter the Book ID : ");
            scanf("%d", &Book_ID[count]);
            bool2 = check(Book_ID[count]);
            printf("%d\n", bool2);
            if (bool2 == 0 && Book_ID[count] >= 0) {
                break;
            }
        }
    }

    printf("Book Name : ");
    scanf("%s", Book_Name[index]);

    printf("Book date of publish : ");
    scanf("%s", Book_date_of_issue[index]);

    printf("Publisher Name : ");
    scanf("%s", Publisher_Name[index]);

    printf("Publisher Phone number : ");
    scanf("%s", Publisher_Number[index]);

    printf("Author Name : ");
    scanf("%s", Author_Name[index]);

    printf("Author E-mail Address : ");
    scanf("%s", Author_eaddress[index]);
}

void DELETE(void) { // 제거 함수
    int index; // 업데이트 함수와 마찬가지로 index를 기반으로 작동
    printf("Please enter the index to be deleted : ");
    scanf("%d", &index);

    if (index >= 0) { // 제거할 인덱스를 입력하면 그 위치를 기반으로 한 칸씩 밀어서 덮어씌움.
        for (int i = index + 1; i < count; i++) {
            Book_ID[i - 1] = Book_ID[i]; // ID는 int형이라서 그냥 대입하면 되는데
            strcpy(Book_Name[i - 1], Book_Name[i]); // 여기는 char형이라서 C언어는 string으로 처리가 안되서 그냥 strcpy를 사용해서 덮어씌움.
            strcpy(Book_date_of_issue[i - 1], Book_date_of_issue[i]);
            strcpy(Publisher_Name[i - 1], Publisher_Name[i]);
            strcpy(Publisher_Number[i - 1], Publisher_Number[i]);
            strcpy(Author_Name[i - 1], Author_Name[i]);
            strcpy(Author_eaddress[i - 1], Author_eaddress[i]);
        }
        count--; // 이후 count를 하나 감소시켜서 스택을 감소시킴.
    } else
        printf("Error -- not found"); // 만약 입력받은 인덱스 음수라면 Error 출력
}

int SEARCH(void) { // 검색 함수
    int BookID;
    printf("Please enter the BOOK ID : "); // BookID를 입력 받아서 찾기로 함 왜냐면 책 이름만 알때 책 이름을 입력해서 index번호를 알아내면 나머지 정보도 얻을 수 있기 때문에.
    scanf("%d", &BookID);

    for (int i = 0; i < count; i++) { // for문을 돌려서 전역변수에 들어있는지 확인, 없으면 Error출력, 있으면 인덱스 번호를 알려줌.
        if (Book_ID[i] == BookID) {
            printf("Existing Book ID | INDEX == %d\n", i);
            return (0); // 여기서 리턴은 큰 의미 없음. 그냥 함수를 종료시키려고 넣은 것.
        }
    }
    printf("Error -- ID not found");
    return (-1); // not found
}

void DISPLAY(void) { // 디스플레이 함수.
    char publisher[1000]; // 출판사와 작가 변수를 입력받을 수 있게 변수를 선언함.
    char author[1000];
    int num = 0;
    printf("1. Author\n2.Publisher\n3.All\nEnter the number : ");
    scanf("%d", &num); //여기서 if else 문을 통해서 입력받은 수에 따라서 작가, 출판사, 전체를 골라서 볼 수 있게 설정함.

    if (num == 1) { // 작가명을 기준으로 확인
        printf("Enter the author name : ");
        scanf("%s", author);
        findauthor((char) *author); // findauthor함수로 이동해서 출력 // display함수에서 매개변수를 보낼때 애스터리스크로 보낸 이유는 char형이라 보낼때 이상하게 매개변수 전달이 되서 if문에 걸리지 않는 오류가 발생했음.
    } else if (num == 2) { // 출판사명을 기준으로 확인.
        printf("Enter the Publisher name : ");
        scanf("%s", publisher);
        findpublisher((char) *publisher); // findpublisher함수로 이동해서 출력 // display함수에서 매개변수를 보낼때 애스터리스크로 보낸 이유는 char형이라 보낼때 이상하게 매개변수 전달이 되서 if문에 걸리지 않는 오류가 발생했음.
    } else if (num == 3) { // 전체 다 출력
        printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
        for (int i = 0; i < count; ++i) { // count 즉 스택이 쌓인 만큼 돌려서 전부 확인
            printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, Book_ID[i], Book_Name[i], Book_date_of_issue[i],
                   Publisher_Name[i], Publisher_Number[i], Author_Name[i], Author_eaddress[i]);
        }
    } else
        printf("Enter a number from 1 to 3.\n");
}

int main(void) { // 메인 함수

    int num;

    while (1) { // while loop와 switch문으로 메인프로그램에서 exit를 하기 전까지 프로그램이 종료되지 않게 설정.
        printf("1: ADD_Book information\n2: DELETE_Book information\n3: SEARCH_Book information\n4: UPDATE_Book information\n5: DISPLAY_Book information\n6: Exit Program\nEnter the number : ");
        scanf("%d", &num);

        switch (num) { // 모든 프로그램은 글로벌 변수에서 참조해서 작동하기 때문에 void형식으로 작성됨.
            case 1:
                ADD();
                printf("===============================================================\n");
                break;
            case 2:
                DELETE();
                printf("===============================================================\n");
                break;
            case 3:
                SEARCH();
                printf("===============================================================\n");
                break;
            case 4:
                UPDATE();
                printf("===============================================================\n");
                break;
            case 5:
                DISPLAY();
                printf("===============================================================\n");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Enter a number from 1 to 6.\n");
                printf("===============================================================\n");
                break;
        }
    }
}