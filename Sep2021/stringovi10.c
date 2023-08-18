#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/*
    2. (12p) Napisati program koji učitava string koji sadrži mala slova i pravilno
            zatvorene dvostruke navodnike. Program treba da na osnovu učitanog stringa
            napravi novi koji iz navodnika izbacuje sva slova koja se pojavljuju samo jednom
            između navodnika.
            Primer
            Unos: acdj"knaan"nhn"prcf"ak"dfffs"j
            Ispis: acdj"naan"nhn""ak"fff"j

 */

bool notRepeating(char* word, char letter, int letterIdx){
    for(int i = 0; i < strlen(word); i++){
        if(i == letterIdx)
            continue;
        if(word[i] == letter){
            return true;
        }
    }
    return false;
}

void removeLetters(char* word){

    int len = (int) strlen(word);
    for(int i = 0; i < len; i++) {
        if (!notRepeating(word, word[i], i)) {
            if(word[i] == '\0' || word[i] == ' ')
                break;
            int currentIdx = i;
            for (int j = i; j < len; j++) {
                word[i++] = word[j+1];
                word[i] = '\0';
            }
            i = currentIdx-1;
        }
    }

}

int main(){

    char inputStr[100];
    gets(inputStr);

    char* word;
    char* words[20];
    int i = 0;
    word = strtok(inputStr, "\"");
    while(word != NULL){
        words[i] = (char*) malloc((strlen(word)+1)* sizeof(char));
        strcpy(words[i++], word);
        word = strtok(NULL, "\"");
    }

    char res[50] = "";

    for(int j = 0; j < i; j++){
        if(j%2 == 1) {
            for (int k = 0; k < strlen(words[j]); k++) {
                removeLetters(words[j]);
            }
        }
        if(j != 0)
            strcat(res, "\"");
        strcat(res, words[j]);
    }

    puts(res);

    return 0;
}