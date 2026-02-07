#include <stdio.h>
#define SIZE 100
void addData(int arr[], int *n, int value);
void showData(int arr[], int n);
void deleteData(int arr[], int *n, int pos);
int main() {
    int arr[SIZE];
    int n = 0;  
    int choice, value, pos;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Add Data\n");
        printf("2. Show Data\n");
        printf("3. Delete Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n >= SIZE) {
                    printf("Array is full!\n");
                } else {
                    printf("Enter value to add: ");
                    scanf("%d", &value);
                    addData(arr, &n, value);
                }
                break;

            case 2:
                showData(arr, n);
                break;

            case 3:
                if (n == 0) {
                    printf("Array is empty, nothing to delete.\n");
                } else {
                    printf("Enter position to delete (1 to %d): ", n);
                    scanf("%d", &pos);
                    deleteData(arr, &n, pos);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

void addData(int arr[], int *n, int value) {
    arr[*n] = value;
    (*n)++;
    printf("Data added successfully.\n");
}


void showData(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void deleteData(int arr[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
    } else {
        for (int i = pos - 1; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Data deleted successfully.\n");
    }
}