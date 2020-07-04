#include <stdio.h>
#include <stdlib.h>

/*
 * Program design
 * I wrote the program to work through the while loop and switch case.
 * MAIN
 * -1.BOOK
 * -1-1. ADD
 * -1-2. DELETE
 * -1-3. SEARCH
 * -1-4. UPDATE
 * -1-5. DISPLAY
 *
 * -2. AUTHOR
 * -2-1. ADD
 * -2-2. UPDATE
 * -2-3. DELETE
 * -2-4. SEARCH
 *
 * -3. SAVE INFORMATION
 */

typedef struct BOOK_INFO { // Book information struct
    int Book_ID;
    char Book_Name[1000];
    char Publisher_Name[1000];
    char Publication_Date[1000];
    int Author_ID;
} BI;

typedef struct AUTHOR_INFO { // Author information struct
    int Author_ID;
    char Author_Name[1000];
    char Author_address[1000];
    char Author_phone_number[1000];
    char Author_eaddress[1000];
    char Author_biography[1000];
} AI;

// prototype declaration
void book_save_file(BI *BOOK, AI *AUTHOR);

void author_save_file(BI *BOOK, AI *AUTHOR);

int findLoc(int ID, AI *AUTHOR);

void sort(struct BOOK_INFO *BOOK, struct AUTHOR_INFO *AUTHOR);

int check_BOOK(int ID, BI *BOOK);

int check_AUTHOR(int ID, AI *AUTHOR);

void
ADD_BOOK(struct BOOK_INFO *BOOK, struct AUTHOR_INFO *AUTHOR);

void
DELETE_BOOK(struct BOOK_INFO *BOOK);

void SEARCH_BOOK(struct BOOK_INFO *BOOK);

void
UPDATE_BOOK(struct BOOK_INFO *BOOK, struct AUTHOR_INFO *AUTHOR);

void
DISPLAY_BOOK(struct BOOK_INFO *BOOK, struct AUTHOR_INFO *AUTHOR);

void ADD_AUTHOR(struct AUTHOR_INFO *AUTHOR);

void UPDATE_AUTHOR(struct AUTHOR_INFO *AUTHOR);

void DELETE_AUTHOR(struct AUTHOR_INFO *AUTHOR);

int SEARCH_AUTHOR(struct AUTHOR_INFO *AUTHOR);

int count_BOOK = 0; // Book information stack
int count_AUTHOR = 0; // Author information stack


int main(void) {

    int num1, num2;
    BI BOOK[100];
    AI AUTHOR[100];

    while (1) {
        printf("Please select information to access\n"); // The user selected the book function and the author function to use.
        printf("1. Book information\n2. Author information\n3.Exit Program\nEnter the number : ");
        scanf("%d", &num1);
        printf("\n");
        fflush(stdin);

        switch (num1) {
            case 1: // BOOK INFORMATION FUNCTION
                printf("1: ADD_Book information\n2: DELETE_Book information\n3: SEARCH_Book information\n4: UPDATE_Book information\n5: DISPLAY_Book information\n6: Exit Program\nEnter the number : ");
                scanf("%d", &num2);
                fflush(stdin);

                switch (num2) {
                    case 1: // ADD
                        ADD_BOOK(BOOK, AUTHOR); // Passing structure parameters
                        sort(BOOK, AUTHOR);
                        printf("===============================================================\n");
                        break;
                    case 2: // DELETE
                        DELETE_BOOK(BOOK); // Passing structure parameters
                        printf("===============================================================\n");
                        break;
                    case 3: // SEARCH
                        SEARCH_BOOK(BOOK); // Passing structure parameters
                        printf("===============================================================\n");
                        break;
                    case 4: // UPDATE
                        UPDATE_BOOK(BOOK, AUTHOR); // Passing structure parameters
                        sort(BOOK, AUTHOR);
                        printf("===============================================================\n");
                        break;
                    case 5: // DISPLAY
                        DISPLAY_BOOK(BOOK, AUTHOR); // Passing structure parameters
                        printf("===============================================================\n");
                        break;
                    case 6:
                        printf("\n");
                        break;
                    default:
                        printf("Enter a number from 1 to 6.\n");
                        printf("===============================================================\n");
                        break;
                }
                break;

            case 2: // AUTHOR INFORMATION FUNCTION
                printf("1: ADD_Author information\n2: DELETE_Author information\n3: SEARCH_Author information\n4: UPDATE_Author information\n5: Exit Program\nEnter the number : ");
                scanf("%d", &num2);
                fflush(stdin);

                switch (num2) {
                    case 1: // ADD
                        ADD_AUTHOR(AUTHOR); // Passing structure parameters
                        printf("===============================================================\n");
                        break;
                    case 2: // DELETE
                        DELETE_AUTHOR(AUTHOR); // Passing structure parameters
                        printf("===============================================================\n");
                        break;
                    case 3: // SEARCH
                        SEARCH_AUTHOR(AUTHOR); // Passing structure parameters
                        printf("===============================================================\n");
                        break;
                    case 4: // UPDATE
                        UPDATE_AUTHOR(AUTHOR); // Passing structure parameters
                        printf("===============================================================\n");
                        break;
                    case 5:
                        printf("\n");
                        break;
                    default:
                        printf("Enter a number from 1 to 5.\n");
                        printf("===============================================================\n");
                        break;
                }
                break;
            case 3: // End of program
                exit(0);
                break;
            default:
                printf("Enter a number from 1 to 5.\n");
                printf("===============================================================\n");
                break;
        } // Save the information received after using the function as a txt file
        book_save_file(BOOK, AUTHOR);
        author_save_file(BOOK, AUTHOR);
    }
}

