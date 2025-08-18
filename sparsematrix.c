#include <stdio.h>

#define MAX 100

void convertToSparse(int rows, int cols, int matrix[rows][cols]) {
    int sparse[MAX][3];  
    int k = 1;  

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;

    printf("\nSparse Matrix Representation (Row Col Value):\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}


int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    convertToSparse(rows, cols, matrix);

    return 0;
}
