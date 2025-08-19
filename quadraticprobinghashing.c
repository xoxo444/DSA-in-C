#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_STRING 100

typedef struct {
    char key[MAX_STRING];
    int isOccupied;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash + *str) % TABLE_SIZE;
        str++;
    }
    return hash;
}

void insert(const char* key) {
    unsigned int index = hash(key);
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int newIndex = (index + i * i) % TABLE_SIZE;
        if (!hashTable[newIndex].isOccupied) {
            strcpy(hashTable[newIndex].key, key);
            hashTable[newIndex].isOccupied = 1;
            printf("Inserted \"%s\" at index %d\n", key, newIndex);
            return;
        } else if (strcmp(hashTable[newIndex].key, key) == 0) {
            printf("\"%s\" already exists at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Hash table is full, cannot insert \"%s\"\n", key);
}


int search(const char* key) {
    unsigned int index = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        unsigned int newIndex = (index + i * i) % TABLE_SIZE;

        if (!hashTable[newIndex].isOccupied)
            return 0; 

        if (strcmp(hashTable[newIndex].key, key) == 0)
            return 1;
    }

    return 0; 
}


void printTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isOccupied)
            printf("[%d]: %s\n", i, hashTable[i].key);
        else
            printf("[%d]: <empty>\n", i);
    }
}


int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = 0;
    }

    insert("apple");
    insert("banana");
    insert("grape");
    insert("orange");
    insert("melon");
    insert("peach");
    insert("cherry");

    printTable();

    printf("\nSearching for \"banana\": %s\n", search("banana") ? "Found" : "Not Found");
    printf("Searching for \"kiwi\": %s\n", search("kiwi") ? "Found" : "Not Found");

    return 0;
}
