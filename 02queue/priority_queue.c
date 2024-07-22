#include <stdio.h>
#include <stdlib.h>
// The priority is implemented using a min-heap data structure.
#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

void initialize(PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue* pq) {
    return pq->size == MAX_SIZE;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = pq->size - 1;
    while (i >= 0 && pq->elements[i].priority > priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }

    pq->elements[i + 1] = newElement;
    pq->size++;
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = pq->elements[0].data;

    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }

    pq->size--;

    return data;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Data: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
    }
}

int main() {
    PriorityQueue pq;
    initialize(&pq);

    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&pq, data, priority);
                break;
            case 2:
                data = dequeue(&pq);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}