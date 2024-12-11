#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop* volgend;
};
void print_lijst(const knoop*);
knoop* maak_gesorteerde_lijst_automatisch(int, int);
void voeg_vooraan_toe(int, knoop**);
void vernietig_lijst(knoop**);
int main() {
    srand(time(NULL));
    knoop* l = maak_gesorteerde_lijst_automatisch(10, 100);
    print_lijst(l);
    printf("\nnu worden dubbels verwijderd: \n");
    // verwijder_dubbels(...);  // aan te vullen
    printf("\nna verwijderen van dubbels: \n\n");
    print_lijst(l);
    //...  // aan te vullen

    return 0;
}

knoop* maak_gesorteerde_lijst_automatisch(int aantal, int einde) {
    int getal = einde;  //[0, einde]
    knoop* lst = 0;
    int grootte = 0;
    while (grootte < aantal) {
        voeg_vooraan_toe(getal, &lst);
        getal = getal - rand() % (3);
        grootte++;
    }
    return lst;
}
void verwijder_dubbels() {
}
void print_lijst(const knoop* list) {
    while (list != NULL) {
        printf("%d ", list->getal);
        list = list->volgend;
    }
    printf("X\n");
}
void voeg_vooraan_toe(int getal, knoop** list) {
    knoop* nieuweknoop = malloc(sizeof(knoop));
    nieuweknoop->getal = getal;
    nieuweknoop->volgend = *list;
    *list = nieuweknoop;
}
void vernietig_lijst(knoop** list) {
    knoop* hulp = (*list)->volgend;
    while (hulp != NULL) {
        free(*list);
        *list = hulp->volgend;
        hulp = *list;
    }
}