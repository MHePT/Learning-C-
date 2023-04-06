#include <iostream>
#include <vector>

using namespace std;

inline void runVector() {

	vector<int> v1{ 0,0,0,0 }; //1D Vector Pre-Defined = vector<int> v1[4]; equavilant to int v1[]=new int[4]; or int v1[]={0,0,0,0};
	vector< vector<int>> v2(3, vector<int>(5)); //2D 3x5 Vector Named v2
	vector< vector< vector<int> > > v3(3, vector< vector<int> >(5, vector<int>(6))); //3D 3x5x6 Vector Named v3


}