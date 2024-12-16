#include <stdio.h>

int main() {
    int getal = 0, som = 0, aantal = 0;

    while (getal >= 0 && aantal < 5) {
        printf("Vul een positief getal in: \n");
        scanf("%d", &getal);
        if (getal >= 0) {
            som += getal;
            aantal++;
        }
    }

    printf("De gebruiker heeft %d getal(len) ingevoerd\n", aantal);
    printf("De som van de ingevoerde getallen is %d\n", som);

    return 0;
}