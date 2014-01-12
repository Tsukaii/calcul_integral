#include <math.h>
#include <stdio.h>
//#include "simspon.h"

double f(double x){
	return sin(x);
}

//a, b : bornes de l'intervalle
double formuleSimpson(double a, double b){
	return ( (b-a)/6 ) * ( f(a) + 4*f((a+b)/2) + f(b) );
}

//a, b : bornes de l'intervalle
double methodeSimpson(double a, double b, double pas){
	
	double integrale = 0.0;
	double i = a;
	
	while(i <= b){
		integrale += formuleSimpson(i, i+pas);
		i+=pas;
	}
	
	return integrale;
}

int main(int argc, char *argv[]){
	printf("L'intégrale est égale à : %lf\n", methodeSimpson(1.0, 3.0, 0.2));
	
	return 0;
}

	
