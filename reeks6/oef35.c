#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;

struct knoop {
    int getal;
    knoop *volgend;
};

void print_lijst();
void voeg_vooraan_toe(int, knoop **);
void vernietig_lijst(knoop **);
int main() {
    knoop *lst = NULL;
    print_lijst(lst);  // output: X
    voeg_vooraan_toe(7, &lst);
    voeg_vooraan_toe(3, &lst);
    print_lijst(lst);  // output: 3 7 X
    vernietig_lijst(&lst);
    print_lijst(lst);  // output: X
    return 0;
}


void voeg_vooraan_toe(int getal, knoop **list) {
    knoop *nieuweknoop = malloc(sizeof(knoop));
    nieuweknoop->getal = getal;
    nieuweknoop->volgend = *list;
    *list = nieuweknoop;
}

void vernietig_lijst(knoop **list) {
    knoop *hulp = (*list)->volgend;
    while (hulp != NULL) {
        free(*list);
        *list = hulp->volgend;
        hulp = *list;
    }
}