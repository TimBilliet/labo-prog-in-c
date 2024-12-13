#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct knoop knoop;
// indien de pointer naar de eerste knoop moet verplaatst worden of null worden gemaakt worden, dubbele ster
struct knoop {
    int getal;
    knoop* volgend;
};
void print_lijst(const knoop*);
knoop* maak_gesorteerde_lijst_automatisch(int, int);
void voeg_vooraan_toe(int, knoop**);
void vernietig_lijst(knoop**);
void verwijder_dubbels(knoop*);

int main() {
    srand(time(NULL));
    knoop* l = maak_gesorteerde_lijst_automatisch(10, 100);
    print_lijst(l);
    printf("\nnu worden dubbels verwijderd: \n");
    verwijder_dubbels(l);  // aan te vullen
    printf("\nna verwijderen van dubbels: \n\n");
    print_lijst(l);
    //...  // aan te vullen
    vernietig_lijst(&l);
    return 0;
}

knoop* maak_gesorteerde_lijst_automatisch(int aantal, int einde) {
    int getal = einde;  //[0, einde]
    knoop* lst = 0;
    for (int i = 0; i < aantal; i++) {
        voeg_vooraan_toe(getal, &lst);
        getal = getal - rand() % 3;
    }
    return lst;
}

void verwijder_dubbels(knoop* list) {
    while (list) {
        while (list->volgend != NULL && list->getal == list->volgend->getal) {
            knoop* hulp = list->volgend;
            list->volgend = list->volgend->volgend;
            free(hulp);
        }
        list = list->volgend;
    }
}

void print_lijst(const knoop* list) {
    while (list) {
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
    while (*list) {
        knoop* hulp = *list;
        *list = (*list)->volgend;
        free(hulp);
    }
}

// extra oef eerste knoop naar achter, maatste knoop naar voor

// merge(l1,l2), geordende lijsten samenvoegen, l1 en l2 worden leeg, geen nieuwe knopen maken moet ook geordend zijn
// optioneel 38: while() {
// pl=}
// }
//*pl = ;