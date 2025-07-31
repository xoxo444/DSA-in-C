#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow\n");
        return;
    }
  
    
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto stack\n", value);
}


void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Popped %d from stack\n", temp->data);
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
  
    struct Node* temp = top;
    printf("Stack contents:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
          
        } else if (choice == 2) {
            pop();
          
        } else if (choice == 3) {
            display();
          
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
          
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
