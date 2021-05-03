
#include <stdio.h>
#include "Conversion.h"

const int LOWERF = 0; // lower limit of table
const int UPPERF = 300; // upper limit
const int STEPF = 20; // step size

const int LOWERC = -17; // lower limit of table
const int UPPERC = 148; // upper limit
const int STEPC = 11; // step size


int main(void){
	
	 printf("Conversion de Fahrenheit a Celsius \n");
	 
	 for(int fahr = LOWERF; fahr <= UPPERF; fahr = fahr + STEPF){
	 	
	 printf("%3d %6.1f\n", fahr, Celcius(fahr) ); 
 	 fahr = fahr + STEPF;
 	 
	 };
	 
	 printf("Conversion de Celcius a Fahrenheit \n");
	 
	 for(int cels = LOWERC; cels <= UPPERC; cels = cels + STEPC){
	 	
	 printf("%3d %6.1f\n", cels, Fahrenheit(cels) );
	 
	 };
	 
}