void book_save_file(BI *BOOK, AI *AUTHOR) {
    int FINDID = 0;
    FILE *fp; // file pointer
    fp = fopen("BOOK_INFORMATION.txt", "w"); // Opened for writing only to enter information.

    // information list
    fprintf(fp,
            "index\tBOOK ID\tBOOK NAME\tPUBLISHER NAME\tPUBLICATION DATE\tAUTHOR NAME\tAuthor Name\tAuthor address\tAuthor phone number\tAuthor email\tAuthor short biography\n");
    for (int i = 0; i < count_BOOK; i++) { // writing information
        FINDID = findLoc(BOOK[i].Author_ID, AUTHOR);
        fprintf(fp, "%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", i, BOOK[i].Book_ID, BOOK[i].Book_Name,
                BOOK[i].Publisher_Name, BOOK[i].Publication_Date, AUTHOR[FINDID].Author_Name,
                AUTHOR[FINDID].Author_address, AUTHOR[FINDID].Author_phone_number, AUTHOR[FINDID].Author_eaddress,
                AUTHOR[FINDID].Author_biography);
    }
    fclose(fp); // close file
}

void author_save_file(BI *BOOK, AI *AUTHOR) {
    FILE *fp; // file pointer
    fp = fopen("AUTHOR_INFORMATION.txt", "w"); // Opened for writing only to enter information.
    // information list
    fprintf(fp, "index\tAuthor Name\tAuthor address\tAuthor phone number\tAuthor email\tAuthor short biography\n");
    for (int i = 0; i < count_AUTHOR; i++) { // writing information
        fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%s\n",
                i, AUTHOR[i].Author_Name, AUTHOR[i].Author_address, AUTHOR[i].Author_phone_number,
                AUTHOR[i].Author_eaddress, AUTHOR[i].Author_biography);
    }
    fclose(fp); // close file
}

int findLoc(int ID, AI *AUTHOR) { // Function to find author information through the author ID of the book struct.
    for (int i = 0; i < count_AUTHOR; ++i) {
        if (AUTHOR[i].Author_ID == ID)
            return (i);
    }
    return (-1); // not found
}

void sort(BI *BOOK, AI *AUTHOR) { // Structure alignment function for binary search
    BI TEMP;
    for (int i = 0; i < count_BOOK; i++) { // Sort in ascending order by ID
        for (int j = 0; j < count_BOOK - 1; j++) {
            if (BOOK[j].Book_ID > BOOK[j + 1].Book_ID) {
                TEMP = BOOK[j];
                BOOK[j] = BOOK[j + 1];
                BOOK[j + 1] = TEMP;
            }
        }
    }
}

