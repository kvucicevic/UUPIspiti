#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>


/*
    2. (12p) Napisati program koji učitava string sastavljen od reči koji sadrže mala slova
            abecede, a neke reči imaju i veliko X, koje ne može biti na kraju reči. Program treba da
            od unetog stringa napravi novi string u kom će se reči koje sadrže X promeniti tako što se
            ukrste stringovi pre i posle X. Ukrštanje se radi tako što se između svaka dva slova levo
            od X umetne jedno slovo iz podstringa desno od X, slova se umeću redom, kada se
            potroše sva slova iz desnog podstringa, kreće se od početka. Reči koje ne sadrže X
            prenose se u rezultujući string bez izmena.

            Primer:
            Unos: abcdeXhz zhj bbbbXac cccXs
            Ispis: ahbzchdze zhj babcbab cscsc
 */

char* rotateWord(char* word){
    char left[20];
    char right[20];
    int len = strlen(word);
    bool flag = false;
    int j = 0;
    int k = 0;
    char* res = (char*) malloc((strlen(word)+1)*sizeof(char));

    for(int i = 0; i < len; i++){
        if(word[i] == 'X') {
            flag = true;
        } else {
            if(flag == false){
                left[k++] = word[i];
                left[k] = '\0';
            } else {
                right[j++] = word[i];
                right[j] = '\0';
            }
        }
    }

    j = 0;
    k = 0;
    if(strlen(right) > strlen(left)){
        len = 2 * strlen(right)-1;
    } else {
        len = 2 * strlen(left)-1;
    }

    for(int i = 0; i < len; i++){
        if(k >= strlen(left)){
            k = 0;
        }

        if(j >= strlen(right)){
            j = 0;
        }

        if(i%2 == 0)
            res[i] = left[k++];
        else
            res[i] = right[j++];

    }
    res[len] = '\0';

    return res;
}

bool containsChar(char* word, char c){
    for(int i = 0; i < strlen(word); i++){
        if(word[i] == c)
            return true;
    }
    return false;
}

int main(){

    char inputStr[50];
    gets(inputStr);

    char* res = (char*) malloc((strlen(inputStr)+1)*sizeof(char));

    char* word;
    char* words[20];
    int i = 0; // size of words

    word = strtok(inputStr, " ");
    while(word != NULL){
        words[i] = (char*)malloc((strlen(word)+1)*sizeof(char));
        strcpy(words[i++], word);
        word = strtok(NULL, " ");
    }

    for(int j = 0; j < i; j++){
        if(containsChar(words[j], 'X')){
            strcat(res, rotateWord(words[j]));
        } else {
            strcat(res, words[j]);
        }
        strcat(res, " ");
    }

    puts(res);

    return 0;
}