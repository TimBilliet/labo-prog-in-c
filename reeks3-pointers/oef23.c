#include <stdio.h>

const int AANTAL = 5;

int som(int a, int b) {
    return a + b;
}

int product(int a, int b) {
    return a * b;
}

int verschil(int a, int b) {
    return a - b;
}

void schrijf(const int* t, int aantal) {
    for (int i = 0; i < aantal; i++)
        printf("%d ", t[i]);
    printf("\n");
}
void vul_array(const int*, const int*, int*, int, int (*)(int, int));

int main() {
    int a[AANTAL];
    int b[AANTAL];
    int c[AANTAL];
    for (int i = 0; i < AANTAL; i++) {
        a[i] = 10 * i;
        b[i] = i;
    }

    vul_array(a, b, c, AANTAL, som);
    schrijf(c, AANTAL);

    vul_array(a, b, c, AANTAL, product);
    schrijf(c, AANTAL);

    vul_array(a, b, c, AANTAL, verschil);
    schrijf(c, AANTAL);
    return 0;
}

void vul_array(const int* a, const int* b, int* c, int aantal, int (*func_p)(int, int)) {
    for (int i = 0; i < aantal; i++) {
        c[i] = func_p(a[i], b[i]);
    }
}