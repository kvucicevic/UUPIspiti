#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*
    1. (13p) Napisati program koji učitava matricu dimenzija NxN i ispisuje njenu najmanju podmatricu
                koja sadrži najveći i najmanji prost broj iz originalne matrice.

                Primer (n = 6): Ulaz: 8 7 2 6 3 9  Izlaz: 4 7 2
                                      3 9 5 8 4 1        12 9 4
                                      4 7 2 9 5 3         8 6 3
                                     12 9 4 10 7 15      11 6 8
                                      8 6 3 10 4 5
                                     11 6 8 10 5 3

                                     8 7 2 6 3 9 3 9 5 8 4 1 4 7 2 9 5 3 12 9 4 10 7 15 8 6 3 10 4 5 11 6 8 10 5 3

                Primer (n = 7): Ulaz: 9 5 6 10 3 7 5   Izlaz: 13 1
                                      4 10 7 7 6 12 1          8 7
                                      7 13 1 8 6 5 4          10 3
                                      12 8 7 9 1 13 6
                                      4 10 3 9 12 8 7
                                      9 6 5 11 4 8 10
                                      3 6 8 16 5 4 11
 */

bool isPrime(int n){

    if(n == 1 || n == 0)
        return false;

    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int highestPrime(int n, int matrix[n][n]){
    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isPrime(matrix[i][j])) {
                if (matrix[i][j] > max)
                    max = matrix[i][j];
            }
        }
    }
    return max;
}

int smallestPrime(int n, int matrix[n][n]){
    int min = 100;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isPrime(matrix[i][j])) {
                if (matrix[i][j] < min)
                    min = matrix[i][j];
            }
        }
    }
    return min;
}

void printMat(int x, int x1, int y, int y1, int n, int matrix[n][n]){

    if(x > x1 && y > y1){
        for(int i = x1; i <= x; i++) {
            for (int j = y1; j <= y; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        return;
    }

    if(x > x1 && y < y1){
        for(int i = x1; i <= x; i++) {
            for (int j = y; j <= y1; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        return;
    }

    if(x < x1 && y > y1){
        for(int i = x; i <= x1; i++) {
            for (int j = y; j <= y; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        return;
    }

    if(x < x1 && y < y1){
        for(int i = x; i <= x1; i++) {
            for (int j = y; j <= y1; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        return;
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

    int max = highestPrime(n, matrix);
    int maxIdx[3] = {0, 0};
    int min = smallestPrime(n, matrix);
    int minIdx[3] = {0, 0};
    bool flag1 = false;
    bool flag2 = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(matrix[i][j] == max){
                if(flag1 == false){
                    maxIdx[0] = i;
                    maxIdx[1] = j;
                    flag1 = true;
                } else {
                    if (abs(maxIdx[0] - minIdx[0]) <= abs(i - minIdx[0]) &&
                        abs(maxIdx[1] - minIdx[1]) <= abs(j - minIdx[1])) {
                        maxIdx[0] = i;       // 5
                        maxIdx[1] = j;       // 0
                    }
                }
            }
            else if(matrix[i][j] == min){
                if(flag2 == false){
                    minIdx[0] = i;
                    minIdx[1] = j;
                    flag2 = true;
                } else {
                    if (abs(maxIdx[0] - minIdx[0]) <= abs(i - maxIdx[0]) &&
                        abs(maxIdx[1] - minIdx[1]) <= abs(j - maxIdx[1])) {
                        minIdx[0] = i;     // 0     2
                        minIdx[1] = j;     // 2     2
                    }
                }
            }
        }
    }

    printMat(maxIdx[0], minIdx[0], maxIdx[1],minIdx[1], n, matrix);

    return 0;
}