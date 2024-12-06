#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* lees();
int aantal = 5;
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
    char str_in[aantal + 1];
    fgets(str_in, aantal + 1, stdin);
    int len = strlen(str_in);  // len is stringlengte zonder nullchar
    if (str_in[len - 1] == '\n') {
        str_in[len - 1] = '\0';
        len--;
    } else {
        while (getchar() != '\n');
    }
    char* kleiner = malloc(sizeof(char) * len + 1);
    strcpy(kleiner, str_in);
    return kleiner;
}