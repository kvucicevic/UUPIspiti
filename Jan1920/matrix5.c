#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/*
    1. (13p) Napisati program koji učitava kvadratnu matricu sastavljenu od nula i jedinica i
            brojeve n i m koji su manji ili jednaki dimenziji matrice. Program treba da u unetoj matrici
            pronađe sve podmatrice sa n vrsta i m kolona koje se sastoje samo od nula ili samo od
            jedinica. Potrebno je ispisati broj takvih podmatrica i indekse vrste i kolone gornjeg levog
            elementa svih pronađenih podmatrica.

            Primer:
            n = 3, m = 2
            1 1 1 0 1 0
            1 0 0 0 1 1
            1 1 1 1 0 1
            0 1 1 1 0 0
            1 1 1 1 0 0
            1 1 1 0 0 0
            ispis: broj podmatrica 4, (2,1) (2,2) (3,1) (3,4)
 */

bool matrixSameElements(int n, int m, int matrix[n][m]){
    int prev = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 0 && j == 0)
                continue;

            if(matrix[i][j] != prev)
                return false;
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

    int n, m;
    printf("enter small matrix dimension: ");
    scanf("%d %d", &n, &m);

    int indices[dim][3];
    int idx = 0;
    int count = 0;

    int smallMat[n][m];

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            for (int x = i, c1 = 0; x < i+n; x++, c1++) {
                for (int y = j, c2 = 0; y < j+m; y++, c2++) {
                    smallMat[c1][c2] = matrix[x][y];
                }
            }
            if(matrixSameElements(n, m, smallMat)){
                count++;
                indices[idx][0] = i;
                indices[idx++][1] = j;
            }
        }
    }

    printf("No of matrices: %d\t", count);
    printf("On indices: ");
    for (int i = 0; i < count; i++) {
        printf(" (");
        for (int j = 0; j < 2; j++) {
            printf(" %d ", indices[i][j]);
        }
        printf(") ");
    }



    return 0;
}