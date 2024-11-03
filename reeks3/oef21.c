#include <stdio.h>

int* plaats_van(int* t, int n, int g);

int main() {
    int arr[] = {0, 1, 2, 53, 4, 5, 6, 7, 8};
    int getal = 53;
    // printf("%d", plaats_van(arr, sizeof(arr) / sizeof(arr[0]), 55));
    int* plaats_van_getal = plaats_van(arr, sizeof(arr) / sizeof(arr[0]), getal);
    if (plaats_van_getal != NULL) {
        printf("%d komt voor, adres =  %p\n", getal, plaats_van_getal);
    } else {
        printf("%d komt niet voor\n", getal);
    }
    return 0;
}

int* plaats_van(int* t, int n, int g) {
    for (int i = 0; i < n; i++) {
        if (g == *t) {
            return t;
        }
        t++;
    }
    return NULL;
}