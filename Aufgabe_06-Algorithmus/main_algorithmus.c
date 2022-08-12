//      Autor:          Matthias Heiming
//      Mail:           matthias.heiming@stud.thga.de
//      Matr. Nr.:      239266
//      Datum:          09.08.2022
//
//      Hausarbeit:      Aufgabe 06 - Algorithmus - Suche nach längster Reihe an Primzahlen in einem instream

#include <stdio.h>
#include <stdlib.h>

char version[]="V0.2";
int primzahlsieb[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

int primzahl_pruefung(int zahl)
{
    #ifdef DEBUG
    printf("\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: zahl: %i\x1b[0m", zahl);
    #endif
    for (int i=0; i<45; i++)
    {
	if (primzahlsieb[i] == zahl)
	{
		#ifdef DEBUG
		printf("\t\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: \x1b[32mreturn 1 \x1b[0m\n");
		#endif
		return 1;
	}
    }
    #ifdef DEBUG
    printf("\t\x1b[34m//DEBUG-PRIMZAHL-PRÜFUNG: \x1b[31mreturn 0 \x1b[0m\n");
    #endif
    return 0;
}

int main()
{
    FILE * in_zahlenreihe;
    in_zahlenreihe = fopen("zahlenreihe.txt", "r");

    int zahlenreihe[200];

    for (int i=0; i<200; i++)
    {
	fscanf(in_zahlenreihe, " %i,", &zahlenreihe[i]);
    }

    int stelle_max = 0;
    int max = 0;

    for(int i=0; i<199; i++)
    {
	#ifdef DEBUG
	printf("\x1b[35m i = %i \x1b[30m\n", i);
	#endif
	if (primzahl_pruefung(zahlenreihe[i]) == 1)
	{
	    printf("IF-SCHLEIFE \n");
	    int x = 0;
	    for(int j=1; x=0; j++)
	    {
    	        printf("FOR-SCHLEIFE\n");
	        #ifdef DEBUG
	        printf("\x1b[35m j = %i \x1b[30m\n", j);
	        #endif
	        if (primzahl_pruefung(zahlenreihe[i+j]) == 0)
		{
		    printf("j+i = %i \n", j+i);
		    if(j>max)
		    {
			printf("j > max \n");
			max = j;
			stelle_max = i;
		    }
		    x=1;
		}
	    }
	}
    }

    printf("Die längste Reihe von Primzahlen in der Zahlenreihe ist %i Primzahlen lang.\n", max);
    printf("Die Zahlen lauten: ");
    for(stelle_max; stelle_max < stelle_max + max; stelle_max++)
    {
	printf("%i, ", zahlenreihe[stelle_max]);
    }
    printf("\n");

    fclose(in_zahlenreihe);
    return 0;
}
