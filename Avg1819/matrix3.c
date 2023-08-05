#include <stdio.h>
#include <stdbool.h>

/*
    1. (12p) Napisati program koji učitava ceo broj n i matricu koja sadrži cifre od 0
            do 9. Program treba da proveri i ispiše koliko puta se cifre broja n pojavljuju
            redom u vrstama matrice čitajući sa desna na levo i uzimajući u obzir i prelazak u
            sledeću vrstu (na primer prve dve cifre broja mogu biti u jednoj vrsti a ostatak u
            sledećoj). Pojavljivanja cifara ne moraju biti odvojena, na primer može prva cifra
            jednog pojavljivanja da bude poslednja cifra prethodnog, kao u primeru.

            Primer:
            3 1 9 1     n = 3453
            4 3 5 4
            2 3 3 5
            7 4 1 7

            Ispis:
            2

 */


int countElements(const int arr[]){
    int count = 0;
    while(arr[count]){
        count++;
    }
    return count;
}

bool contains(int arr[], int element){
    int len = countElements(arr);
    for(int i = 0; i < len-1; i++){
        if(element == arr[i]){
            return true;
        }
    }
    return false;
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
    int len = countElements(cifre);


    int count = 0;
    int occurances = 0;
    bool flag = false;
    for(int j = dim-1; j >= 0; j--){
        for(int k = dim-1; k >= 0; k--){
            if(contains(cifre, matrix[j][k])){
                count++;
            } else {
                count = 0;
                flag = false;
            }

            if(count > 1 && flag == false){
                occurances++;
                flag = true;
            }
        }
    }

    printf("Occurances: %d\n", occurances);


    return 0;
}