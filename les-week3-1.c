#include <stdio.h>

int main() {
    int getal = 1;

    int ret = scanf("%d", &getal);
    while (ret != 1 || getal < 5 || getal > 20) {
        getal *= 2;
        printf("fout ");
        while (getchar() != '\n');
        ret = scanf("%d", &getal);
    }
    printf("iingevoerd getal%d\n", getal);
    return 0;
}