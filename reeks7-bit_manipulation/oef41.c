#include <limits.h>
#include <stdio.h>

void wijzig_eerste_cijfer(int*);

int main() {
    int getal = 0x53a9;
    printf("%x\n", getal);
    wijzig_eerste_cijfer(&getal);
    printf("%x\n", getal);
    return 0;
}

void wijzig_eerste_cijfer(int* g) {
    int gg = *g;
    int mask = 0b1111;
    gg >>= 4;
    while (gg) {
        mask <<= 4;
        gg >>= 4;
    }
    *g |= mask;
}

// void wijzig_eerste_cijfer(int* g) {
//     unsigned int mask = 0b11110000000000000000000000000000;
//     while (!(mask & *g)) {
//         mask >>= 4;
//     }
//     *g |= mask;
// }