#include <stdio.h>

int aantal_verschillende_letters(const char*);
char hoofdletter_naar_kleine(char);

int main() {
    char test[] = "Dit is een voorbeeld";
    int aantal = aantal_verschillende_letters(test);
    printf("aantal characters: %d\n", aantal);
    return 0;
}

int aantal_verschillende_letters(const char* zin) {
    int aanwezigheids[26] = {0};
    int count = 0;
    while (*zin != 0) {
        char teCheckenChar = *zin;
        int index = (int)*zin >= (int)'A' && (int)*zin <= (int)'Z' ? *zin - 'A' : *zin - 'a';

        if (aanwezigheids[index] == 0) {
            aanwezigheids[index] = 1;
            count++;
        }

        zin++;
    }
    return count;
}