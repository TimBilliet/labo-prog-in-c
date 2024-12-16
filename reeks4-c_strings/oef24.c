#include <stdio.h>

int aantal_verschillende_letters(const char*);

int main(int argc, char** argv) {
    char test[] = "Dit is een voorbeeld";
    int aantal = aantal_verschillende_letters(test);
    printf("Aantal characters: %d\n", aantal);
    char invoer[31];
    printf("Voer een woord/zin van max 30 characters in\n");
    fgets(invoer, 31, stdin);
    printf("Het aantal verschillende letters van het ingevoerde woord is: %d", aantal_verschillende_letters(invoer));
    return 0;
}

int aantal_verschillende_letters(const char* zin) {
    int aanwezigheids[26] = {0};
    int count = 0;
    while (*zin != 0) {
        int index = *zin >= 'A' && *zin <= 'Z' ? *zin - 'A' : *zin - 'a';
        if (index > 0 && aanwezigheids[index] == 0) {
            aanwezigheids[index] = 1;
            count++;
        }
        zin++;
    }
    return count;
}