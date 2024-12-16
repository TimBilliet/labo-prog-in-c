#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    const int ondergrens = 100;
    const int bovengrens = 125;
    const int aantal_getallen = 20;
    int aanwezig[aantal_getallen];

    for (int i = 0; i < aantal_getallen; i++) {
        aanwezig[i] = 1;
    }

    for (int i = 0; i < aantal_getallen; i++) {
        int random = ondergrens + rand() % (bovengrens - ondergrens + 1);  //[ondergrens, bovengrens]
        aanwezig[random - ondergrens] = 0;
        printf("Random getal %d = %d\n", i + 1, random);
    }

    for (int i = 0; i < aantal_getallen; i++) {
        if (aanwezig[i]) {
            printf("%d is niet aanwezig\n", ondergrens + i);
        }
    }
    return 0;
}