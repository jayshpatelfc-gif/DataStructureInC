#include <stdio.h>
#define MAX 5   // Maximum size of the circular queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the circular queue
void insert(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) { // First insertion
            front = rear = 0;
            queue[rear] = value;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0; // Wrap around
            queue[rear] = value;
        } else {
            rear++;
            queue[rear] = value;
        }
        printf("Inserted %d into the circular queue.\n", value);
    }
}

// Function to delete an element from the circular queue
void delete() {
    if (front == -1) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted %d from the circular queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else if (front == MAX - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }
    }
}

// Function to display the circular queue
void traverse() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
