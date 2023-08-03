#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

/*
      (13) Napisati program koji učitava duži string koji se sastoji od reči razdvojenih spejsom i jedan
            kraci string koji ne sadrži spejs. Program treba da iz dužeg stringa izbaci sve reči koje sadrže bar dva
            odvojena pojavljivanja kradeg stringa. Pri tome zanemariti veličinu slova. Rezultujudi string ispisati na
            sistemski izlaz.
            Primer:
            prvi string: Jaja pojavljivanja boja jabuka
            drugi string: ja
            Ispis: boja jabuka
 */


char* extract_substring(const char* str, int start_index, int end_index) {
    int len = strlen(str);
    if (start_index < 0 || start_index >= len || end_index < 0 || end_index >= len || start_index > end_index) {
        return NULL; // Invalid input indices
    }

    int substring_length = end_index - start_index + 1;
    char* result = (char*)malloc((substring_length + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    strncpy(result, str + start_index, substring_length);
    result[substring_length] = '\0'; // Null-terminate the substring

    return result;
}

int main() {

    char big[100];
    gets(big);

    char small[20];
    gets(small);

    char* word;
    char* words[50];
    int i = 0;

    word = strtok(big, " ");
    while(word != NULL){
        words[i] = (char*)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(words[i++], word);
        word = strtok(NULL, " ");
    }

    int count = 0;

    printf("duzina niza: %d\n", i);
    for(int j = 0; j < i; j++){
        //puts(words[j]);
        for(int k = 0, l = k+1; l < strlen(words[j]); l++){
            char* current = extract_substring(words[j], k , l);
            if(strlen(current) == strlen(small)){
                k++;
                if(strcmp(current, small) == 0){
                    count++;
                }

            }
        }
        if(count < 2){
            puts(words[j]);
        }
        count = 0;
    }


    return 0;
}