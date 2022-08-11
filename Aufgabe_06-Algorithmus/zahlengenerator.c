#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 200
#define SIZE 100
#define NUMS_TO_GENERATE 200

//Version: V0.1

int main() {

        int zufallszahlen[NUMS_TO_GENERATE];

        FILE * outstream;
        outstream = fopen("zahlenreihe.txt", "w");

	
	srand(time(NULL));
        for (int i = 0; i < NUMS_TO_GENERATE; i++){
                zufallszahlen[i] = rand() % MAX;
        }

        for (int i = 0; i < NUMS_TO_GENERATE; i++){
                fprintf(outstream, "%d, ", zufallszahlen[i]);
        }

        fclose(outstream);

        return 0;
}
