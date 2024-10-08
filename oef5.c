#include <stdio.h>
int main() {
    int macht = 1;
    // er wordt gebruik gemaakt van break om een for lus te stoppen
    for (int i = 0; i < 20; i++) {
        printf("%d ", macht);
        macht *= 2;
        if (macht > 10000)
            break;
    }
    return 0;
}