#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    const int van = 2;
    const int tot = 30;

    double uitkomst = 1;
    srand(time(NULL));
    int random = van + rand() % (tot - van + 1);
    printf("Random getal tussen %d en %d = %d\n", van, tot, random);

    for (int i = 1; i <= tot; i++) {
        uitkomst = uitkomst * i;
        if (i == random) {
            printf("%d! = %f \n", i, uitkomst);
        }
    }
    return 0;
}