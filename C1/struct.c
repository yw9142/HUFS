#include <stdio.h>
struct person
{
    int age;
    float weight;
};
void display(struct person *p) {
    printf("Displaying:\n");
    printf("Age: %d\n", p->age);
    printf("weight: %f", p->weight);
}
int main()
{
    struct person* personPtr, person1;
    personPtr = &person1;
    printf("Enter age: ");
    scanf("%d", &person1.age);
    printf("Enter weight: ");
    scanf("%f", &person1.weight);
    display(personPtr);
    return 0;
}