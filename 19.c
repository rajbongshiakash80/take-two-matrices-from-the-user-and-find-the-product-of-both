#include <stdio.h>

#define MAX_ROWS1 10
#define MAX_COLS1 10
#define MAX_ROWS2 10
#define MAX_COLS2 10

// Function to input a matrix from the user
void inputMatrix(int matrix[MAX_ROWS1][MAX_COLS1], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_ROWS1][MAX_COLS1], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the product of two matrices
void multiplyMatrices(int matrix1[MAX_ROWS1][MAX_COLS1], int rows1, int cols1, int matrix2[MAX_ROWS2][MAX_COLS2], int rows2, int cols2, int result[MAX_ROWS1][MAX_COLS2]) {
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input from user: dimensions of the first matrix
    printf("Enter the number of rows for the first matrix (1-%d): ", MAX_ROWS1);
    scanf("%d", &rows1);
    printf("Enter the number of columns for the first matrix (1-%d): ", MAX_COLS1);
    scanf("%d", &cols1);

    if (rows1 <= 0 || rows1 > MAX_ROWS1 || cols1 <= 0 || cols1 > MAX_COLS1) {
        printf("Invalid dimensions for the first matrix.\n");
        return 1; // Return an error code
    }

    // Input from user: dimensions of the second matrix
    printf("Enter the number of rows for the second matrix (1-%d): ", MAX_ROWS2);
    scanf("%d", &rows2);
    printf("Enter the number of columns for the second matrix (1-%d): ", MAX_COLS2);
    scanf("%d", &cols2);

    if (rows2 <= 0 || rows2 > MAX_ROWS2 || cols2 <= 0 || cols2 > MAX_COLS2) {
        printf("Invalid dimensions for the second matrix.\n");
        return 1; // Return an error code
    }

    int matrix1[MAX_ROWS1][MAX_COLS1], matrix2[MAX_ROWS2][MAX_COLS2], product[MAX_ROWS1][MAX_COLS2];

    // Input first matrix from user
    printf("For the first matrix:\n");
    inputMatrix(matrix1, rows1, cols1);

    // Input second matrix from user
    printf("For the second matrix:\n");
    inputMatrix(matrix2, rows2, cols2);

    // Print original matrices
    printf("\nOriginal matrices:\n");
    printf("First matrix:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("\nSecond matrix:\n");
    printMatrix(matrix2, rows2, cols2);

    // Find and print the product of matrices
    multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, product);
    printf("\nProduct of matrices:\n");
    printMatrix(product, rows1, cols2);

    return 0; // Return success code
}
