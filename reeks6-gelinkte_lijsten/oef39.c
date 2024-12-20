#include <stdio.h>
#include <stdlib.h>
typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop *volgend;
};

void print_lijst(const knoop *);
void voeg_getal_toe_nieuw(int, knoop **);
void verwijder(int g, knoop **l);
int main() {
    knoop *lijst = 0;

    print_lijst(lijst);

    print_lijst(lijst);
    printf("Voeg getal nieuw toe\n");
    voeg_getal_toe_nieuw(10, &lijst);
    voeg_getal_toe_nieuw(100, &lijst);
    voeg_getal_toe_nieuw(7, &lijst);
    print_lijst(lijst);
    int te_verwijderen_getal = 10;
    printf("%d wordt verwijderd\n", te_verwijderen_getal);
    verwijder(te_verwijderen_getal, &lijst);
    print_lijst(lijst);
    return 0;
}

void verwijder(int g, knoop **l) {
    while ((*l)->getal < g && (*l) != NULL) {
        l = &((*l)->volgend);
    }

    if ((*l) != NULL && (*l)->getal == g) {
        knoop *free_my_boy_temp_he_aint_do_nun_wrong = *l;
        *l = (*l)->volgend;
        free(free_my_boy_temp_he_aint_do_nun_wrong);//ite bro got you
    }
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
