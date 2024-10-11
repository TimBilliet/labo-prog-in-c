#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    const int van = 2;
    const int tot = 30;

    // meest juist met double, dan met long long
    long long uitkomst = 1;
    // srand(time(NULL));
    // int random = van + rand() % (tot - van + 1);
    // printf("rand %d", random);
    // printf("\n");

    int userInput;
    printf("Vul een getal in tussen 2 en 20 (grenzen inbegrepen)\n");
    scanf("%d", &userInput);
    while (userInput < 2 || userInput > 30) {
        printf("Foute invoer\n");
        while (getchar() != '\n');
        scanf("%d", &userInput);
    }
    for (int i = 1; i <= tot; i++) {
        uitkomst = uitkomst * i;
        if (i == userInput) {
            printf("%d! = %lld\n", i, uitkomst);
        }
        if (i >= van) {
            // printf("%d! = %f \n", i, uitkomst);
        }
        // if (i == random) {
        // printf("random %d! = %f \n", i, uitkomst);
        // }
    }
    return 0;
}