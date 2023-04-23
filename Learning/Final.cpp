#include "Final.h"

Fraction::Fraction(int  Numerator, int Denominator) : Numerator(Numerator), Denominator(Denominator){
    if (this->Denominator == 0)
        throw std::domain_error("bad fraction");
};

string Fraction::to_string(){//Sends the outpu to internal buffer can be accessed through str() Method 
    ostringstream os;
    os << "[" << Numerator << "/" << Denominator << "]";
    return os.str();
}

double Fraction::get_double(){
    return double(Numerator) / double(Denominator);
}

Fraction Fraction::operator!(){//Reducing the fraction
    int gcd = Greater_Common_Divisor(Numerator, Denominator);
    return Fraction(Numerator / gcd, Denominator / gcd);
}

Fraction Fraction::operator+(Fraction arg){

    int common_denom = Lower_Common_Multiplier(Denominator, arg.Denominator);

    int new_numer = Numerator * common_denom / Denominator +
        arg.Numerator * common_denom / arg.Denominator;

    Fraction f(new_numer, common_denom);

    return f;
}

Fraction& Fraction::operator+=(Fraction arg) {

    int common_denom = Lower_Common_Multiplier(Denominator, arg.Denominator);

    int numera = Numerator * common_denom / Denominator +
        arg.Numerator * common_denom / arg.Denominator;

    Numerator = numera;
    Denominator = common_denom;

    return *this;
}

Fraction Fraction::operator*(Fraction arg){

    int numera = Numerator * arg.Numerator;
    int denomi = Denominator * arg.Denominator;

    Fraction f(numera, denomi);

    return !f;
}

Fraction Fraction::operator/(Fraction arg){

    if (arg.Numerator == 0)
        throw domain_error("division by zero");

    int numera = Numerator * arg.Denominator;

    int denomi = Denominator * arg.Numerator;

    Fraction f(numera, denomi);

    return !f;
}

ostream& operator<< (ostream& ostr, Fraction& f){
    return ostr << f.to_string();
}

int Fraction::Lower_Common_Multiplier(int x, int y){
    int i = y;

    while (y % x)
        y += i;

    return y;
}

int Fraction::Greater_Common_Divisor(int x, int y){
    for (;;) {
        x %= y;
        if (!x)
            return y;

        y %= x;
        if (!y)
            return x;
    }
}

void run_final() {

    Fraction f1(1, 2), f2(2, 3), f;

    cout << f1 << "->" << f1.get_double() << endl;
    cout << f2 << "->" << f2.get_double() << endl;

    f = f1 + f2;
    cout << f1 << "+" << f2 << "=" << f << endl;

    f = f2 + f2 + f2;
    cout << f2 << "+" << f2 << "+" << f2 << "=" << f << endl;

    f = !f;
    cout << f2 << "+" << f2 << "+" << f2 << "=" << f << endl;

    f = f1 * f2;
    cout << f1 << "*" << f2 << "=" << f << endl;

    f = f1 / f2;
    cout << f1 << ":" << f2 << "=" << f << endl;

    Fraction f3(7, 8);
    f3 += f1;
    cout << f3 << endl;
}/*Output
~[1/2]->0.5
~[2/3]->0.666667
~[1/2]+[2/3]=[7/6]
~[2/3]+[2/3]+[2/3]=[6/3]
~[2/3]+[2/3]+[2/3]=[2/1]
~[1/2]*[2/3]=[1/3]
~[1/2]:[2/3]=[3/4]
~[11/8]
*/
