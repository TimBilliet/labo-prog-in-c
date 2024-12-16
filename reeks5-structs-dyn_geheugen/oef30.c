#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} punt;

double euclidische_afstand(const punt*, const punt*);
double manhattan_afstand(const punt*, const punt*);
double schaakbord_afstand(const punt*, const punt*);
double bepaal_max_afstand(const punt[], int, double (*)(const punt*, const punt*));
double max(double, double);
int main() {
    // punt p1 = {
    //     .x = 1,
    //     .y = 2,
    // };

    // punt p2 = {
    //     .x = 3,
    //     .y = 4,
    // };
    // punt p3 = {
    //     .x = 5,
    //     .y = 6,
    // };
    // punt p4 = {
    //     .x = 7,
    //     .y = 8,
    // };
    // const punt* punten[4] = {&p1, &p2, &p3, &p4};

    // double afstand = bepaal_max_afstand(punten, sizeof(punten) / sizeof(punten[0]), manhattan_afstand);
    printf("Hoeveel punten wilt u ingeven?\n");
    int aantal_punten;

    while (scanf("%d", &aantal_punten) != 1) {
        while (getchar() != '\n');
        printf("Foute invoer, voer een nieuw getal in\n");
    }
    const punt ingevoerde_punten[aantal_punten];

    for (int i = 0; i < aantal_punten; i++) {
        // ingevoerde_punten[i] = malloc(sizeof(punt));
        // double x = 0;
        printf("Vul een x-coordinaat in voor punt %d\n", i + 1);
        while (scanf("%lf", &ingevoerde_punten[i].x) != 1) {
            while (getchar() != '\n');
            printf("Foute invoer, voer een nieuw x-coordinaat in\n");
        }
        printf("Vul een y-coordinaat in voor punt %d\n", i + 1);
        // double y = 0;
        while (scanf("%lf", &ingevoerde_punten[i].y) != 1) {
            while (getchar() != '\n');
            printf("Foute invoer, voer een nieuw y-coordinaat in\n");
        }
        // ingevoerde_punten[i].x = x;
        // ingevoerde_punten[i].y = y;
    }
    printf("Max euclidische afstand is %f\n", bepaal_max_afstand((const punt*)ingevoerde_punten, sizeof(ingevoerde_punten) / sizeof(ingevoerde_punten[0]), euclidische_afstand));
    printf("Max manhattan afstand is %f\n", bepaal_max_afstand((const punt*)ingevoerde_punten, sizeof(ingevoerde_punten) / sizeof(ingevoerde_punten[0]), manhattan_afstand));
    printf("Max schaakbordafstand is %f\n", bepaal_max_afstand((const punt*)ingevoerde_punten, sizeof(ingevoerde_punten) / sizeof(ingevoerde_punten[0]), schaakbord_afstand));
    return 0;
}

double bepaal_max_afstand(const punt punten[], int aantal, double (*func)(const punt*, const punt*)) {
    const punt* einde = punten + aantal;
    const punt* startpos = punten;
    double afstand = 0;
    while (startpos < einde) {
        const punt eerste_punt = *startpos;
        punten = startpos;
        punten++;

        while (punten < einde) {
            const punt tweede_punt = *punten++;
            afstand = max(afstand, func(&eerste_punt, &tweede_punt));
            // printf("vergelijking tussen %f x en %f x\n", eerste_punt->x, tweede_punt->x);
        }
        startpos++;
    }
    return afstand;
}
double max(double a, double b) {
    return a > b ? a : b;
}
double euclidische_afstand(const punt* p1, const punt* p2) {
    return sqrt(pow(fabs(p1->x - p2->x), 2) + pow(fabs(p1->y - p2->y), 2));
}

double manhattan_afstand(const punt* p1, const punt* p2) {
    return (fabs(p1->x - p2->x)) + (fabs(p1->y - p2->y));
}

double schaakbord_afstand(const punt* p1, const punt* p2) {
    return max(fabs(p1->x - p2->x), fabs(p1->y - p2->y));
}
