#include <stdio.h>
#include <stdbool.h>

/*
        Primer 1:
        3 4 9 1     n = 3453
        5 3 4 4
        2 5 3 5
        7 4 1 6
        Ispis:
        2
 */

bool matrixEqualsN(int arr[5], int dim, int matrix[dim][dim]){

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if((i == 0 && j == 1) || (i == 1 && j == 1)) {
                if (matrix[i][j] != arr[i + j + 1]) {
                    return false;
                }
            } else {
                if (matrix[i][j] != arr[i + j]) {
                    return false;
                }
            }
        }
    }
    return true;
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

    int n;
    printf("enter the number: ");
    scanf("%d", &n);

    int cifre[20];
    int k = 0;
    while(n > 0){
        cifre[k++] = n%10;
        n /= 10;
    }

    int smallMat[2][2];
    int matCount = 0;
    for (int i = 0; i < dim-1; i++) {
        for (int j = 0; j < dim-1; j++) {
            for (int x = i, c1 = 0; x < i+2; x++, c1++) {
                for (int y = j, c2 = 0; y < j+2; y++, c2++) {
                    smallMat[c1][c2] = matrix[x][y]; /// nije ovde ij
                    //printf("matrixij elements: %d\n", matrix[i][j]);
                    //printf("matrixxy elements: %d\n", matrix[x][y]);
                }
            }
            if(matrixEqualsN(cifre, 2, smallMat)){
                matCount++;
            }
        }
    }

    printf("Number of matrix is: %d\n", matCount);


    return 0;
}