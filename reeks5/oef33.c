#include <stdio.h>

void plaats_ptr_op_string(char*** p, char c);

int main() {
    char* p[] = {"test", "test2", "dit is een test", "en nog een laatste testje", "grapje nog een", NULL};
    char** wijzende_pointer = p;  // pointer p wijst naar het eerste element van p (een string, char*)
    plaats_ptr_op_string(&wijzende_pointer, 'e');
    return 0;
}

void plaats_ptr_op_string(char*** p, char c) {
    while (**p != NULL && ***p != c) {
        (*p)++;
    }
    printf("staat op '%c' bij zin '%s'\n", ***p, **p);
}