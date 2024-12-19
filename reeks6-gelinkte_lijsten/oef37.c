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
knoop* merge(knoop**, knoop**);

int main() {
    srand(time(NULL));
    knoop* m = maak_gesorteerde_lijst_automatisch(10, 1000);
    knoop* n = maak_gesorteerde_lijst_automatisch(5, 1000);
    printf("\nLIJST m:\n");
    print_lijst(m);  // output: 10 geordende getallen + X
    printf("\nLIJST n:\n");
    print_lijst(n);  // output: 5 geordende getallen + X

    printf("\nDeze worden gemerged. \n\n");
    knoop* mn = merge(&m, &n);

    printf("\nLIJST m:   \n");
    print_lijst(m);  // output: X
    printf("\nLIJST n:   \n");
    print_lijst(n);  // output: X
    printf("\nRESULTAAT: \n");
    print_lijst(mn);  // output: 15 geordende getallen + X

    vernietig_lijst(&mn);  // aan te vullen
    return 0;
}
knoop* merge(knoop** m, knoop** n) {
    knoop* list_out;
    if ((**m).getal > (**n).getal) {
        list_out = *n;
        *n = (**n).volgend;
    } else if ((**m).getal <= (**n).getal) {
        list_out = *m;
        *m = (**m).volgend;
    }
    knoop* hulp = list_out;
    while (*m != NULL && *n != NULL) {
        if ((**m).getal > (**n).getal) {
            (*hulp).volgend = *n;  // of hulp->volgend = *n;
            *n = (**n).volgend;
        } else if ((**m).getal <= (**n).getal) {
            (*hulp).volgend = *m;
            *m = (**m).volgend;
        }
        hulp = (*hulp).volgend;
    }
    if (*m) {
        (*hulp).volgend = *m;
    } else {
        (*hulp).volgend = *n;
    }
    *m = NULL;
    *n = NULL;
    return list_out;
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
