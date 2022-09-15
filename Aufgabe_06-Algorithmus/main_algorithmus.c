//      Autor:          Matthias Heiming
//      Mail:           matthias.heiming@stud.thga.de
//      Matr. Nr.:      239266
//      Datum:          09.08.2022
//
//      Hausarbeit:      Aufgabe 06 - Algorithmus - Suche nach längster Reihe an Primzahlen in einem instream

#include <stdio.h>
#include <stdlib.h>

#define MAX 200      //Hoechste Zahl im Instream
#define ANZAHL  200  //Anzahl Zahlen im Instream

char version[]="V0.7";

int primzahlliste[MAX];

//Funktion zum erstllen der Primzahlliste
void primzahlliste_erstellung()
{
    int primzahlliste_zaehler = 0;
    for (int i=2; i<MAX; i++)
    {
        char pruefstempel = 't';
        for (int j=2; j<i; j++)
        {
            if (i % j == 0)
            {
                pruefstempel = 'f';
                break;
            }
        }
        if (pruefstempel == 't')
        {
            primzahlliste[primzahlliste_zaehler] = i;
            primzahlliste_zaehler++;
        }
    }
    for (int i=0; i<MAX; i++)
    {
        if (primzahlliste[i] == 0)
            primzahlliste[i] = -1;
    }
    #ifdef DEBUG
    printf("Primzahlliste: {");
    for (int i; i<MAX; i++)
    {
        if (primzahlliste[i] != 0)
            printf("%i, ", primzahlliste[i]);
        else
            break;
    }
    printf("} \n");
    #endif
}

//Funktion zum pruefen, ob eine Zahl eine Primzahl ist
int primzahl_pruefung(int zahl)
{
    #ifdef DEBUG
    printf("\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: zahl: %i\x1b[0m", zahl);
    #endif
    for (int i=0; i<MAX; i++)
    {
        if (primzahlliste[i] == zahl)
        {
	    #ifdef DEBUG
            printf("\t\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: \x1b[32mreturn 1 \x1b[0m\n");
	    #endif
            return 1;
        }
        else if (primzahlliste[i] == -1)
            break;
    }
    #ifdef DEBUG
    printf("\t\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: \x1b[31mreturn 0 \x1b[0m\n");
    #endif
    return 0;
}

int main()
{
    primzahlliste_erstellung();
    FILE * in_zahlenreihe;
    in_zahlenreihe = fopen("zahlenreihe.txt", "r");

    int zahlenreihe[ANZAHL];

    for (int i=0; i<ANZAHL; i++)
    {
        fscanf(in_zahlenreihe, " %i,", &zahlenreihe[i]);
    }

    int stelle_max = 0;
    int max = 0;

    for(int i=0; i<ANZAHL; i++)
    {
	#ifdef DEBUG
        printf("\x1b[35m i = %i \x1b[30m\n", i);
	#endif
        if (primzahl_pruefung(zahlenreihe[i]) == 1)
        {
            int x = 0;
            for(int j=1; x<1; j++)
            {
		#ifdef DEBUG
                printf("\x1b[35m j = %i \x1b[30m\n", j);
		#endif
                if (primzahl_pruefung(zahlenreihe[i+j]) == 0)
                {
                    if(j>max)
                    {
                        max = j;
                        stelle_max = i;
                    }
                    i = i + j;
                    x=1;
                }
            }
        }
    }

    if (max < 2)
        printf("In der Zahlenreihe gibt es keine Primzahlreihe ! \n");
    else
    {
        printf("Die längste Reihe von Primzahlen in der Zahlenreihe ist %i Primzahlen lang.\n", max);
        printf("Die Zahlen lauten: ");

        for(int i=stelle_max; i < stelle_max+max; i++)
        {
            printf("%i, ", zahlenreihe[i]);
        }
        printf("\n");
    }
    fclose(in_zahlenreihe);
    return 0;
}
