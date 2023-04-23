#pragma once
#ifndef __FINAL__
#define __FINAL__

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class Fraction {
	int Numerator , Denominator;
	int Lower_Common_Multiplier(int x, int y);
	int Greater_Common_Divisor(int x, int y);

public:
	Fraction(int Numerator = 0, int Denominator = 1);
    string to_string();
    double get_double();
    Fraction operator!();
    Fraction operator+(Fraction arg);
    Fraction operator*(Fraction arg);
    Fraction operator/(Fraction arg);
    Fraction& operator+=(Fraction arg);
};

ostream& operator<<(ostream& ostr, Fraction& f);
void run_final();

#endif // !__PROOPERATORS__
