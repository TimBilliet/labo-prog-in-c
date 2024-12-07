#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** lees_meerdere(int);
char* lees();
int aantal = 1000;
int main() {
    char** woorden = lees_meerdere(5);
    while (*woorden != NULL) {
        printf("%s\n", *woorden);
        woorden++;
    }
    free(woorden);
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

char** lees_meerdere(int n) {
    char** string_arr = malloc((n + 1) * sizeof(char*));
    // char** string_arr;
    for (int i = 0; i < n; i++) {
        printf("Voer lijn nr %d in\n", i + 1);
        string_arr[i] = lees();
    }
    string_arr[n] = NULL;
    return string_arr;
}
