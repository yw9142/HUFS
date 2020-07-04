#include <stdio.h>
#include <string.h>

typedef struct Student_information {
    char IDs[100];
    char Name[100];
    char Phone_number[100];
    char email_address[100];
} SI;

SI Students[100];

int main(void) {

    FILE *fileopen = NULL;
//    char filename[100];
//    scanf("%s", &filename);

    int count = 0;

    fileopen = fopen("YonghunPark.txt", "r");

    if (fileopen != NULL) {
        char buffer[100];
        while (!feof(fileopen)) { // End-of-File indicator
            SI Student;
            fgets(buffer, sizeof(buffer), fileopen);
            char *ptr = strtok(buffer, "\t");
            strcpy(Student.IDs, ptr);

            ptr = strtok(NULL, "\t");
            strcpy(Student.Name, ptr);

            ptr = strtok(NULL, "\t");
            strcpy(Student.Phone_number, ptr);

            ptr = strtok(NULL, "\t");
            strcpy(Student.email_address, ptr);


            Students[count++] = Student;
        }
        fclose(fileopen);
        for (int i = 0; i < count; i++) {
            printf("INDEX : %d,\tIDs : %s,\tName : %s,\tPhone Number : %s,\tEmail address : %s\n", i, Students[i].IDs,
                   Students[i].Name,
                   Students[i].Phone_number, Students[i].email_address);
        }
    } else {
        printf("Dont.\n");
    }
    return 0;
}
