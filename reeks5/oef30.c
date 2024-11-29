#include <math.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
} punt;
double euclidische_afstand(const punt*, const punt*);
double manhattan_afstand(const punt*, const punt*);
double schaakbord_afstand(const punt*, const punt*);
double bepaal_max_afstand(const punt*[], int, double (*)(const punt*, const punt*));
int main() {
    punt p1 = {
        .x = 7,
        .y = 8,
    };

    punt p1 = {
        .x = 2,
        .y = 3,
    };

    return 0;
}

double bepaal_max_afstand(const punt* punten[], int aantal, double (*func)(const punt*, const punt*)) {
    int startpos = 0;

    while (startpos < aantal) {
        // for (int i = startpos; i < aantal; i++) {
        //     punt* eerst = *punten++;
        //     double afstand = func(eerst, *punten);
        // }
    }
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