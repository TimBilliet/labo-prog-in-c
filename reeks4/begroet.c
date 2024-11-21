#include <stdio.h>

void my_toupper(char*);

int main(int argc, char** argv) {
    if (argc == 0) {
        printf("Dag allemaal!\n");
    } else {
        for (int i = 1; i < argc; i++) {
            // my_toupper(argv[i]); //zelfde als de 2 lijnen hieronder
            argv++;
            my_toupper(*argv);
            printf("Dag %s!\n", *argv);
        }
    }

    return 0;
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