int check_BOOK(int ID, BI *BOOK) { // BOOK ID validation function
    for (int i = 0; i < count_BOOK; i++) {
        if (BOOK[i].Book_ID == ID) // return True if duplicate
            return (1); // True
    }
    return (0); // False
}

int check_AUTHOR(int ID, AI *AUTHOR) { // AUTHOR ID duplicate check function
    for (int i = 0; i < count_AUTHOR; i++) {
        if (AUTHOR[i].Author_ID == ID) // return True if duplicate
            return (1); // True
    }
    return (0); // False
}

void ADD_BOOK(BI *BOOK, AI *AUTHOR) {
    int BID, AID;
    int bool;
    printf("Enter the Book ID : ");
    scanf("%d", &BID);
    fflush(stdin);

    bool = check_BOOK(BID, BOOK); // ID Validation check
    if (bool == 1 || BID < 0) { // already exists or negative number
        while (1) {
            printf("The ID already exists or you entered a negative number.\n");
            printf("Enter the Book ID : ");
            scanf("%d", &BID);
            bool = check_BOOK(BID, BOOK);
            if (bool == 0 && BID >= 0) { // If unique and non-negative ID, break.
                break;
            }
        }
    }

    BOOK[count_BOOK].Book_ID = BID; // BOOK ID setting
    // BOOK struct information input
    printf("Enter the BOOK NAME : ");
    scanf("%s", BOOK[count_BOOK].Book_Name);
    fflush(stdin);

    printf("Enter the PUBLISHER NAME : ");
    scanf("%s", BOOK[count_BOOK].Publisher_Name);
    fflush(stdin);

    printf("Enter the PUBLICATION DATE : ");
    scanf("%s", BOOK[count_BOOK].Publication_Date);
    fflush(stdin);


    printf("Enter the Author ID, If there is no ID, enter new information. : "); // AUTHOR ID setting
    scanf("%d", &AID);
    fflush(stdin);

    bool = check_AUTHOR(AID, AUTHOR); // ID Validation check

    BOOK[count_BOOK].Author_ID = AID; // Author ID stored in BOOK struct

    if (bool == 1) {
        printf("Author ID that already exists. It is entered automatically.\n"); // Automatic setting without input if ID already exists
    } else {
        printf("Author ID doesn't exists.\n");
        printf("Enter the Author Name : "); // If it does not exist, enter new information
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_Name);
        fflush(stdin);

        printf("Enter the Author address : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_address);
        fflush(stdin);

        printf("Enter the Author phone number : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_phone_number);
        fflush(stdin);

        printf("Enter the Author e-amil : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_eaddress);
        fflush(stdin);

        printf("Enter the Author short biography : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_biography);
        fflush(stdin);

        AUTHOR[count_AUTHOR].Author_ID = AID; // Author ID stored in Author struct
        count_AUTHOR++; // author stack increase
    }
    count_BOOK++; // book stack increase
}

void DELETE_BOOK(BI *BOOK) {
    int index;
    printf("Please enter the index to be deleted : "); // Remove the information by receiving the index.
    scanf("%d", &index);
    fflush(stdin);

    if (index >= 0) {
        for (int i = index + 1; i < count_BOOK; i++) { // Remove spaces by sliding the index one space
            BOOK[i - 1] = BOOK[i];
        }
        count_BOOK--; // Book stack reduction
    } else
        printf("Error -- Invalid index."); // If the input index is negative, error message output
}


void SEARCH_BOOK(BI *BOOK) {
    int ID;
    printf("Please enter the BOOK ID : "); // if you enter ID, search function view index
    scanf("%d", &ID);
    fflush(stdin);

    int start = 0;
    int end = count_BOOK;
    int mid;
    // binary search
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
                printf("Existing Book ID | INDEX == %d // BOOK NAME == %s // PUBLISHER NAME == %s // PUBLICATION DATE == %s\n",
                       mid, BOOK[mid].Book_Name, BOOK[mid].Publisher_Name, BOOK[mid].Publication_Date);
                break;
            }
        } else {
            if (BOOK[mid].Book_ID != ID) {
                // Data that does not exist if not equal
                printf("Error -- ID not found");
                break;
            } else { // If it is the same as the key value.
                printf("Existing Book ID | INDEX == %d // BOOK NAME == %s // PUBLISHER NAME == %s // PUBLICATION DATE == %s\n",
                       mid, BOOK[mid].Book_Name, BOOK[mid].Publisher_Name, BOOK[mid].Publication_Date);
            }
            break;
        }
    }
}


