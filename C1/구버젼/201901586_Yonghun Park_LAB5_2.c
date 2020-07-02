#include <stdio.h>
#include <stdlib.h>

int findLoc(int number);

void ADD_ID(void);

void DELETE_ID(void);

void INSERT_ID(void);

int SEARCH_ID(void);

void UPDATE_ID(void);

void DISPLAY_IDs(void);

Student_ID[10000];
count = 0;

int findLoc(int number) {
    for (int i = 0; i < count; i++) {
        if (Student_ID[i] == number)
            return (i);
    }
    return (-1); // not found
}

void ADD_ID(void) {
    printf("Enter the Student ID : ");
    scanf("%d", &Student_ID[count]);
    count++;
}

void DELETE_ID(void) {
    int DELNUM;
    printf("Please enter the student number to be deleted : ");
    scanf("%d", &DELNUM);

    int loc = findLoc(DELNUM);
    if (loc != -1) {
        for (int i = loc + 1; i < count; ++i)
            Student_ID[i - 1] = Student_ID[i];
        count--;
    } else
        printf("Error -- ID not found");
}

void INSERT_ID(void) {
    int ID;
    int num;
    printf("Please enter the student number : ");
    scanf("%d", &ID);
    printf("Please enter the index : ");
    scanf("%d", &num);

    Student_ID[num] = ID;
}

int SEARCH_ID(void) {
    int ID;
    printf("Please enter the student number : ");
    scanf("%d", &ID);

    for (int i = 0; i < count; i++) {
        if (Student_ID[i] == ID) {
            printf("Existing student number | INDEX == %d\n", i);
            return (0);
        }
    }
    printf("Error -- ID not found");
    return (-1); // not found
}

void UPDATE_ID(void) {
    int ID, ID2;
    printf("Please enter the student number to be changed : ");
    scanf("%d", &ID);
    printf("Please enter the student number to be updated : ");
    scanf("%d", &ID2);

    int loc = findLoc(ID);

    if (loc != -1) {
        Student_ID[loc] = ID2;
    } else
        printf("***Error -- ID not found");
}

void DISPLAY_IDs(void) {
    printf("Index\tNumber\n");
    for (int i = 0; i < count; ++i) {
        printf("%d\t%d\n", i, Student_ID[i]);
    }
}

int main(void) {

    int num;

    while (1) {
        printf("1: ADD_ID\n2: DELETE_ID\n3: INSERT_ID\n4: SEARCH_ID\n5: UPDATE_ID\n6: DISPLAY_IDs\n7: Exit Program\nEnter the number : ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                ADD_ID();
                printf("===============================================================\n");
                break;
            case 2:
                DELETE_ID();
                printf("===============================================================\n");
                break;
            case 3:
                INSERT_ID();
                printf("===============================================================\n");
                break;
            case 4:
                SEARCH_ID();
                printf("===============================================================\n");
                break;
            case 5:
                UPDATE_ID();
                printf("===============================================================\n");
                break;
            case 6:
                DISPLAY_IDs();
                printf("===============================================================\n");
                break;
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