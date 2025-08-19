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
    unsigned int originalIndex = index;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hashTable[index].isOccupied) {
            strcpy(hashTable[index].key, key);
            hashTable[index].isOccupied = 1;
            printf("Inserted \"%s\" at index %d\n", key, index);
            return;
        } else if (strcmp(hashTable[index].key, key) == 0) {
            printf("\"%s\" already exists at index %d\n", key, index);
            return;
        }

        index = (originalIndex + i + 1) % TABLE_SIZE; 
    }

    printf("Hash table is full, cannot insert \"%s\"\n", key);
}


int search(const char* key) {
    unsigned int index = hash(key);
    unsigned int originalIndex = index;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hashTable[index].isOccupied)
            return 0; 
        if (strcmp(hashTable[index].key, key) == 0)
            return 1; 

        index = (originalIndex + i + 1) % TABLE_SIZE;
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

    printTable();

    printf("\nSearching for \"banana\": %s\n", search("banana") ? "Found" : "Not Found");
    printf("Searching for \"kiwi\": %s\n", search("kiwi") ? "Found" : "Not Found");

    return 0;
}
