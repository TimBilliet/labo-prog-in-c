#include <stdio.h>

char* alfab_kleinste(char**, int);
void my_toupper(char*);

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Dag allemaal!\n");
    } else {
        char* alfab_kleinste_naam = alfab_kleinste(argv, sizeof(argv) / sizeof(argv[0]));
        my_toupper(alfab_kleinste_naam);
        printf("Dag %s!\n", alfab_kleinste_naam);
    }

    return 0;
}

char* alfab_kleinste(char** voornamen, int n) {
    char* kleinste = *voornamen;
    for (int i = 0; i < n; i++) {
        if (**voornamen > *kleinste) {  // of *voornamen[i] > kleinste[i]
            kleinste = *voornamen;
        }
    }
    return kleinste;
}

void my_toupper(char* woord) {
    if (*woord >= 'a' & *woord <= 'z') {
        *woord = *woord - ('a' - 'A');
    }
    woord++;
    while (*woord != 0) {
        if (*woord < 'a' && *woord >= 'A') {
            *woord = *woord - 'A' + 'a';
        }
        woord++;
    }
}