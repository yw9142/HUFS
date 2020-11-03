#include <stdio.h>
#include <stdlib.h>

int findLoc(const int *S_ID, int number);

int ADD_ID(int *S_ID);

int DELETE_ID(int *S_ID);

int INSERT_ID(int *S_ID);

int SEARCH_ID(const int *S_ID);

int UPDATE_ID(int *S_ID);

int DISPLAY_IDs(int *S_ID);

int count = 0;

int findLoc(const int *S_ID, int number) {
    for (int i = 0; i < count; i++) {
        if (S_ID[i] == number)
            return (i);
    }
    return (-1); // not found
}

int ADD_ID(int *S_ID) {
    printf("Enter the Student ID : ");
    scanf("%d", &S_ID[count]);
    count++;

    return *S_ID;
}

int DELETE_ID(int *S_ID) {
    int DELNUM;
    printf("Please enter the student number to be deleted : ");
    scanf("%d", &DELNUM);

    int loc = findLoc(S_ID, DELNUM);
    if (loc != -1) {
        for (int i = loc + 1; i < count; ++i)
            S_ID[i - 1] = S_ID[i];
        count--;
        return *S_ID;
    } else
        printf("Error -- ID not found");
    return *S_ID;
}

int INSERT_ID(int *S_ID) {
    int ID;
    int num;
    printf("Please enter the student number : "); //ID 넣을 아이디
    scanf("%d", &ID);
    printf("Please enter the index : "); // INDEX // 인덱스 번호
    scanf("%d", &num);

    for (int i = count; i > num; i--) {
        S_ID[i] = S_ID[i - 1];
    }
    count++;
    S_ID[count] = S_ID[count - 1];
    S_ID[num] = ID;
    return *S_ID;
}

int SEARCH_ID(const int *S_ID) {
    int ID;
    printf("Please enter the student number : ");
    scanf("%d", &ID);

    for (int i = 0; i < count; i++) {
        if (S_ID[i] == ID) {
            printf("Existing student number | INDEX == %d\n", i);
            return (0);
        }
    }
    printf("Error -- ID not found");
    return (-1); // not found
}

int UPDATE_ID(int *S_ID) {
    int ID, ID2;
    printf("Please enter the student number to be changed : ");
    scanf("%d", &ID);
    printf("Please enter the student number to be updated : ");
    scanf("%d", &ID2);

    int loc = findLoc(S_ID, ID);

    if (loc != -1) {
        S_ID[loc] = ID2;
        return *S_ID;
    } else
        printf("***Error -- ID not found");
    return *S_ID;
}

int DISPLAY_IDs(int *S_ID) {
    printf("Index\tNumber\n");
    for (int i = 0; i < count; ++i) {
        printf("%d\t%d\n", i, S_ID[i]);
    }
}

int main(void) {

    int num;
    int Student_ID[10000];

    while (1) {
        printf("1: ADD_ID\n2: DELETE_ID\n3: INSERT_ID\n4: SEARCH_ID\n5: UPDATE_ID\n6: DISPLAY_IDs\n7: Exit Program\nEnter the number : ");
        scanf("%d", &num);

        switch (num) {
            case 1: {
                ADD_ID(Student_ID);
                printf("===============================================================\n");
                break;
            }

            case 2: {
                DELETE_ID(Student_ID);
                printf("===============================================================\n");
                break;
            }

            case 3: {
                INSERT_ID(Student_ID);
                printf("===============================================================\n");
                break;
            }

            case 4: {
                SEARCH_ID(Student_ID);
                printf("===============================================================\n");
                break;
            }

            case 5: {
                UPDATE_ID(Student_ID);
                printf("===============================================================\n");
                break;
            }

            case 6: {
                DISPLAY_IDs(Student_ID);
                printf("===============================================================\n");
                break;
            }

            case 7:
                exit(0);
                break;
            default:
                printf("Enter a number from 1 to 7.\n");
                printf("===============================================================\n");
                break;
        }
    }
}