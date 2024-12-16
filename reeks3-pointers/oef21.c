#include <stdio.h>

int* plaats_van(int* t, int n, int g);
int* plaats_ptr_op_getal(const int** const p, int n, int g);

int main() {
    int arr[] = {20, 1, 2, 53, 4, 5, 6, 10, 8};
    int getal = 53;
    int getal2 = 4;

    // printf("%d", plaats_van(arr, sizeof(arr) / sizeof(arr[0]), 55));
    int* plaats_van_getal = plaats_van(arr, sizeof(arr) / sizeof(arr[0]), getal);
    if (plaats_van_getal != NULL) {
        printf("%d komt voor op index %d, adres =  %p\n", getal, plaats_van_getal - arr, plaats_van_getal);
        *plaats_van_getal *= 2;
    } else {
        printf("%d komt niet voor\n", getal);
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    int* verplaatsende_pointer = arr;
    printf("Verplaatsende pointer wijst naar %d met index %d\n", *verplaatsende_pointer, verplaatsende_pointer - arr);
    int* verplaatste_pointer = plaats_ptr_op_getal(&verplaatsende_pointer, sizeof(arr) / sizeof(arr[0]), getal2);
    if (verplaatste_pointer != NULL) {
        printf("Verplaatsende pointer wijst nu naar %d met index %d\n", *verplaatsende_pointer, verplaatsende_pointer - arr);
        printf("Resterende getallen in het array: ");
        while (verplaatste_pointer < arr + sizeof(arr) / sizeof(arr[0]) - 1) {  // verschuif verplaatste_pointer op tot aan het einde van het array
            verplaatste_pointer++;
            printf("%d, ", *verplaatste_pointer);
        }
    } else {
        printf("verplaatsende_pointer komt niet voor in arr;");
    }

    return 0;
}

int* plaats_van(int* t, int n, int g) {  // geen const int* t want dan moet ook een const int* gereturned worden
    for (int i = 0; i < n; i++) {
        if (g == *t) {
            return t;
        }
        t++;
    }
    return NULL;
}

int* plaats_ptr_op_getal(const int** const p, int n, int g) {
    for (int i = 0; i < n; i++) {
        if (**p == g) {
            // return;NOG TE FIXEN
        }
        (*p)++;
    }
    return NULL;
}