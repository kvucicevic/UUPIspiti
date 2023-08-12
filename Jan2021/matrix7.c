#include <stdio.h>
#include <stdbool.h>

/*
        1. (12p) Napisati program koji unutar date pravougane matrice pronalazi sve kvadratne
        matrice (dimenziije veće od 2x2) za koje važi da je zbir elemenata na ivicama (prva i
        poslednja vrsta i kolona) jednak zbiru unutrašnjih elemenata (svih elemenata koji se ne
        nalaze na ivici). Ispisati indekse gornjeg levog ugla i dimenziju svih ovakvih kvadratnih
        matrica. U primeru je označen jedan slučaj kvadrata koji zadovoljava traženi uslov.

        Primer:
        1 3 1 1 1 1
        2 1 3 1 9 1
        1 4 7 1 2 1
        2 8 7 1 1 1
        2 3 4 5 1 2

        Ispis: (1,0) dim 4x4
                (0,3) dim 3x3

14.00
 */

int findEgdeSum(int n, int matrix[n][n]){

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == 0 || i == n-1){
                sum += matrix[i][j];
            } else if(j == 0 || j == n-1){
                sum += matrix[i][j];
            }

        }
    }

    return sum;
}

int findInnerSum(int n, int matrix[n][n]){
    int sum = 0;
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

void generateSubmatrices(int n, int m, int bigMatrix[n][m], int size, int smallMatrix[size][size], int startRow, int startCol) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            smallMatrix[i][j] = bigMatrix[startRow + i][startCol + j];
        }
    }
}


int main(){

    int n, m;
    printf("Enter the matrix dim: ");
    scanf("%d %d", &n, &m);

    int matrix[n][m];
    printf("enter the matrix elements: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxSubmatrixSize = n < m ? n : m;

    int smallMat[50][50];
    for (int size = 2; size <= maxSubmatrixSize; size++) {
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= m - size; j++) {
                generateSubmatrices(n, m, matrix, size, smallMat, i, j);

                if (findEgdeSum(size, smallMat) ==
                    findInnerSum(size, smallMat)) {
                    printf("size is: %dx%d\n", size, size);
                    printf("LeftUp is: %d %d\n", i, j);
                }
            }

        }
    }


    return 0;
}