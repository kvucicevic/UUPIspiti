#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/*
    2. (12p) Napisati program koji učitava string sastavljen od reči koje sadrže niz različitih
            malih slova abecede u tri vrste zagrada, (),{} i []. Program treba da napravi novi string
            na osnovu unetog u kom će slova u istim zagradama biti grupisana u jednu reč, pri čemu
            reč ne sme da sadrži ista slova. Redosled reči u rezultujućem stringu, kao i redosled
            slova u rečima unutar zagrada nisu bitni.

            Unos: [adf] {dfg} {fgh} {nm} (jkl) [df]
            Ispis: [adf] {dfghnm} (jkl)
 */

// {dfgfghnm}[adfdf](jkl)

bool falg1 = false; // {
bool falg2 = false; // [
bool falg3 = false; // (

char findMin(char* word, int startIndex){

    int len = strlen(word);
    char min = '0';

    for(int i = startIndex+1; i < len-1; i++){
        if(min > word[i]){
            min = word[i];
        }
    }
    return min;
}

int findMinIdx(char letter, char* word){

    int len = strlen(word);

    for(int i = 1; i < len-1; i++){
        if(letter == word[i]){
            return i;
        }
    }
    return -1;
}

char* sortWord(char* word){

    int len = strlen(word);
    char temp;

    for(int i = 1; i < len-1; i++){
        char min = findMin(word, i);
        int idx = findMinIdx(min, word);

        if(min == '0'){
            continue;
        }

        temp = word[i];
        word[i] = min;
        word[idx] = temp;

    }
    return word;
}

void removeBrackets(char* word){

    int len = strlen(word);
    char b1 = word[0];
    char b2 = word[len-1];

    for(int i = 1; i < len-1; i++) {
        if (word[i] == b1 || word[i] == b2) {
            word[i] = word[i + 1];
            word[i + 1] = ' ';
            i--;
        }
    }
    for(int i = 0, k = 0; word[i]; i++) {
        word[i] = word[i + k];
        if (word[i] == ' ') {
            k++;
            i--;
        }
    }

}

void removeDuplicates(char* word){

    int len = strlen(word);

    for(int i = 0; i < len; i++){
        for(int j = i+1; word[j] != '\0'; j++){
            if(word[j] == word[i]){
                for(int k = j; word[k] != '\0'; k++){
                    word[k] = word[k + 1];
                }
            }
        }
    }
}

int main(){

    char inputStr[50];
    gets(inputStr);

    char resultStr[50] = "";

    char str1[20] = "";
    int i1 = 0;
    char str2[20] = "";
    int i2 = 0;
    char str3[20] = "";
    int i3 = 0;

    for(int i = 0; i < strlen(inputStr); i++){

        if(inputStr[i] == '{'){
            falg1 = true;
        } else if(inputStr[i] == '['){
            falg2 = true;
        } else if(inputStr[i] == '('){
            falg3 = true;
        }

        if(falg1 == true){
            str1[i1++] = inputStr[i];
        } else if(falg2 == true){
            str2[i2++] = inputStr[i];
        } else if(falg3 == true){
            str3[i3++] = inputStr[i];
        }

        if(inputStr[i] == '}'){
            falg1 = false;
        } else if(inputStr[i] == ']'){
            falg2 = false;
        } else if(inputStr[i] == ')'){
            falg3 = false;
        }

    }

    removeBrackets(str1);
    removeDuplicates(str1);

    removeBrackets(str2);
    removeDuplicates(str2);

    removeBrackets(str3);
    removeDuplicates(str3);

    strcat(resultStr, sortWord(str1));
    strcat(resultStr, sortWord(str2));
    strcat(resultStr, sortWord(str3));

    puts(resultStr);

    return 0;
}