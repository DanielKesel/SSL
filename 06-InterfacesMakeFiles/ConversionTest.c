#include <stdio.h>
#include "Conversion.h"
#include <assert.h>


int main(void){
	
	// Funciona conversor de Fahrenheit a Celcius
	assert(Celcius(32)==0);
	assert(Celcius(104)==40);
	assert(Celcius(248)==120);
	assert(Celcius(428)==240);
	
	// Funciona conversor de Celcius a Fahrenheit
	assert(Fahrenheit(0)==32);
	assert(Fahrenheit(40)==104);
	assert(Fahrenheit(120)==248);
	assert(Fahrenheit(428)==240);
	 
}
