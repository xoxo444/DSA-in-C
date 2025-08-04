#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}


void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
      
    } else {
        struct Node* tail = head->prev;
        tail->prev->next = head;
        head->prev = tail->prev;
        free(tail);
    }
}


void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
          
        } else if (choice == 2) {
            deleteEnd();
          
        } else if (choice == 3) {
            display();
          
        } else if (choice == 4) {
            break;
          
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
