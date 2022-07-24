#include "static_function-generator.h"
#include <stdio.h>
#include <math.h>

double intern_function_sawblade (float x)
{
	double y = 0.0;

	//sawblade function: f(x)=sin(x) + sin(2x)/2 + sin(3x)/3 + ... + sin(i*x)/i
	//y gets more precise, if i increases
	for (int i=1; i<21; i++)
	{
		y=y + sin(i*x)/i;
	}
	#ifdef DEBUG
	printf("//DEBUG: %.2f, %.3lf \n", x, y);
	#endif
	return y;
}

void static_function_generator(int amount_of_values, float x_step, FILE * outstream_x, FILE * outstream_y) 
{	
	#ifdef DEBUG
	printf("//DEBUG: amount_of_values: %i\n", amount_of_values);
	printf("//DEBUG: x_step: %f\n", x_step);
	#endif
	//declarations:
	double y_value;

	//call function and print to outstream
	for (int i=0; i<amount_of_values; i++)
	{
		fprintf(outstream_x, "%.2f  \n", x_step * i);
		fprintf(outstream_y, "%.3lf \n", intern_function_sawblade(x_step * i));
	}

	#ifdef DEBUG	
	printf("//DEBUG: application finished\n");
	#endif
}
