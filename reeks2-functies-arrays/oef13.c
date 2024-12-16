#include <stdio.h>

void schuif_links(char letters[], int lengte);
int main() {
    char letters[] = {'s', 'a', 'p', 'a', 'p', 'p', 'e', 'l'};
    schuif_links(letters, sizeof(letters) / sizeof(letters[0]));

    for (int i = 0; i < sizeof(letters) / sizeof(letters[0]); i++) {
        printf("%c", letters[i]);
    }
    printf("\n");
    schuif_links(letters, sizeof(letters) / sizeof(letters[0]));
    for (int i = 0; i < sizeof(letters) / sizeof(letters[0]); i++) {
        printf("%c", letters[i]);
    }
    printf("\n");
    schuif_links(letters, sizeof(letters) / sizeof(letters[0]));
    for (int i = 0; i < sizeof(letters) / sizeof(letters[0]); i++) {
        printf("%c", letters[i]);
    }
    printf("\n");
    return 0;
}

void schuif_links(char letters[], int lengte) {
    char eerste_element = letters[0];
    for (int i = 0; i < lengte - 1; i++) {
        letters[i] = letters[i + 1];
    }
    letters[lengte - 1] = eerste_element;
}