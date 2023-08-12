#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/*
    2. (12p) Napisati program koji na osnovu unetog stringa koji se sastoji od reči razdvojenih
        spejsom, pravi novi string tako što spaja reči koje počinju istim slovom. Reči se spajaju
        tako što se prvo ispiše njihovo isto početno slovo, a zatim redom ostatak svih reči bez
        prvog slova redosledom kako se reči pojavlju u unetom stringu. Reči koje ne mogu da se
        upare prepisuju se nepromenjene.

        Primer
        Unos: abc nkj amng nrp cbf ak
        Ispis: abcmngk nkjrp cbf
*/

bool newWordFlag = false;

void myStrcat(char* cpy, char* dest, char* source){
    int len = strlen(dest)+strlen(source);
    char res[20];
    bool flag = false;
    int j = 1;

    for(int i = 0; i < len; i++){
        if(dest[i] == '\0' && flag == false){
            flag = true;
            continue;
        }
        if(flag == false)
            res[i] = dest[i];
        if(flag == true){
            res[i-1] = source[j++];
            res[i] = '\0';
        }
    }

    // if we have new word we just add it to the result string
    // when we have another matching word, we override the old with a new one (strcpy)
    if(newWordFlag == true)
        strcat(cpy, res);
    else
        strcpy(cpy, res);
}

int main(){

    char inputStr[50];
    gets(inputStr);

    char* word;
    char* words[20];
    int i = 0;

    word = strtok(inputStr, " ");
    while(word != NULL){
        words[i] = (char*)malloc((strlen(word)+1)*sizeof(char));
        strcpy(words[i++], word);
        word = strtok(NULL, " ");
    }

    char res[50] = "";
    bool used[20] = {false};
    char currentWord[10];
    bool repeat = false;

    for(int j = 0; j < i-1; j++){
        if(used[j] == true)
            continue;
        for(int k = j+1; k < i; k++){
            if(used[k] == true)
                continue;
            // case when multiple words start on the same letter (currentWord and repeat flag)
            // ex. after haveing abc+amng = abcmng   we should add on the result string ak
            if(repeat == true){
                if(currentWord[0] == words[k][0]){
                    used[k] = true;
                    myStrcat(res, currentWord, words[k]);
                    strcpy(currentWord, res);
                    continue;
                }
            }
            // case when we have just 2 words starting on the same letter (or first matching of the words with multiple matches)
            // ex. adding abc+amng and nkj + nrp
            if(words[j][0] == words[k][0] && repeat == false){
                repeat = true;
                used[k] = true;
                myStrcat(res, words[j], words[k]);
                strcpy(currentWord, res);
            }
            newWordFlag = false;
        }
        strcat(res, " ");
        repeat = false;
        used[j] = true;
        newWordFlag = true;
    }
    //res[strlen(res)-1] = '\0';
    puts(res);

    return 0;
}