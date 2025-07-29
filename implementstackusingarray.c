#include <stdio.h>
#define SIZE 100

int stack[SIZE], top = -1;

void push(int value) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
          
        }
        else if (choice == 2) {
            pop();
          
        }
        else if (choice == 3) {
            display();
          
        } 
        else if (choice == 4) {
            break;
          
        } 
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
