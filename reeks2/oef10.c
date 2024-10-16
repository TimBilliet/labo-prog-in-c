#include <stdio.h>

int ggd(int, int);
int zijn_onderling_ondeelbaar(int, int);
void print_onderling_ondeelbaar(int, int);

int main() {
    // printf("ggd(18, 24) = %d\n", ggd(18, 24));
    print_onderling_ondeelbaar(5, 8);
    return 0;
}

int ggd(int a, int b) {
    int antwoord = 0;
    if (b == 0) {
        antwoord = a;
    } else {
        antwoord = ggd(b, a % b);
    }
    return antwoord;
}
int zijn_onderling_ondeelbaar(int a, int b) {
    if (ggd(a, b) == 1) {
        return 1;
    } else {
        return 0;
    }
}

void print_onderling_ondeelbaar(int a, int b) {
    for (int i = a; i <= b; i++) {
        for (int j = i; j <= b; j++) {
            if (zijn_onderling_ondeelbaar(i, j) == 1) {
                printf("%d en %d zijn onderling ondeelbaar\n", i, j);
            }
        }
    }
}