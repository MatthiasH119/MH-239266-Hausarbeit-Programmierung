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

char version[]="V01.2";

int main(int argc,char *argv[])
{
    char *vvalue = NULL;
    int option;
    int option_switch = 0;
    int amount_of_values = 100;
    int sawblade_function_resolution = 20;
    float x_step = 0.1;
    opterr = 0;

    FILE * outstream_x;
    FILE * outstream_y;

    while ((option = getopt(argc, argv, "hn:r:v")) != -1)
        switch (option)
        {
        //void print_gaussian_dist ( float expected_value, float std_deviation , int amount_of_values, FILE ∗ output_stream)
        // -h (help):
        case 'h':
            header_help_catalogue();
            option_switch++;
	    break;
	// -n amount of values
	case 'n':
	    amount_of_values = atoi(optarg);
	    if (amount_of_values < 100)
	        {
		printf("%i values are not enough, amount set to 100.\n", amount_of_values);
		amount_of_values = 100;
		}
            break;
	// -r precision of the sawblade function
	case 'r':
            sawblade_function_resolution = atoi(optarg);
            if (sawblade_function_resolution < 1)
                {
                printf("%i is a too little sawblade resolution, resolution set to 1.\n", sawblade_function_resolution);
                sawblade_function_resolution = 1;
                }
            break;
        // -v Version
        case 'v':
            printf("%s \n", version);
            option_switch++;
	    break;
        //optional error handling
        case '?':
	    if (optopt == 'n' || optopt == 'r')
            {
                fprintf (stderr, "There are rules! -%c requires an argument! \n", optopt);
            }
	    else if (isprint (optopt))//is character printable
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


    //start program
    if (option_switch == 0) {
	#ifdef DEBUG
	printf("//DEBUG: starting application\n");
	#endif
	outstream_x = fopen("outstream_x.txt", "w");
	outstream_y = fopen("outstream_y.txt", "w");
	
	static_function_generator(amount_of_values, x_step, sawblade_function_resolution, outstream_x, outstream_y);
        
	fclose(outstream_x);
	fclose(outstream_y);
    }

    return 0;
}
