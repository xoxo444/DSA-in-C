#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, i, val, key;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in the tree.\n", key);
    } else {
        printf("Element %d not found in the tree.\n", key);
    }

    return 0;
}
