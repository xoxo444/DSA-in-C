#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_STRING 100

typedef struct node {
    char data[MAX_STRING];
    struct node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hash(const char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  

    return hash % TABLE_SIZE;
}

void insert(const char* str) {
    unsigned int index = hash(str);
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(const char* str) {
    unsigned int index = hash(str);
    Node* current = hashTable[index];
    while (current) {
        if (strcmp(current->data, str) == 0)
            return 1;  
        current = current->next;
    }
    return 0; 
}

void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* current = hashTable[i];
        while (current) {
            printf("%s -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}


int main() {
    insert("apple");
    insert("banana");
    insert("orange");
    insert("grape");

    printTable();

    printf("Searching for 'banana': %s\n", search("banana") ? "Found" : "Not Found");
    printf("Searching for 'kiwi': %s\n", search("kiwi") ? "Found" : "Not Found");

    freeTable();
    return 0;
}
