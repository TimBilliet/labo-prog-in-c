#include <stdio.h>
#include <stdlib.h>
typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop *volgend;
};

void voeg_getal_toe(int, knoop **);

void print_lijst(const knoop *);
void voeg_getal_toe_nieuw(int, knoop **);
int main() {
    knoop *lijst = 0;

    print_lijst(lijst);
    // voeg_getal_toe(4, &lijst);
    // voeg_getal_toe(8, &lijst);
    // voeg_getal_toe(20, &lijst);
    // voeg_getal_toe(2, &lijst);
    print_lijst(lijst);
    printf("Voeg getal nieuw toe\n");
    voeg_getal_toe_nieuw(10, &lijst);
    voeg_getal_toe_nieuw(100, &lijst);
    voeg_getal_toe_nieuw(7, &lijst);
    print_lijst(lijst);
    return 0;
}

void print_lijst(const knoop *lijst) {
    while (lijst) {
        printf("%d ", lijst->getal);
        lijst = lijst->volgend;
    }
    printf("X\n");
}

void voeg_getal_toe_nieuw(int g, knoop **l) {
    while (*l != NULL && (*l)->getal < g) {
        l = &((*l)->volgend);
    }
    knoop *temp = malloc(sizeof(knoop));
    temp->getal = g;
    temp->volgend = *l;  // dit kan omdat op het einde van de lijst *l 0 is en wordt temp-> volgend dus ook mooi 0
    (*l) = temp;
}

void voeg_getal_toe(int g, knoop **pl) {
    knoop *h, *m;
    if (*pl == 0 || g <= (*pl)->getal) {
        h = malloc(sizeof(knoop));
        h->getal = g;
        h->volgend = *pl;
        *pl = h;
    } else {
        h = *pl;
        while (h->volgend != 0 && h->volgend->getal < g)
            h = h->volgend;
        m = h->volgend;
        h->volgend = malloc(sizeof(knoop));
        h = h->volgend;
        h->getal = g;
        h->volgend = m;
    }
}