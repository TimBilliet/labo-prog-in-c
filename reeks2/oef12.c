#include <stdio.h>

int index_van(double array[], int lengte, double getal);

int main() {
    double getallen[] = {1.2, 3.4, 5.6, 3.4, 9.0, 3.4, 9.0, 1.2};
    // const double getal = 9.0;
    double getal;
    printf("Vul een reeel getal in\n");
    while (scanf("%lf", &getal) == 0) {
        while (getchar() != '\n');
        printf("Foute invoer, vul een reeel getal in\n");
    }

    if (index_van(getallen, sizeof(getallen) / sizeof(getallen[0]), getal) == -1) {
        printf("Het getal %f komt niet voor in de array\n", getal);
    } else {
        printf("Het getal %f komt voor op index %d\n", getal, index_van(getallen, sizeof(getallen) / sizeof(getallen[0]), getal));
    }
    // printf("laagste index van %f is %d", getal, index_van(getallen, sizeof(getallen) / sizeof(getallen[0]), getal));
    return 0;
}

int index_van(double array[], int lengte, double getal) {
    for (int i = 0; i < lengte; i++) {
        if (array[i] <= getal + 0.0001 && array[i] >= getal - 0.0001) {
            return i;
        }
    }
    return -1;
}