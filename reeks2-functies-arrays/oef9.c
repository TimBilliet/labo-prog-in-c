#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cijfersom(int);

const int cijfer = 12345;
const int van = 1;
const int tot = INT_MAX;

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int random = van + rand() % (tot - van + 1);
        printf("cijfersom van %d = %d\n", random, cijfersom(random));
    }
    return 0;
}

int cijfersom(int cijfer) {
    int uitkomst = 0;
    while (cijfer > 0) {
        uitkomst += cijfer % 10;
        cijfer /= 10;
    }
    return uitkomst;
}