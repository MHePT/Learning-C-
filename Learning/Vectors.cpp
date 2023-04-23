#include "Vectors.h"

V::V(int a0, int a1){
    vec.push_back(a0);
    vec.push_back(a1);
}

V V::operator+(V& arg){// Adding two vectors
    V res;

    for (int i = 0; i < arg.vec.size(); i++)
        res.vec[i] = vec[i] + arg.vec[i];

    return res;
}

V V::operator>>(int arg){// Bitwise Shifting the vector elements

    V res(*this);

    for (int i = 0; i < 2; i++)
        res.vec[i] >>= arg;

    return res;
}

V V::operator++(int) {//Can not be implemented as a global function
    //Must have dummy int parameter for the compiler and must not used
    //It's the postfix operator

    V v(*this);

    for (int i = 0; i < 2; i++)
        ++vec[i];

    return v;//Obligatory

}

V& V::operator=(V& arg){//Dummy overloading

    for (int i = 0; i < arg.vec.size(); i++)
        vec[i] = arg.vec[1 - i];

    return *this;// Obligatory

}

V& V::operator+=(V& arg){//Can not be implemented as a global function

    for (int i = 0; i < arg.vec.size(); i++)
        vec[i] += arg.vec[i];

    return *this;//Obligatory
}

V& V::operator++(){//Can not be implemented as a global function
    //Must be parameter-less
    //It's the prefix operator
    for (int i = 0; i < vec.size(); i++)
        vec[i]++;

    return *this;//Obligatory
}

V& operator+(V& left, V& right) {
    V* res = new V(0, 0);

    for (int i = 0; i < 2; i++)
        res->vec[i] = left.vec[i] + right.vec[i];

    return *res; //Obligatory returns refrence same object
}

bool V::operator==(V& arg){

    for (int i = 0; i < arg.vec.size(); i++)
        if (vec[i] != arg.vec[i])
            return false;

    return true;
}

int operator*(V& left, V& right){//Dot product

    int res = 0;
    if (left.vec.size() != right.vec.size())
        throw "Not Allowed";
    for (int i = 0; i < left.vec.size(); i++)
        res += left.vec[i] * right.vec[i];

    return res;
}

int operator~(V& arg){//Product of all elements in vector

    int res = 1;

    for (int i = 0; i < arg.vec.size(); i++)
        res *= arg.vec[i];

    return res;
}

bool operator>(V& l, V& r){
    return l.vec[0] + l.vec[1] > r.vec[0] + r.vec[1]; //Obligatory return bool
}

void runVector() {

	vector<int> v1{ 0,0,0,0 }; //1D Vector Pre-Defined = vector<int> v1[4]; equavilant to int v1[]=new int[4]; or int v1[]={0,0,0,0};
	vector< vector<int>> v2(3, vector<int>(5)); //2D 3x5 Vector Named v2
	vector< vector< vector<int> > > v3(3, vector< vector<int> >(5, vector<int>(6))); //3D 3x5x6 Vector Named v3

	//array of pointers to create triangular array
	int** ptrarr = new int*[5];
	for (int i = 0; i < 5;i++) {
		i[ptrarr] = new int[i + 1];
	}

}