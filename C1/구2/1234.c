#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * (1) 저자(미완성)
 * (2) 출판사(미완성)
 * (3) ALL(완성)
 */

int Book_ID[10000];
char Book_Name[100][1000];
char Book_date_of_issue[100][1000];
char Publisher_Name[100][1000];
char Publisher_Number[100][1000];
char Author_Name[100][1000];
char Author_eaddress[100][1000];
int count = 0;

void swapINT(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapCHAR(char *a, char *b) {
    char temp[100];
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void BUBBLESORT(void) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (Book_ID[j] > Book_ID[j + 1]) {
                swapINT(&Book_ID[j], &Book_ID[j + 1]);
                swapCHAR(Book_Name[j], Book_Name[j + 1]);
                swapCHAR(Book_date_of_issue[j], Book_date_of_issue[j + 1]);
                swapCHAR(Publisher_Name[j], Publisher_Name[j + 1]);
                swapCHAR(Publisher_Number[j], Publisher_Number[j + 1]);
                swapCHAR(Author_Name[j], Author_Name[j + 1]);
                swapCHAR(Author_eaddress[j], Author_eaddress[j + 1]);
            }
        }
    }
}

int findpublisher(char name) {
    printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
    for (int i = 0; i < count; i++) {
        if ((char) *Publisher_Name[i] == name) {
            printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, Book_ID[i], Book_Name[i], Book_date_of_issue[i],
                   Publisher_Name[i], Publisher_Number[i], Author_Name[i], Author_eaddress[i]);
        }
    }
    return (0); // not found
}

int findauthor(char name) {
    printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
    for (int i = 0; i < count; i++) {
        if ((char) *Author_Name[i] == name) {
            printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, Book_ID[i], Book_Name[i], Book_date_of_issue[i],
                   Publisher_Name[i], Publisher_Number[i], Author_Name[i], Author_eaddress[i]);
        }
    }
    return (0); // not found
}

int check(int ID) {
    for (int i = 0; i < count; i++) {
        if (Book_ID[i] == ID)
            return (1); // True
    }
    return (0); // False
}

void ADD(void) {
    printf("Enter the Book ID : ");
    scanf("%d", &Book_ID[count]);

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

    count++;
}

void UPDATE(void) {
    int index;

    printf("Please enter the index of the book you want to modify : ");
    scanf("%d", &index);

    printf("Book ID : ");
    scanf("%d", &Book_ID[index]);

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

void DELETE(void) {
    int index;
    printf("Please enter the index to be deleted : ");
    scanf("%d", &index);

    if (index >= 0) {
        for (int i = index + 1; i < count; i++) {
            Book_ID[i - 1] = Book_ID[i];
            strcpy(Book_Name[i - 1], Book_Name[i]);
            strcpy(Book_date_of_issue[i - 1], Book_date_of_issue[i]);
            strcpy(Publisher_Name[i - 1], Publisher_Name[i]);
            strcpy(Publisher_Number[i - 1], Publisher_Number[i]);
            strcpy(Author_Name[i - 1], Author_Name[i]);
            strcpy(Author_eaddress[i - 1], Author_eaddress[i]);
        }
        count--;
    } else
        printf("Error -- not found");
}

int SEARCH(void) {
    int BookID;
    printf("Please enter the BOOK ID : ");
    scanf("%d", &BookID);

    int start = 0;
    int end = count;
    int mid = 0;

    while (1) { //찾을 때까지 무한루프..
        mid = (start + end) / 2;
        if (start < end) { //(<인 이유는 같아지거나 반대가 되면 예외이기 때문)
            //마지막 검사 위치가 아니라면.
            if (Book_ID[mid] < BookID) {
                //키 값과 같은지 확인. 데이터가 더 작다면.
                start = mid + 1;
            } else if (Book_ID[mid] > BookID) {
                //키 값과 같은지 확인. 데이터가 더 크다면.
                end = mid - 1;
            } else { //키 값과 같다면.
                printf("Existing Book ID | INDEX == %d\n", mid);
                return 0;
            }
        } else { //마지막 검사위치에서는 따로.
            if (Book_ID[mid] != BookID) {
                //같지 않다면 존재하지 않는 데이터.
                printf("Error -- ID not found");
                return 0;
            } else { //키 값과 같다면.
                printf("Existing Book ID | INDEX == %d\n", mid);
                return 0;
            }
            break;
        }
    }
}

void DISPLAY(void) {
    char publisher[1000];
    char author[1000];
    int num = 0;
    printf("1. Author\n2.Publisher\n3.All\nEnter the number : ");
    scanf("%d", &num);

    if (num == 1) {
        printf("Enter the author name : ");
        scanf("%s", author);
        printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
        findauthor((char) *author);
    } else if (num == 2) {
        printf("Enter the Publisher name : ");
        scanf("%s", publisher);
        printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
        findpublisher((char) *publisher);
    } else if (num == 3) {
        printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
        for (int i = 0; i < count; ++i) {
            printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, Book_ID[i], Book_Name[i], Book_date_of_issue[i],
                   Publisher_Name[i], Publisher_Number[i], Author_Name[i], Author_eaddress[i]);
        }
    } else
        printf("Enter a number from 1 to 3.\n");
}

int main(void) {
    int num;

    while (1) {
        BUBBLESORT();
        printf("1: ADD_Book information\n2: DELETE_Book information\n3: SEARCH_Book information\n4: UPDATE_Book information\n5: DISPLAY_Book information\n6: Exit Program\nEnter the number : ");
        scanf("%d", &num);

        switch (num) {
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