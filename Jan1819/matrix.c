#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
 . (12p) Napisati program koji učitava dve kvadratne matrice celih brojeva od kojih je dimenzija prve
        matrice stepen nekog prirodnog broja (4,9,16,..), a dimenzija druge jednaka korenu dimenzije prve
        matrice i proverava da li u prvoj matrici postoji vrsta i/ili kolona koja sadrži iste elemente kao druga
        matrica (zanemariti broj pojavljivanja elemenata). Ispisati redne brojeve vrsta i kolona prve matrice
        za koje ovo važi.
        Primer:
        1. matrica    2. matrica
        1 1 9 7         1 9
        1 5 9 1         7 9
        1 9 7 9
        1 15 6 9
        Ispis:
        vrsta 0
        vrsta 2
        kolona 3
 */

int found = false;
int rowCount = 0;

void printRow(int row[], int size, int mat[size][size]){

    int counter = 0;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if(mat[i][j] == row[counter]){
                counter++;
                if(counter == (int)sqrt(size)){
                    rowCount++;
                    found = true;
                    printf("%d", i);
                    return;
                }
            }
        }
        counter = 0;
    }
}

void transpose(int n, int matrix[n][n], int trans[n][n]){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            trans[i][j] = matrix[j][i];
        }
    }
}

int main(){

    int n;
    printf("Insert matrix dim: ");
    scanf("%d", &n); /// ovde treba da se ishendla sta ako broj nije potpun kvadrat

    int bigMat[n][n];

    printf("Insert big matrix elements: ");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; ++j) {
            scanf("%d", &bigMat[i][j]);
        }
    }

    int smallDim = sqrt(n); /// it will always be an int, so it doesn't matter
    int smallMat[smallDim][smallDim];

    printf("Insert small matrix elements: ");
    for (int i = 0; i < smallDim; i++){
        for (int j = 0; j < smallDim; j++) {
            scanf("%d", &smallMat[i][j]);
        }
    }

    for(int i = 0; i < smallDim; i++) {
        if(i > 0 && found == false){
            break;
        }
        printf("row no is: ");
        printRow(smallMat[i], n, bigMat);
        printf("\n");
    }
    rowCount = 0;

    int transMat[n][n];
    transpose(n, bigMat, transMat);
    int smalltrans[smallDim][smallDim];
    transpose(smallDim, smallMat, smalltrans);

    for(int i = 0; i < smallDim; i++) {
        found = false;
        rowCount = 0;
        if(i > 0 && found == false){
            break;
        }
        printf("col no is: ");
        printRow(smalltrans[i], n, transMat);
        printf("\n");
    }




    return 0;
}