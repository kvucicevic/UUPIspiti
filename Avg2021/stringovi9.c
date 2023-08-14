#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

/*
    2. (12p) Napisati program koji učitava dva stringa i nad prvim stringom vrši sledeće izmene: bez
            upotrebe pomoćnih stringova uklanja sve reči neparne dužine koje sadrže sva slova iz drugog
            stringa.
            Napomene: podrazumevati da su sve reči u prvom stringu razdvojene po jednim praznim
            karakterom i da drugi string ne sadrži više pojavljivanja istog slova, tj. da su sva slova u drugom
            stringu različita. Takođe, voditi računa da i u izmenjenom prvom stringu razmak između reči bude
            po jedan prazan karakter.
            Primeri: Prvi string: hazari azbuka pazar oranje zagor tor
                     Drugi string: zar
                     Izlaz: hazari azbuka oranje tor

                     Prvi string: vertikala tvor varivo ravnica verovanje
                     Drugi string: vir
                     Izlaz: tvor varivo verovanje
*/

int len;
bool isOdd(char word[100], int start, char* empty){

    if(start == strlen(word))
        return true;

    int count = 0;
    for(int i = start; word[i] != ' '; i++){
        if(word[i] == '\0')
            break;
        empty[count++] = word[i];
        empty[count] = '\0';
    }
    len = strlen(empty);

    if(len%2 == 1)
        return true;

    return false;

}

bool containsAllLetters(char word[100], char* small){

    int count = 0;
    int i;
    for(i = 0; small[i] != ' '; i++){
        if(small[i] == '\0')
            break;
        for(int j = 0; j < strlen(word); j++){
            if(small[i] == word[j]){
                count++;
                break;
            }
        }
    }
    if(count == i)
        return true;
    return false;

}

int main(){

    char first[100];
    char second[100];
    gets(first);
    gets(second);

    strcat(second, " ");
    int mid = strlen(second);
    strcat(second, first);
    second[strlen(second)+1] = '\0';
    strncpy(first, " ", strlen(first));

    for(int i = mid; second[i] != '\0'; i++){
        if(second[i-1] == '\0')
            break;
        if(isOdd(second, i, first) == false){
            puts(first);
            strncpy(first, " ", strlen(first));
        } else if (!containsAllLetters(first, second)){
            puts(first);
            strncpy(first, " ", strlen(first));
        }
        i += len;
    }


    return 0;
}