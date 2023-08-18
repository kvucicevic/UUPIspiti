#include <stdio.h>
#include <malloc.h>

/*
    3. (25p) Napisati program koji učitava podatke o broju rođenih beba po datumima u jednom gradu i
            smešta ih u listu. Podaci se u fajlu nalaze u obliku: dan mesec godina broj beba, svi podaci su
            razdvojeni spejsom. Primer: 23 2 2018 12 (23. februara 2018. rođeno je 12 beba).
            Napraviti meni za interakciju preko konzole sa slededim opcijama.
            a) (7p) učitavanje podataka, unosi se naziv fajla koji sadrži opisane podatke i učitava se u listu
            uređenu nerastude po broju rođenih beba,
            b) (8p) ispis broja rođenih beba u jednoj godini, unosi se godina i treba ispisati broj rođenih u toj
            godini, ovu funkcionalnost je potrebno implementirati na dva načina, iterativno i rekurzivno,
            c) (10p) ispis broja rođenih beba po mesecima sortirano rastude po godini i mesecu, posmatra se
            broj rođenih beba u konkretnom mesecu (na primer 2.2018.) i ispisuje se mesec, godina i broj
            rođenih u tom mesecu, sortirano rastude po mesecu (dozvoljeno je praviti nove strukture podataka)
 */

typedef struct Porodiliste Porodiliste;
struct Porodiliste {
    int godina;
    int mesec;
    int dan;
    int brojBeba;
    Porodiliste* nextB;
};
void insertionSort(Porodiliste** head);
void sortedInsert(Porodiliste** head, Porodiliste* newNode);
void printList(Porodiliste* head);

void loadFile(char* fileName){

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Porodiliste* head = NULL;

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        int godina;
        int mesec;
        int dan;
        int brojBeba;

        sscanf(line, "%d %d %d %d ", &godina, &mesec, &dan, &brojBeba);
        Porodiliste* node = (Porodiliste*)malloc(sizeof(Porodiliste));
        node->godina = godina;
        node->mesec = mesec;
        node->dan = dan;
        node->brojBeba = brojBeba;
        node->nextB = NULL;

        if (head == NULL) {
            head = node;
        } else {
            node->nextB = head;
            head = node;
        }

    }

    insertionSort(&head);
    printList(head);

}

void printList(Porodiliste* head) {
    Porodiliste* current = head;
    while (current->nextB != NULL) {
        printf("Datum: %d-%d-%d, Broj beba: %d\n", current->dan, current->mesec, current->godina, current->brojBeba);
        current = current->nextB;
    }
}

void sortedInsert(Porodiliste** headRef, Porodiliste* newNode){
    Porodiliste* current;
    if(*headRef == NULL || (*headRef)->brojBeba >= newNode->brojBeba){  //uslov je ispunjen
        newNode->nextB = *headRef; // samo dodaj u listu
        *headRef = newNode;
    } else { // uslov nije ispunjen
        current = *headRef;
        while(current->nextB != NULL && current->nextB->brojBeba < newNode->brojBeba){
            current = current->nextB;  // nadji mesto za trenutni node u listi
        }
        newNode->nextB = current->nextB; // prepovezivanje pokazivaca
        current->nextB = newNode;
    }
}

void insertionSort(Porodiliste** headRef){
    Porodiliste* sorted = NULL;
    Porodiliste* current = *headRef;
    while(current != NULL){
        Porodiliste* next = current->nextB;
        sortedInsert(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}


int main(){

    loadFile("grupa1.txt");

    return 0;
}