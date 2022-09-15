//      Autor:          	Cedric-Julian Nettler                   |       Matthias Heiming
//      Mail:           	cedric-julian.nettler@stud.thga.de      |       matthias.heiming@stud.thga.de
//      Datum:          	28.06.2022
//
//	Angepasst/Überarbeitet:	Matthias Heiming, 09.08.2022
//
//      Hausarbeit Matthias Heiming, Aufgabe 06 - Zahlengenerator
//	Der Zahlengenerator wurde aus dem Praktikum nr. 9 übernommen und für die Aufgabe 06 der Hausarbeit angepasst.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 200
#define NUMS_TO_GENERATE 200

//Version: V0.2

int main() {

    int zufallszahlen[NUMS_TO_GENERATE];

    FILE * outstream;
    outstream = fopen("zahlenreihe.txt", "w");


    srand(time(NULL));
    for (int i = 0; i < NUMS_TO_GENERATE; i++) {
        zufallszahlen[i] = rand() % MAX;
    }

    for (int i = 0; i < NUMS_TO_GENERATE; i++) {
        fprintf(outstream, "%d, ", zufallszahlen[i]);
    }

    fclose(outstream);

    return 0;
}
