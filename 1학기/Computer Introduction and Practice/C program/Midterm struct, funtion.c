#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct BOOK_INFO { // Reduce global variables as much as possible and use structures
    int Book_ID;
    char Book_Name[1000];
    char Book_date_of_issue[1000];
    int Publisher_ID;
    char Publisher_Name[1000];
    char Publisher_Number[1000];
    int Author_ID;
    char Author_Name[1000];
    char Author_eaddress[1000];
} BI;

typedef struct PUBLISHER_INFO {
    char Publisher_Name[1000];
    char Publisher_Number[1000];
};

typedef struct AUTHOR_INFO {
    char Author_Name[1000];
    char Author_eaddress[1000];
};

void ADD(struct BOOK_INFO BOOK[]); // prototype declaration

void DELETE(struct BOOK_INFO BOOK[]); // prototype declaration

int SEARCH(struct BOOK_INFO BOOK[]); // prototype declaration

void UPDATE(struct BOOK_INFO BOOK[]); // prototype declaration

void DISPLAY(struct BOOK_INFO BOOK[]); // prototype declaration

int count = 0; // count is set as a global variable so that all functions can be modified.


int main(void) {

    int num;
    struct BOOK_INFO BOOK[100];
    struct PUBLISHER_INFO PUBLISHER[100];
    struct AUTHOR_INFO AUTHOR[100];

    while (1) {

        BI TEMP;
        for (int i = 0; i < count; i++) { // Sort in ascending order by ID
            for (int j = 0; j < count - 1; j++) {
                if (BOOK[j].Book_ID > BOOK[j + 1].Book_ID) {
                    TEMP = BOOK[j];
                    BOOK[j] = BOOK[j + 1];
                    BOOK[j + 1] = TEMP;
                }
            }
        }

        printf("1: ADD_Book information\n2: DELETE_Book information\n3: SEARCH_Book information\n4: UPDATE_Book information\n5: DISPLAY_Book information\n6: Exit Program\nEnter the number : ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                ADD(BOOK); // Passing structure parameters
                printf("===============================================================\n");
                break;
            case 2:
                DELETE(BOOK); // Passing structure parameters
                printf("===============================================================\n");
                break;
            case 3:
                SEARCH(BOOK); // Passing structure parameters
                printf("===============================================================\n");
                break;
            case 4:
                UPDATE(BOOK); // Passing structure parameters
                printf("===============================================================\n");
                break;
            case 5:
                DISPLAY(BOOK); // Passing structure parameters
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

void ADD(struct BOOK_INFO BOOK[]) {
    int ID;
    printf("Enter the Book ID : ");
    scanf("%d", &ID);

    int bool = 0;
    int bool2 = 0;
    for (int i = 0; i < count; i++) {
        if (BOOK[i].Book_ID == ID) { // already exists
            bool = 1; // True
        }
    } // False
    if (bool == 1 || ID < 0) { // already exists or negative number

        while (1) {
            bool2 = 0;
            printf("The ID already exists or you entered a negative number.\n");
            printf("Enter the new Book ID : ");
            scanf("%d", &ID);

            for (int i = 0; i < count; i++) {
                if (BOOK[i].Book_ID == ID) { // already exists
                    bool2 = 1; // True
                }
            } // False
            if (bool2 != 1 && ID >= 0)
                break;
        }
    }

    BOOK[count].Book_ID = ID;

    printf("Enter the Book Name : "); // Set value in current index based on global variable
    scanf("%s", BOOK[count].Book_Name);

    printf("Enter the date of publication of a book : ");
    scanf("%s", BOOK[count].Book_date_of_issue);

    printf("Enter the Publisher Name : ");
    scanf("%s", BOOK[count].Publisher_Name);

    printf("Enter the Publisher Phone Number : ");
    scanf("%s", BOOK[count].Publisher_Number);

    printf("Enter the Author Name : ");
    scanf("%s", BOOK[count].Author_Name);

    printf("Enter the Author e-amil address : ");
    scanf("%s", BOOK[count].Author_eaddress);

    count++;
}

void UPDATE(struct BOOK_INFO BOOK[]) {

    int index;
    int ID;
    printf("Please enter the index of the book you want to modify : ");
    scanf("%d", &index);

    printf("Enter the Book ID : ");
    scanf("%d", &ID);

    int bool = 0;
    int bool2 = 0;
    for (int i = 0; i < count; i++) {
        if (BOOK[i].Book_ID == ID) { // already exists
            bool = 1; // True
        }
    } // False
    if (bool == 1 || ID < 0) { // already exists or negative number

        while (1) {
            bool2 = 0;
            printf("The ID already exists or you entered a negative number.\n");
            printf("Enter the new Book ID : ");
            scanf("%d", &ID);

            for (int i = 0; i < count; i++) {
                if (BOOK[i].Book_ID == ID) { // already exists
                    bool2 = 1; // True
                }
            } // False
            if (bool2 != 1 && ID >= 0)
                break;
        }
    }

    BOOK[index].Book_ID = ID;
    printf("Enter the Book Name : "); // Set value in current index based on global variable
    scanf("%s", BOOK[index].Book_Name);

    printf("Enter the date of publication of a book : ");
    scanf("%s", BOOK[index].Book_date_of_issue);

    printf("Enter the Publisher Name : ");
    scanf("%s", BOOK[index].Publisher_Name);

    printf("Enter the Publisher Phone Number : ");
    scanf("%s", BOOK[index].Publisher_Number);

    printf("Enter the Author Name : ");
    scanf("%s", BOOK[index].Author_Name);

    printf("Enter the Author e-amil address : ");
    scanf("%s", BOOK[index].Author_eaddress);
}

void DELETE(struct BOOK_INFO BOOK[]) {
    int index;
    printf("Please enter the index to be deleted : ");
    scanf("%d", &index);

    if (index >= 0) {
        for (int i = index + 1; i < count; i++) { // Remove spaces by sliding the index one space
            BOOK[i - 1] = BOOK[i];
        }
        count--;
    } else
        printf("Error -- not found");
}

int SEARCH(struct BOOK_INFO BOOK[]) {
    int ID;
    printf("Please enter the BOOK ID : ");
    scanf("%d", &ID);

    int start = 0;
    int end = count;
    int mid;

    while (1) { // Infinite loop until found
        mid = (start + end) / 2;
        if (start < end) { // Exception if equal or opposite
            // If not the last inspection position
            if (BOOK[mid].Book_ID < ID) {
                // Check if it is the same as the key value. If the data is smaller
                start = mid + 1;
            } else if (BOOK[mid].Book_ID > ID) {
                // Check if it is the same as the key value. If the data is bigger
                end = mid - 1;
            } else { // If it is the same as the key value.
                printf("Existing Book ID | INDEX == %d\n", mid);
                break;
            }
        } else {
            if (BOOK[mid].Book_ID != ID) {
                // Data that does not exist if not equal
                printf("Error -- ID not found");
                break;
            } else { // If it is the same as the key value.
                printf("Existing Book ID | INDEX == %d\n", mid);
            }
            break;
        }
    }
    return 0;
}

void DISPLAY(struct BOOK_INFO BOOK[]) {
    int num;
    char author[50], publisher[50]; // Declaration of character array for input
    int flag = 0;

    printf("1. Author\n2.Publisher\n3.All\nEnter the number : ");
    scanf("%d", &num);

    if (num == 1) {
        printf("Enter the author name : ");
        scanf("%s", author);
        printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
        for (int i = 0; i <= count; i++) {
            if (strcmp(author, BOOK[i].Author_Name) ==
                0) { // Output if it matches the data of the structure through strcmp function.
                printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, BOOK[i].Book_ID, BOOK[i].Book_Name,
                       BOOK[i].Book_date_of_issue,
                       BOOK[i].Publisher_Name, BOOK[i].Publisher_Number, BOOK[i].Author_Name,
                       BOOK[i].Author_eaddress);
                flag++;
            }
        }
        if (flag == 0)
            printf("Error -- Author not found\n");
    } else if (num == 2) {
        printf("Enter the Publisher name : ");
        scanf("%s", publisher);
        printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
        for (int i = 0; i <= count; i++) {
            if (strcmp(publisher, BOOK[i].Publisher_Name) ==
                0) { // Output if it matches the data of the structure through strcmp function.
                printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, BOOK[i].Book_ID, BOOK[i].Book_Name,
                       BOOK[i].Book_date_of_issue,
                       BOOK[i].Publisher_Name, BOOK[i].Publisher_Number, BOOK[i].Author_Name,
                       BOOK[i].Author_eaddress);
                flag++;
            }
        }
        if (flag == 0)
            printf("Error -- Publisher not found\n");
    } else if (num == 3) {
        printf("Index\tBook ID\tBook Name\tBook's date of issue\tPublisher Name\tPublisher Number\tAuthor Name\tAuthor Email Address\n");
        for (int i = 0; i < count; ++i) { // Output all
            printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, BOOK[i].Book_ID, BOOK[i].Book_Name,
                   BOOK[i].Book_date_of_issue,
                   BOOK[i].Publisher_Name, BOOK[i].Publisher_Number, BOOK[i].Author_Name,
                   BOOK[i].Author_eaddress);
        }
    } else
        printf("Enter a number from 1 to 3.\n");
}
