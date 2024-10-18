#include <stdio.h>

void lees_input(int frequenties[]);
void teken_horizontaal(int frequenties[]);
void teken_verticaal(int frequenties[]);
char hoofdletter_naar_kleine(char letter);
int meest_aantal_letters(int frequenties[]);
int main() {
    int frequenties[26] = {0};
    lees_input(frequenties);
    teken_horizontaal(frequenties);
    teken_verticaal(frequenties);

    return 0;
}

char hoofdletter_naar_kleine(char letter) {
    return (char)(int)letter + ((int)'a' - (int)'A');
}

void lees_input(int frequenties[]) {
    char input_char;
    while (scanf("%c", &input_char) == 1 && input_char != '$') {
        if ((int)input_char >= (int)'A' && (int)input_char <= (int)'Z') {  // is de letter een hoofdletter
            input_char = hoofdletter_naar_kleine(input_char);              // maak van de hoofdletter een kleine letter
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
int meest_aantal_letters(int frequenties[]) {
    int grootste = 0;
    for (int i = 0; i < 26; i++) {
        if (frequenties[i] > grootste) {
            grootste = frequenties[i];
        }
    }
    return grootste;
}
void teken_verticaal(int frequenties[]) {
    printf("max voorkomend = %d\n", meest_aantal_letters(frequenties));

    for (int i = meest_aantal_letters(frequenties); i > 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (frequenties[j] == i) {
                frequenties[j]--;
                printf("%c", j + (int)'a');
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
