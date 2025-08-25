#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   // Hash table size

struct Node {
    int data;
    struct Node* next;
};

int hash(int key) {
    return key % SIZE;
}

void insert(struct Node* hashTable[], int key) {
    int index = hash(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int search(struct Node* hashTable[], int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key)
            return 1; 
        temp = temp->next;
    }
    return 0; 
}

void display(struct Node* hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main() {
    struct Node* hashTable[SIZE] = {NULL};

    insert(hashTable, 12);
    insert(hashTable, 22);
    insert(hashTable, 42);
    insert(hashTable, 52);
    insert(hashTable, 25);

    printf("Hash Table:\n");
    display(hashTable);

    int key = 42;
    if (search(hashTable, key))
        printf("\n%d found in hash table.\n", key);
    else
        printf("\n%d not found in hash table.\n", key);

    return 0;
}
