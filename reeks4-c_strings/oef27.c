#include <ctype.h>
#include <stdio.h>

void wis(char*);

int main(int argc, char** argv) {
    char brol[] = "8\td?a7!+. -)4h&!e9)b*( )j'(e)!4\n8g|'92o!43e5d/.' 2 3g*(e('d22a'(a25n'(";
    printf("String voor verandering = %s\n", brol);
    wis(brol);
    printf("String na verandering = %s\n", brol);
    return 0;
}

void wis(char* s) {
    char* juiste_woord_ptr = s;
    while (*s != 0) {
        if (islower(*s) || isspace(*s)) {
            *juiste_woord_ptr = *s;
            juiste_woord_ptr++;
        }
        s++;
    }
    *juiste_woord_ptr = '\0';
}