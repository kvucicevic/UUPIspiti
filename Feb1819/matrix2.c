#include <stdio.h>
#include <stdbool.h>

/*
    1. (12p) Napisati program koji učitava ceo broj n i matricu koja sadrži cifre od 0 do 9 i proverava da li
            glavna ili sporedna dijagonala sadrže sve cifre broja n u bilo kom redosledu i sa tačnim brojem
            pojavljivanja cifara. Ispisati nazive dijagonala (glavna, sporedna) za koje ovo važi.

            Primer:
            1 1 9 1     n = 477
            2 7 4 4
            2 3 4 2
            7 4 1 7

            Ispis:
            glavna

 */

int otherHas(int dim, int matrix[dim][dim], int arr[20]){

    bool used[] = {false};
    int count = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if((i+j) == dim-1) {
                for(int k = 0; k < dim; k++){
                    if(arr[k] == matrix[i][j] && used[k] == false){
                        used[k] = true;
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int occurancesInMain(int dim, int matrix[dim][dim], int arr[20]){

    bool used[] = {false};
    int count = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if(i == j) {
                for(int k = 0; k < dim; k++){
                    if(arr[k] == matrix[i][j] && used[k] == false){
                        used[k] = true;
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int countElements(int n, int arr[n]){
    int count = 0;
    while(arr[count] != NULL){
        count++;
    }
    return count;
}

int main()
{

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
    int i = 0;
    while(n > 0){
        cifre[i++] = n%10;
        n /= 10;
    }
    int len = countElements(20, cifre);

    if(occurancesInMain(dim, matrix, cifre) == len){
        printf("APPEARS IN MAIN");
    } else if (otherHas(dim, matrix, cifre) == len){
        printf("ALTERNATIVE DIAGONAL HAS IT");
    }


    return 0;
}