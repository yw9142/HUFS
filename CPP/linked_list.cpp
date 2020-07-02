#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = top;
    top = node;
}

void Top() {
    if (top != NULL) {
        cout << "top : " << top->data;
    }
    else {
        cout << "top is NULL";
    }
    cout << endl;
}

void pop() {
    if (top == NULL) {
        cout << "stack underflow" << endl;
    }
    else {
        cout << "pop : " << top->data << endl;
        top = top->next;
    }
}

void display() {
    Node* ptr;
    if (top == NULL) {
        cout << "stack is empty";
    }
    else {
        ptr = top;
        cout << "stack element : ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

int main() {

    display();
    Top();

    push(1);
    push(2);
    push(3);

    display();
    Top();

    pop();
    pop();

    display();
    Top();

    push(5);

    display();
    Top();

    return 0;
}