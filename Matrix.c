#include <stdio.h>

#define SIZE 10

// Function to input matrix
void inputMatrix(int matrix[SIZE][SIZE], int rows, int cols) {
    int i, j;

    printf("Enter matrix elements:\n");

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[SIZE][SIZE], int rows, int cols) {
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE],
               int Result[SIZE][SIZE], int rows, int cols) {

    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrix(int A[SIZE][SIZE], int B[SIZE][SIZE],
                    int Result[SIZE][SIZE],
                    int r1, int c1, int c2) {

    int i, j, k;

    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {

            Result[i][j] = 0;

            for(k = 0; k < c1; k++) {
                Result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {

    int A[SIZE][SIZE], B[SIZE][SIZE], Result[SIZE][SIZE];
    int r1, c1, r2, c2;
    int choice;

    printf("===== MATRIX OPERATIONS =====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Matrix Addition
    if(choice == 1) {

        printf("Enter rows and columns of Matrix A: ");
        scanf("%d%d", &r1, &c1);

        printf("Enter rows and columns of Matrix B: ");
        scanf("%d%d", &r2, &c2);

        if(r1 != r2 || c1 != c2) {
            printf("Matrix addition not possible!\n");
            return 0;
        }

        printf("Enter Matrix A:\n");
        inputMatrix(A, r1, c1);

        printf("Enter Matrix B:\n");
        inputMatrix(B, r2, c2);

        addMatrix(A, B, Result, r1, c1);

        printf("\nResultant Matrix after Addition:\n");
        displayMatrix(Result, r1, c1);
    }

    // Matrix Multiplication
    else if(choice == 2) {

        printf("Enter rows and columns of Matrix A: ");
        scanf("%d%d", &r1, &c1);

        printf("Enter rows and columns of Matrix B: ");
        scanf("%d%d", &r2, &c2);

        if(c1 != r2) {
            printf("Matrix multiplication not possible!\n");
            return 0;
        }

        printf("Enter Matrix A:\n");
        inputMatrix(A, r1, c1);

        printf("Enter Matrix B:\n");
        inputMatrix(B, r2, c2);

        multiplyMatrix(A, B, Result, r1, c1, c2);

        printf("\nResultant Matrix after Multiplication:\n");
        displayMatrix(Result, r1, c2);
    }

    else {
        printf("Invalid Choice!\n");
    }

    return 0;
}