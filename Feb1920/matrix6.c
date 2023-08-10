#include <stdio.h>
#include <math.h>

void removeEdges(int dim, int matrix[dim][dim]){

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if(i == 0 && j == 0 || i == dim-1 && j == 0 ||
                i == 0 && j == dim-1 || i == dim-1 && j == dim-1){
                matrix[i][j] = 0;
            }

            if(abs(i+j) == 2*(dim-1)-1 || abs(i+j) == 1 ||
                abs(i-j) == dim-2){
                matrix[i][j] = 0;
            }
        }
    }
}

int findMinInColumn(int dim, int matrix[dim][dim], int row){

    int min = 10;
    for (int i = 0; i < dim; i++) {
        if(matrix[i][row] == 0)
            continue;

        if(matrix[i][row] < min){
            min = matrix[i][row];
        }
    }
    return min;
}

int findMaxInColumn(int dim, int matrix[dim][dim], int row){

    int max = 0;
    for (int i = 0; i < dim; i++) {
        if(matrix[i][row] == 0)
            continue;

        if(matrix[i][row] > max){
            max = matrix[i][row];
        }
    }
    return max;
}


int main(){

    int dim;
    printf("enter matrix dimension: ");
    scanf("%d", &dim);
    int matrix[dim][dim];

    printf("enter matrix elements: ");
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    removeEdges(dim, matrix);

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if(i < dim/2 && matrix[i][j] == 0){
                matrix[i][j] = findMaxInColumn(dim, matrix, j);
            } else if (i > dim/2 && matrix[i][j] == 0){
                matrix[i][j] = findMinInColumn(dim, matrix, j);
            }
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}