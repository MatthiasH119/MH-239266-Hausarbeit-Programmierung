//      Autor:          Matthias Heiming
//      Mail:           matthias.heiming@stud.thga.de
//      Matr. Nr.:	239266
//      Datum:          24.07.2022
//
//      Hausarbeit:      Aufgabe 07 - Funktionsgenerator

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include "header_help-catalogue.h"
#include <static_function-generator.h>

char version[]="V00.1";

int main(int argc,char *argv[])
{
    char *vvalue = NULL;
    int option;
    int option_switch = 0;
    opterr = 0;

    FILE * outstream;

    while ((option = getopt(argc, argv, "hv")) != -1)
        switch (option)
        {
        //void print_gaussian_dist ( float expected_value, float std_deviation , int amount_of_values, FILE ∗ output_stream)
        // -h (help):
        case 'h':
            header_help_catalogue();
            option_switch++;
	    break;
        // -v Version
        case 'v':
            printf("%s \n", version);
            option_switch++;
	    break;
        //optional error handling
        case '?':
            if (isprint (optopt))//is character printable
            {
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            }
            else
            {
                fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
            }
	     header_help_catalogue();
            return 1;
        default:
            abort ();
        }


    //Programmaufruf
    if (option_switch == 0) {
    	printf("\n... starting application ...\n");
        outstream = fopen("outstram.txt", "w");

	static_function_generator(outstream);
        
	fclose(outstream);
    }

    return 0;
}