void UPDATE_BOOK(BI *BOOK, AI *AUTHOR) {

    int index;
    int BID, AID;
    int bool;
    printf("Please enter the index of the book you want to modify : "); // Update by receiving index
    scanf("%d", &index);
    fflush(stdin);
    // Enter all information according to the index.
    printf("Enter the Book ID : ");
    scanf("%d", &BID);
    fflush(stdin);

    bool = check_BOOK(BID, BOOK); // ID Validation
    if (bool == 1 || BID < 0) { // already exists or negative number
        while (1) {
            printf("The ID already exists or you entered a negative number.\n");
            printf("Enter the Book ID : ");
            scanf("%d", &BID);
            bool = check_BOOK(BID, BOOK);
            if (bool == 0 && BID >= 0) {
                break;
            }
        }
    }

    BOOK[index].Book_ID = BID; // BOOK ID setting

    printf("Enter the BOOK NAME : ");
    scanf("%s", BOOK[index].Book_Name);
    fflush(stdin);

    printf("Enter the PUBLISHER NAME : ");
    scanf("%s", BOOK[index].Publisher_Name);
    fflush(stdin);

    printf("Enter the PUBLICATION DATE : ");
    scanf("%s", BOOK[index].Publication_Date);
    fflush(stdin);


    printf("Enter the Author ID, If there is no ID, enter new information. : "); // AUTHOR ID setting
    scanf("%d", &AID);
    fflush(stdin);

    bool = check_AUTHOR(AID, AUTHOR);

    BOOK[index].Author_ID = AID;

    if (bool == 1) {
        printf("Author ID that already exists. It is entered automatically.\n"); // Automatic setting without input if ID already exists
    } else {
        printf("Author ID doesn't exists.\n");
        printf("Enter the Author Name : "); // If it does not exist, enter new information
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_Name);
        fflush(stdin);

        printf("Enter the Author address : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_address);
        fflush(stdin);

        printf("Enter the Author phone number : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_phone_number);
        fflush(stdin);

        printf("Enter the Author e-amil : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_eaddress);
        fflush(stdin);

        printf("Enter the Author short biography : ");
        scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_biography);
        fflush(stdin);

        AUTHOR[count_AUTHOR].Author_ID = AID;

        count_AUTHOR++;
    }
} // Because it is an update function, it does not increase the book stack.


void DISPLAY_BOOK(BI *BOOK, AI *AUTHOR) {
    int FINDID;
    printf("Index\tBook ID\tBook Name\tPublisher Name\tPublication date\tAuthor Name\tAuthor address\tAuthor phone number\tAuthor Email Address\tAuthor short biography\n");
    for (int i = 0; i < count_BOOK; ++i) { // Output all
        FINDID = findLoc(BOOK[i].Author_ID,
                         AUTHOR); // The index of the author struct is obtained through the author ID of the book struct.
        printf("%d\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", i, BOOK[i].Book_ID, BOOK[i].Book_Name,
               BOOK[i].Publisher_Name, BOOK[i].Publication_Date, AUTHOR[FINDID].Author_Name,
               AUTHOR[FINDID].Author_address, AUTHOR[FINDID].Author_phone_number, AUTHOR[FINDID].Author_eaddress,
               AUTHOR[FINDID].Author_biography);
    }
}

void ADD_AUTHOR(AI *AUTHOR) {
    int AID, bool;

    printf("Enter the Author ID : ");
    scanf("%d", &AID);
    fflush(stdin);

    bool = check_AUTHOR(AID, AUTHOR);

    if (bool == 1) {
        printf("Duplicate ID");
        while (1) {
            printf("Enter the Author ID : ");
            scanf("%d", &AID);
            fflush(stdin);

            bool = check_AUTHOR(AID, AUTHOR);
            if (bool != 1) {
                AUTHOR[count_AUTHOR].Author_ID = AID;
                break;
            }
        }
    } else {
        AUTHOR[count_AUTHOR].Author_ID = AID;
    }

    printf("Enter the Author Name : "); // If it does not exist, enter new information
    scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_Name);
    fflush(stdin);

    printf("Enter the Author address : ");
    scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_address);
    fflush(stdin);

    printf("Enter the Author phone number : ");
    scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_phone_number);
    fflush(stdin);

    printf("Enter the Author e-amil : ");
    scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_eaddress);
    fflush(stdin);

    printf("Enter the Author short biography : ");
    scanf("%[^\n]s", AUTHOR[count_AUTHOR].Author_biography);
    fflush(stdin);

    count_AUTHOR++; // author stack increase
}

