#include <stdio.h>

void schrijf_even_posities(char letters[], int lengte);

int main() {
    char letters[] = {'p', 'o', 'r', 'e', 'o', 'i', 'f', 'o', 'i', 'e', 'c', 'i', 'i', ':', 'a', '-', 't', '('};
    printf("lengte is %d\n", sizeof(letters) / sizeof(letters[0]));

    for (int i = 0; i < sizeof(letters) / sizeof(letters[0]); i++) {
        if (i % 2 == 0) {
            printf("%c", letters[i]);
        }
    }
    printf("\n");
    schrijf_even_posities(letters, sizeof(letters) / sizeof(letters[0]));
    return 0;
}

void schrijf_even_posities(char letters[], int lengte) {
    for (int i = 0; i < lengte; i++) {
        if (i % 2 == 0) {
            printf("%c", letters[i]);
        }
    }
    printf("\n");
}