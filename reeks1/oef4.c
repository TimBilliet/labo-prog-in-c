#include <stdio.h>
int main() {
    int macht = 1;
    while (macht < 10000) {
        printf("%d ", macht);
        macht *= 2;
    }
    return 0;
}