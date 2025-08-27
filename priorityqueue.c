#include <stdio.h>
#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

Element pq[MAX];
int size = 0;


void enqueue(int data, int priority) {
    if(size == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    pq[size].data = data;
    pq[size].priority = priority;
    size++;
    printf("Inserted %d with priority %d\n", data, priority);
}

void dequeue() {
    if(size == 0) {
        printf("Queue Underflow!\n");
        return;
    }
    int i, highest = 0;
    for(i=1; i<size; i++) {
        if(pq[i].priority > pq[highest].priority) {
            highest = i;
        }
    }
    printf("Deleted element: %d with priority %d\n", pq[highest].data, pq[highest].priority);

    for(i=highest; i<size-1; i++) {
        pq[i] = pq[i+1];
    }
    size--;
}

void display() {
    if(size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue: \n");
    for(int i=0; i<size; i++) {
        printf("Data: %d  Priority: %d\n", pq[i].data, pq[i].priority);
    }
}


int main() {
    int choice, data, priority;
    while(1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
