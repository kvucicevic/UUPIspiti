#include <stdio.h>
#include <stdbool.h>

/*
    1.(13p) Na osnovu date kvadratne matrice napraviti novu matricu formirajući njene
            prstenove na osnovu prstenova polazne matrice. Prsten nove matrice treba da sadrži
            najveći element istog prstena originalne matrice.
            Primer:
            3 4 3 4 7 5  Rezultat:  7 7 7 7 7 7
            2 4 2 5 5 4             7 6 6 6 6 7
            1 3 4 1 6 1             7 6 4 4 6 7
            1 2 3 1 5 2             7 6 4 4 6 7
            2 3 1 4 5 5             7 6 6 6 6 7
            1 4 5 1 2 3             7 7 7 7 7 7
 */

int findMaxInRing(int n, int matrix[n][n], int level){

    int max = 0;

    for (int i = level; i < n-level; i++) {
        for (int j = level; j < n-level; j++) {
            if(i == level || i == n-level-1 || j == level || j == n-level-1){
                if(matrix[i][j] > max){
                    max = matrix[i][j];
                }
            }
        }
    }
    return max;
}

void fillTheRing(int n, int matrix[n][n], int level){

    int max = findMaxInRing(n, matrix, level);

    for (int i = level; i < n-level; i++) {
        for (int j = level; j < n-level; j++) {
            if(i == level || i == n-level-1 || j == level || j == n-level-1){
                matrix[i][j] = max;
            }
        }
    }
}

void printMat(int n, int matrix[n][n]){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(){

    int n;
    printf("enter matrix dim: ");
    scanf("%d", &n);

    int matrix[n][n];
    printf("enter matrix elements: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < n/2; i++){
        fillTheRing(n, matrix, i);
    }

    printMat(n, matrix);

    return 0;
}
