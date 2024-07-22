#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is full\n");
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d enqueued\n", value);
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("%d dequeued\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1;
    }
}

void display() {
    if (rear == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}