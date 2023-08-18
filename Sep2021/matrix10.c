#include <stdio.h>
#include <stdbool.h>

/*
    1. (13p) Napisati program koji učitava matricu i ceo broj n i u učitanoj matrici
            pronalazi najveći pravougaonik koji na ivicama (prva i poslednja kolona i vrsta)
            ne sadrži ni jednu cifru broja n. Ukoliko takav pravougaonik postoji ispisati vrstu i
            kolonu gornjeg levog temena pronađenog pravougaonika u matrici i dimenziju,
            ako ne postoji ispisati poruku.
            Primer:
            n = 97884
            3 8 3 1 2 3
            2 9 2 9 5 6
            1 9 3 1 6 8
            7 6 1 6 6 9
 */

bool arrayContains(int num, int arr[]){
    for (int i = 0; arr[i]; i++) {
        if(arr[i] == num) {
            //printf("jednaki\n");
            printf("arri: %d\n", arr[i]);
            //printf("number: %d\n", num);
            return true;
        }
    }
    return false;
}

bool containsNumber(int row, int column, int matrix[row][column], int num){ // meni treba najveci prsten koji ne sadrzi

    int arr[10];
    int k = 0;
    while(num > 0){
        arr[k++] = num%10;
        num /= 10;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if(i == 0 || i == row-1 || j == 0 || j == column-1){
                if(arrayContains(matrix[i][j], arr)){
                    printf("matrixTren je: %d\n", matrix[i][j]);
                    //printf("j je %d\n", j);
                    return true;
                }
            }
        }
    }
    return false;
}

void printMat(int n, int m, int matrix[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generateSubmatrices(int n, int m, int bigMatrix[n][m], int height, int width, int smallMatrix[height][width], int startRow, int startCol) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            smallMatrix[i][j] = bigMatrix[startRow + i][startCol + j];
        }
    }
}

int main() {

    int num;
    printf("enter the number: ");
    scanf("%d", &num);

    int n, m;
    printf("enter matrix dim: ");
    scanf("%d %d", &n, &m);

    int matrix[n][n];
    printf("enter matrix elements: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int subMat[50][50];

    for(int height = 2; height <= n; height++){
        for(int width = 2; width <= m; width++){
            for(int i = 0; i < n-height; i++){
                for(int j = 0; j < m-width; j++){
                    generateSubmatrices(n, m, matrix, height, width, subMat, i, j);
                    /*
                    printMat(height, width, subMat);
                    printf("i is : %d\n", i);
                    printf("j is: %d\n", j);
                    printf("height is: %d\n", height);
                    printf("width is : %d\n", width);
                    printf("\n");
                     */
                    if(containsNumber(i, j, subMat, num)){
                        printMat(height, width, subMat);
                        printf("teme: (%d, %d)\n", i, j);
                        printf("dim is: %d x %d\n", height, width);
                        //printf("lolz");
                    }
                }
            }
        }
    }

    return 0;
}