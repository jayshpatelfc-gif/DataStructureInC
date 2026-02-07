#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 10
#define MAX_COLS 10
void displayMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    printf("\n--- Matrix ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void addElement(int matrix[][MAX_COLS], int *rows, int *cols, int row, int col, int value) {
    if (row < MAX_ROWS && col < MAX_COLS) {
        matrix[row][col] = value;
        if (row >= *rows) *rows = row + 1;
        if (col >= *cols) *cols = col + 1;
        printf("Element added successfully!\n");
    } else {
        printf("Invalid position!\n");
    }
}
void deleteElement(int matrix[][MAX_COLS], int row, int col) {
    matrix[row][col] = 0;
    printf("Element deleted successfully!\n");
}
void modifyElement(int matrix[][MAX_COLS], int row, int col, int newValue) {
    matrix[row][col] = newValue;
    printf("Element modified successfully!\n");
}
int main() {
    int matrix[MAX_ROWS][MAX_COLS] = {0};
    int rows = 0, cols = 0;
    int choice, row, col, value;

    while (1) {
        printf("\n--- 2D Array Operations ---\n");
        printf("1. Add Element\n2. Delete Element\n3. Modify Element\n4. Display Matrix\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter row, col, and value: ");
                scanf("%d %d %d", &row, &col, &value);
                addElement(matrix, &rows, &cols, row, col, value);
                break;
            case 2:
                printf("Enter row and col to delete: ");
                scanf("%d %d", &row, &col);
                deleteElement(matrix, row, col);
                break;
            case 3:
                printf("Enter row, col, and new value: ");
                scanf("%d %d %d", &row, &col, &value);
                modifyElement(matrix, row, col, value);
                break;
            case 4:
                displayMatrix(matrix, rows, cols);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}