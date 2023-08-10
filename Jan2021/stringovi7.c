#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/*
    2. (13p) Napisati program koji od dva data stringa P i S pravi treći tako što sve
            podstringove stringa P koji se nalaze u zagradi prepisuje u treći string
            samo ako sadrže
            bar dva karaktera koja se nalaze u S i svi karakteri u zagradi koji se nalaze i u S su
            pojavljuju u istom redosledu kao karakteri u strigu S. String S sadrži sve različite
            karaktere. Podstring u zagradi može da sadrži i karaktere kojih nema u S ili da se
            karakteri ponavljaju, bitno je da redosled za sve karaktere bude isti kao u S. Ostali
            karakteri, izvan zagrada i u zagradi za koje ne važi pravilo ne pripisuju se u rezultujući
            string.
            Primer
            Unos:   P: (dfhhj)fg(adbjbdnc)agh(haj)gh(akjh)
                    S: dhj
            Ispis: dfhhj haj
 */
//11.40 - 12.25

bool isSameOrder(char* big, char* small){

    int count = 0;
    for(int k = 0; k < strlen(small); k++) {
        for (int i = 0, j = k; i < strlen(big); i++) {
            if (big[i] == small[j]) {
                count++;
                j++;
            }
            if(count > 1){
                return true;
            }
        }
        count = 0;
    }

    return false;
}

int main(){

    char inputP[40];
    char inputS[20];
    gets(inputP);
    gets(inputS);


    char word[10];
    int j = 0;
    char* words[20];
    int k = 0;
    bool flag = false;
    for(int i = 0; i < strlen(inputP); i++){
        if(inputP[i] == '('){
            flag = true;
            continue;
        }
        if(inputP[i] == ')'){
            flag = false;
            word[j] = '\0';
            words[k] = (char*)malloc((strlen(word)+1)*sizeof(char));
            strcpy(words[k++], word);
            memset(word,0,strlen(word));
            j = 0;
        }
        if(flag == true){
            word[j++] = inputP[i];
        }
    }

    for(int i = 0; i < k; i++){
        if(isSameOrder(words[i], inputS))
            puts(words[i]);
    }



    return 0;
}