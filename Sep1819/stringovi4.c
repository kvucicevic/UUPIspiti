#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

/*
    2. (13) Napisati program koji učitava string koji se sastoji od reči razdvojenih
            spejsom, u svakoj reči se nalaze do dva znaka zagrada koje mogu biti pravilne,
            prvo otvorena pa zatvorena, i nepravilne, tako da se pojavljuju na primer dve
            otvorene, samo otvorena ili samo zatvorena zagrada ili obe zagrade ali u
            pogrešnom redosledu. Program treba da promeni uneti string (ili napravi novi na
            osnovu unetog) tako što će izbaciti reči koje sadrže nepravilne zagrade, a u
            rečima u kojima su pravilne zagrade će obrnuti podstring u zagradi.

            Primer:
            Unos: obla(ci) m)e(sec su(nce) polj)e
            Ispis: obla(ic) su(ecn)
 */

bool pravilneZagrade(char* word){

    bool flag = false;

    for(int i = 0; i < strlen(word); i++){
        if(word[i] == '(' && flag == false){
            flag = true;
        } else if (word[i] == ')' && flag == false) {
            return false;
        } else if (word[i] == ')' && flag == true) {
            return true;
        }
    }
}

char* obrniPoIndexu(char* word, int startIdx, int endIdx){
    char* obrt;
    obrt = (char*)malloc((strlen(word)+1)* sizeof(char));
    for(int i = endIdx, j = 0; i > startIdx; i--, j++){
        obrt[j] = word[i];
    }
    return obrt;
}

char* obrniRec(char* word){

    char* obrnuta = "";
    obrnuta = (char*)malloc((strlen(word)+1)*sizeof(char));
    int startIdx;
    int endIdx;
    bool flag = false;

    for(int i = 0; i < strlen(word); i++){
        if(word[i] == '('){
            obrnuta[i] = word[i];
            startIdx = i;
            flag = true;
        } else if (word[i] == ')'){
            obrnuta[i] = word[i];
            endIdx = i;
            strcat(obrnuta, obrniPoIndexu(word, startIdx, endIdx-1));
            flag = false;
        }
        if(!flag) {
            obrnuta[i] = word[i];
        }
    }

    return obrnuta;
}

int main(){

    char inputStr[50];
    gets(inputStr);

    char* word;
    char* words[50];

    word = strtok(inputStr, " ");
    int i = 0;
    while(word != NULL){
        words[i] = (char*)malloc((strlen(word)+1)*sizeof(char));
        strcpy(words[i++], word);
        word = strtok(NULL, " ");
    }

    for(int j = 0; j < i; j++){
        if(pravilneZagrade(words[j])){
            puts(obrniRec(words[j]));
        }
    }

    return 0;
}