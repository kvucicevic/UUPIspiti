#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/*
   2. (13) Napisati program koji učitava string koji se sastoji od reči razdvojenih
            spejsom, reči mogu da sadrže slova engleske abecede i maksimalno jedan znak
            uzvika, a ne moraju ni jedan. Program treba da promeni uneti string (ili napravi
            novi na osnovu unetog) tako što će izbaciti reči koje nemaju uzvičnik, a u rečima
            koje imaju uzvičnik zameniti mesta podstringovima pre i posle uzvičnika.

            Primer: prvi string: obla!ci mesec su!nce

            Ispis: ci!obla nce!su
 */

bool containsEx(char* word){
    for(int i = 0; i < strlen(word); i++){
        if(word[i] == '!'){
            return true;
        }
    }
    return false;
}

char* rotateWord(char* word){

    char firstPart[10];
    char secondPart[10];
    bool flag = false;
    char* res = (char*)malloc((strlen(word) + 1) * sizeof(char));
    strcpy(res, "");

    for (int i = 0, j = 0; i < strlen(word); i++) {
        if (flag == false && word[i] != '!') {
            firstPart[i] = word[i];
        } else if (word[i] == '!'){
            firstPart[i] = '\0';
            flag = true;
        } else if(flag == true){
            secondPart[j++] = word[i];
        }
        if(i == strlen(word)-1){
            secondPart[strlen(secondPart)] = '\0';
        }
    }


    strcat(res, secondPart);
    strcat(res, "!");
    strcat(res, firstPart);

    return res;
}

int main(){

    char inputStr[50];
    gets(inputStr);

    char* word;
    char* words[20];
    word = strtok(inputStr, " ");
    int i = 0;
    while(word != NULL){
        words[i] = (char*)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(words[i++], word);
        if(containsEx(word) == true){
            puts(rotateWord(word));
        }
        word = strtok(NULL, " ");
    }



    return 0;
}