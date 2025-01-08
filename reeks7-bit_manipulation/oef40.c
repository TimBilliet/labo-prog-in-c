#include <stdio.h>

typedef unsigned int uint;

int bit_i(uint x, int i);
uint eenbit(int i);
int aantal_eenbits(uint x);
uint bit_i_aangezet(uint x, int i);
uint bit_i_uitgezet(uint x, int i);
uint bit_i_gewisseld(uint x, int i);
int zijn_verschillend(uint x, uint y);
int is_even(uint x);
int main() {
    // printf("%d", bit_i(20, 2));
    // printf("%d", eenbit(0));
    // printf("%d", aantal_eenbits(20));
    // printf("%d", bit_i_aangezet(20, 3));
    // printf("%d", bit_i_uitgezet(20, 2));
    // printf("%d", bit_i_gewisseld(20, 4));
    // printf("%d", zijn_verschillend(20, 20));
    printf("%d", is_even(20));
    return 0;
}

int bit_i(uint x, int i) {
    return x >> i & 1;
}

uint eenbit(int i) {
    return 1 << i;
}

int aantal_eenbits(uint x) {
    int mask = 1;
    int count = 0;
    while (x) {
        count += (x & 1);
        x >>= 1;
    }
    return count;
}

uint bit_i_aangezet(uint x, int i) {
    return x | (1 << i);
}

uint bit_i_uitgezet(uint x, int i) {
    return x & ~(1 << i);
}
uint bit_i_gewisseld(uint x, int i) {
    return x ^ (1 << i);
}
int zijn_verschillend(uint x, uint y) {
    return x ^ y;
}
int is_even(uint x) {
    return ~(x & 1) & 1;
    // return (x & 1) == 0;
}