#include "LargestNumber.h"

int Largest(int number1, int number2){ // can be invoked like this Largest(Largest(a,b),c); but it’s neither nice nor effective. 

	/* we will save the larger number here

	 we temporarily assume that the former number is the larger one

	 we will check it soon */

	int max = number1;

	/* we check if the assumption was false */

	if (number2 > max)
		max = number2;

	/* we retrun the result */

	return max;
}

double Largest(double number1, float number2) {
	return number1 > number2 ? number1 : number2;
}

int Largest(int number1, int number2, int number3) {

	int max = number1;

	if (number2 > max)
		max = number2;

	if (number3 > max)
		max = number2;

	return max;
}

float max(float number1, float number2, float number3){
	return number1 > number2 ?
		(number1 > number3 ? number1 : number3) : (number2 > number3 ? number2 : number3);
}

