#include <stdio.h>

void schrijf(char*, char*);
void pivoteer(char*, char*, char*);

int main() {
    //               0    1    2    3    4    5    6    7    8    9    10  11   12
    char tekst[] = {'b', 'd', '?', 'z', 'g', 'o', 'e', 'z', 'e', 'b', ' ', 'd', 'i', 'g', '!', 'h', 'o', 's', 'v'};

    //                                                  X         X              X
    pivoteer(tekst + 7, tekst + 12, tekst + 9);
    schrijf(tekst + 4, tekst + 15);
    return 0;
}

void schrijf(char* begin, char* eind) {
    while (begin < eind) {
        printf("%c", *begin++);
    }
}

void pivoteer(char* begin, char* einde, char* pivot) {  // veronderstel begin < pivot < einde
    char* p_links = pivot - 1;
    char* p_rechts = pivot + 1;
    char tempchar;
    while (p_links >= begin && p_rechts < einde) {
        tempchar = *p_links;
        *p_links = *p_rechts;
        *p_rechts = tempchar;
        p_links--;
        p_rechts++;
    }
}