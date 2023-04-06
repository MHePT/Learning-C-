#include <string>
#include <iostream>

using namespace std;

void runStrings() {
	string name("String");
	string name2 = "";

	getline(cin, name2);

	if (name == name2) // if(name.compare(name2) == 0)
		cout << "\"" << name << "\" == \"" << name2 << "\"" << endl;

	else if (name > name2)// if(name.compare(name2) > 0)
		cout << "\"" << name << "\" > \"" << name2 << "\"" << endl;

	else
		cout << "\"" << name2 << "\" > \"" << name << "\"" << endl;



	string the_string = "content";

	print_info(the_string);

	for (int i = 0; i < 100; i++)

		the_string += the_string;

	print_info(the_string);
}

void print_info(string& s)

{

	cout << "length = " << s.length() << endl;

	cout << "capacity = " << s.capacity() << endl;

	cout << "max size = " << s.max_size() << endl;

	cout << "---------" << endl;

}