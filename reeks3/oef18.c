#include <stdio.h>

void schrijf_aantal(char*, int);
void schrijf(char*, char*);

int main() {
    char letters[] = {'p', 'o', 'r', 'g', 'o', 'e', 'd', 'o', 'i', 'e', 'o', 'k', 'i', ':', 'a', '-', 't', '('};
    char* p = letters;
    schrijf_aantal(letters + 3, 4);  // output: goed
    printf("\n");
    schrijf(p + 10, p + 12);  // output: ok
    return 0;
}

void schrijf_aantal(char* p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", *p++);
    }
}

void schrijf(char* begin, char* eind) {
    while (begin < eind) {
        printf("%c", *begin++);
    }
}