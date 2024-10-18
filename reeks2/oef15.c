#include <stdio.h>

void lees_input(int frequenties[]);
void teken_horizontaal(int frequenties[]);
void teken_verticaal(int frequenties[]);

int main() {
    int frequenties[26] = {0};
    lees_input(frequenties);
    // for (int i = 0; i < 26; i++) {
    //     printf("%c, ", (char)i + (int)'a');
    // }
    // printf("\n");
    // for (int i = 0; i < sizeof(frequenties) / sizeof(frequenties[0]); i++) {
    //     printf("%d, ", frequenties[i]);
    // }
    teken_horizontaal(frequenties);
    teken_verticaal(frequenties);

    return 0;
}
void lees_input(int frequenties[]) {
    char input_char;
    while (scanf("%c", &input_char) == 1 && input_char != '$') {
        if ((int)input_char >= (int)'A' && (int)input_char <= (int)'Z') {  // is de letter een hoofdletter
            input_char = (char)(int)input_char + ((int)'a' - (int)'A');    // maak van de hoofdletter een kleine letter
        }
        frequenties[(int)input_char - (int)'a']++;
    }
}
void teken_horizontaal(int frequenties[]) {
    for (int i = 0; i < 26; i++) {
        printf("%c:", i + (int)'a');
        for (int j = 0; j < frequenties[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
void teken_verticaal(int frequenties[]) {
}
