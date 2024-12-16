#include <stdio.h>

void schrijf(const char*, const char*);
void verzetNaarEersteHoofdletter(const char**);
const char* pointerNaarEersteKleineLetter(const char*);
int main() {
    char zus1[50] = "sneeuwWITje";
    char zus2[50] = "rozeROOD";
    const char* begin = zus1;
    verzetNaarEersteHoofdletter(&begin);
    const char* eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin, eind); /* schrijft 'WIT' uit */
    printf("\n");
    begin = zus2;
    verzetNaarEersteHoofdletter(&begin);
    eind = pointerNaarEersteKleineLetter(begin);
    schrijf(begin, eind); /* schrijft 'ROOD' uit */
    return 0;
}

const char* pointerNaarEersteKleineLetter(const char* p) {
    while (!(*p >= 'a' && *p <= 'z') && *p != 0) {
        p++;
    }
    return p;
}

void verzetNaarEersteHoofdletter(const char** begin) {
    while ((**begin >= 'a' && **begin <= 'z') && **begin != 0) {
        (*begin)++;
    }
}

void schrijf(const char* begin, const char* eind) {
    while (begin < eind) {
        printf("%c", *begin++);
    }
}