void UPDATE_AUTHOR(AI *AUTHOR) {
    int index, AID, bool;

    printf("Please enter the INDEX of the book you want to modify : "); // Update by receiving the index.
    scanf("%d", &index);
    fflush(stdin);
    //
    printf("Enter the Author ID : ");
    scanf("%d", &AID);
    fflush(stdin);

    bool = check_AUTHOR(AID, AUTHOR);

    if (bool == 1) {
        printf("Duplicate ID");
        while (1) {
            printf("Enter the Author ID : ");
            scanf("%d", &AID);
            fflush(stdin);

            bool = check_AUTHOR(AID, AUTHOR);
            if (bool != 1)
                break;
        }
    } else {
        AUTHOR[index].Author_ID = AID;
    }
    // Enter all information according to the index.
    printf("Enter the Author Name : "); // If it does not exist, enter new information
    scanf("%[^\n]s", AUTHOR[index].Author_Name);
    fflush(stdin);

    printf("Enter the Author address : ");
    scanf("%[^\n]s", AUTHOR[index].Author_address);
    fflush(stdin);

    printf("Enter the Author phone number : ");
    scanf("%[^\n]s", AUTHOR[index].Author_phone_number);
    fflush(stdin);

    printf("Enter the Author e-amil : ");
    scanf("%[^\n]s", AUTHOR[index].Author_eaddress);
    fflush(stdin);

    printf("Enter the Author short biography : ");
    scanf("%[^\n]s", AUTHOR[index].Author_biography);
    fflush(stdin);
} // Because it is an update function, it does not increase the author stack.

void DELETE_AUTHOR(AI *AUTHOR) {
    int index;
    printf("Please enter the index to be deleted : "); // Remove the information by receiving the index.
    scanf("%d", &index);
    fflush(stdin);

    if (index >= 0) {
        for (int i = index + 1; i < count_AUTHOR; i++) { // Remove spaces by sliding the index one space
            AUTHOR[i - 1] = AUTHOR[i];
        }
        count_AUTHOR--;
    } else
        printf("Error -- Invalid index."); // If the input index is negative, error message output
}

int SEARCH_AUTHOR(AI *AUTHOR) { // Linear search
    int AUTHORID;
    printf("Please enter the AUTHOR ID : ");
    scanf("%d", &AUTHORID);

    for (int i = 0; i < count_AUTHOR; i++) {
        if (AUTHOR[i].Author_ID == AUTHORID) {
            printf("Existing AUTHOR ID | INDEX == %d // AUTHOR NAME == %s // AUTHOR address == %s // AUTHOR phone number == %s // AUTHOR e-mail == %s // AUTHOR short biography == %s\n",
                   i, AUTHOR[i].Author_Name, AUTHOR[i].Author_address, AUTHOR[i].Author_phone_number,
                   AUTHOR[i].Author_eaddress, AUTHOR[i].Author_biography);
            return 0;
        }
    }
    printf("Error -- ID not found");
    return (-1); // not found
}