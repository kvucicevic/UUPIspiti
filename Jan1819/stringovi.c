#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
        2. (13) Napisati program koji učitava string koji sadrži nizove u uglastim zagradama u kom su
        elementi razdvojeni zarezom, a nizovi su razdvojeni spejsom. Program treba da u unetom stringu
        pronađe i ispiše nizove koji imaju sve različite elemente.
        Primer:
        Unos: [a,b,c] [34,up,uup,34] [1,2] [1,2,1,4]
        Ispis: [a,b,c]
               [1,2]

 */

bool array_duplicates(const char* subStr){

    int len = strlen(subStr);

    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(subStr[i] == subStr[j]){
                //putchar(subStr[i]);
                return true;  // pronasao duplikat
            }
        }
    }
    return false; // nema duplikata
}


void print_substrings(const char* input){

    int len = strlen(input);
    bool inside_brackets = false;
    char substring[100];
    int sub_len = 0;

    for (int i = 0; i < len; i++) {
        if (input[i] == '[') {
            inside_brackets = true;
            sub_len = 0;
            continue;
        } else if (input[i] == ']') {
            inside_brackets = false;
            substring[sub_len] = '\0'; // Null-terminate the substring
            if (!array_duplicates(substring)) {
                printf("[%s]\n", substring);
            }
            continue;
        }

        if (inside_brackets && input[i] != ',') {
            substring[sub_len] = input[i];
            sub_len++;
        }
    }

}


int main() {

    char string[100];

    gets(string);

    print_substrings(string);

    return 0;
}
