#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    const int van = 2;
    const int tot = 30;

    // int uitkomst = 1;  // correct tot 12!
    // long long uitkomst = 1; // correct tot 20!
    double uitkomst = 1;  // correct tot 21!, daarna afrondingsfouten

    for (int i = 1; i <= tot; i++) {
        uitkomst = uitkomst * i;

        if (i >= van) {
            // printf("%d! = %d \n", i, uitkomst); // voor int
            // printf("%d! = %lld \n", i, uitkomst); // voor long long
            printf("%d! = %f \n", i, uitkomst);  // voor double
        }
    }
    return 0;
}