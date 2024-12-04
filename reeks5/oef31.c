#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* lees();
int aantal = 1000;
int main() {
    for (int i = 0; i < 5; i++) {
        printf("Voer een tekst in\n");
        char* tekst = lees();
        printf("Ik las ***%s*** \n", tekst);
        free(tekst);
    }
    return 0;
}

char* lees() {
    char str_in[aantal];
    fgets(str_in, aantal, stdin);
    int len = strlen(str_in) - 1;
    char* kleiner = malloc(sizeof(char) * len);
    strncpy(kleiner, str_in, len);
    return kleiner;
}