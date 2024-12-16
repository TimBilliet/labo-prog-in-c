#include <stdio.h>

void my_toupper(char*);

int main(int argc, char** argv) {
    char woord[] = "snEEuwwITJE<3!!";
    printf("Woord voor verandering: %s\n", woord);

    my_toupper(woord);
    printf("Woord na verandering: %s\n", woord);

    char ingevoerdWoord[21];
    printf("Voer een woord in met max 20 characters\n");
    scanf("%20s", ingevoerdWoord);

    printf("Woord voor verandering: %s\n", ingevoerdWoord);

    my_toupper(ingevoerdWoord);
    printf("Woord na verandering: %s\n", ingevoerdWoord);
    return 0;
}

void my_toupper(char* woord) {
    if (*woord >= 'a' & *woord <= 'z') {
        *woord = *woord - ('a' - 'A');
    }
    woord++;
    while (*woord != 0) {
        if (*woord < 'a' && *woord >= 'A') {
            *woord = *woord - 'A' + 'a';
        }
        woord++;
    }
}