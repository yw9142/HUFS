#include <stdio.h>
#include <stdlib.h>

struct student { // using struct
    int Book_ID;
    char Book_Name[1000];
    char Author_Name[1000];
    char Author_email[1000];
};

int main() {
    struct student stud1[100], stud2[100]; // struct
    FILE *fptr;
    int error = fopen_s(&fptr, "Helloworld.txt", "w"); // file open
    if (error != 0) { // if file open != 0 print error and exit function
        printf("Error! opening file");
        exit(1);
    }
    for (int i = 0; i < 3; i++) { // input data
        printf("Enter BOOK ID: ");
        scanf("%d", &stud1[i].Book_ID);
        fflush(stdin); // buffer clean
        printf("Enter BOOK NAME: ");
        scanf("%[^\n]s", stud1[i].Book_Name);
        fflush(stdin);
        printf("Enter Author Name: ");
        scanf("%[^\n]s", stud1[i].Author_Name);
        fflush(stdin);
        printf("Enter Author e-address: ");
        scanf("%[^\n]s", stud1[i].Author_email);
        getchar();
    }
    fwrite(stud1, sizeof(stud1), 1, fptr); // wrtie data at fptr
    fclose(fptr); // fptr close because Memory leak

    error = fopen_s(&fptr, "Helloworld.txt", "r"); // and re open the file
    if (error != 0) {
        printf("Error! opening file");
        exit(1);
    }

    fread(stud2, sizeof(stud2), 1, fptr); // and read the file
    for (int i = 0; i < 3; ++i) { // print data
        printf("%d %s %s %s\n", stud2[i].Book_ID, stud2[i].Book_Name, stud2[i].Author_Name, stud2[i].Author_email);
    }
    fclose(fptr); // close
}