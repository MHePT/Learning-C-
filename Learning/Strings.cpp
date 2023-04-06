#include <string>
#include <iostream>

using namespace std;

void runStrings() {
	string name("String");
	string name2 = "";

	getline(cin, name2);

	if (name == name2)
		cout << "\"" << name << "\" == \"" << name2 << "\"" << endl;

	else if (name > name2)
		cout << "\"" << name << "\" > \"" << name2 << "\"" << endl;

	else
		cout << "\"" << name2 << "\" > \"" << name << "\"" << endl;
}