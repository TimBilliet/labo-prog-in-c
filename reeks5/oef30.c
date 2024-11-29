#include <math.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
} punt;
double euclidische_afstand(const punt*, const punt*);
double manhattan_afstand(const punt*, const punt*);
double schaakbord_afstand(const punt*, const punt*);

int main() {
    punt p1 = {
        .x = 2,
        .y = 3,
    };

    punt p1 = {
        .x = 2,
        .y = 3,
    };

    return 0;
}

double euclidische_afstand(const punt* p1, const punt* p2) {
    return sqrt(pow(fabs(p1->x - p2->x), 2) + pow(fabs(p1->y - p2->y), 2));
}

double manhattan_afstand(const punt* p1, const punt* p2) {
    return (fabs(p1->x - p2->x)) + (fabs(p1->y - p2->y));
}
double schaakbord_afstand(const punt* p1, const punt* p2) {
    return
}