#include <stdio.h>
int main() {
    int t[6] = {0, 10, 20, 30, 40, 50};
    int *pt[3];  // array van pointers naar int

    for (int i = 0; i < 3; i++) {
        pt[i] = &t[2 * i];  // opvulling van het pointerarray met verwijzingen naar het 1ste, 3de en 5de element van t (0,20,30)
    }

    pt[1]++;        // de 2de pointer in het pt array wijst nu naar het volgend element in t, 30
    pt[2] = pt[1];  // de derde pointer wijst nu naar hetzelfde als pt1, 30
    *pt[1] += 1;    // incrementeer de waarde waar pt[1] naar wijst met 1, 30 + 1 = 31
    *pt[2] *= 2;    // vermenigvuldig de waarde waar pt[2] naar wijst (zelfde waarde als pt[1]) met 2, 31*2=32

    int **ppt = &pt[0];  // maak een pointer naar pointer aan die wijst naar de eerste pointer in het pt array
    (*ppt)++;            // schuif de pointer waar ppt naar wijst(pt[0]) op, pt[0] wijst dan naar 10
    **ppt += 1;          // incrementeer de waarde waar pt[0] naar wijst, 10+1=11

    for (int i = 0; i < sizeof(t) / sizeof(t[0]); i++) {  // bijvraag, gebruik maken van sizeof :)
        printf("%d ", t[i]);
    }
    printf("\n");
    for (int i = 0; i < sizeof(pt) / sizeof(pt[0]); i++) {
        printf("%d ", *pt[i]);
    }
    printf("\n");
    return 0;
}