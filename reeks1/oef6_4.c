#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    const int van = 2;
    const int tot = 20;

    double uitkomst = 1;

    int userInput;
    printf("Vul een getal in tussen 2 en 20 (grenzen inbegrepen)\n");

    while (scanf("%d", &userInput) == 0 || userInput < van || userInput > tot) {
        printf("Foute invoer\n");
        printf("Vul een getal in tussen 2 en 20 (grenzen inbegrepen)\n");
        while (getchar() != '\n');
    }
    for (int i = 1; i <= tot; i++) {
        uitkomst = uitkomst * i;
        if (i == userInput) {
            printf("%d! = %f\n", i, uitkomst);
        }
    }
    return 0;
}