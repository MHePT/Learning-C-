#include "Strings.h"

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

	for (int i = 0; i < 100; i++)//Will crash due to high upper limit
		the_string += the_string;

	print_info(the_string);

	the_string.reserve(100);//capacity 100

	print_info(the_string);

	the_string.reserve(0);//capacity 15

	print_info(the_string);

	the_string.resize(50, '?');//content??????????????????????????????????????????? null '\0' is default

	print_info(the_string);

	the_string.resize(4);//cont ,capacity 50

	print_info(the_string);

	the_string.clear();// "" ,capacity 50

	print_info(the_string);

	the_string = "content";

	for (int i = 0; i < the_string.length(); i++)
		the_string[i] = the_string[i] - 'a' + 'A';
	cout << the_string << endl; // CONTENT

	string str1 = "content";  str1.append(3, 'x');// str1 contains "contentxxx" now
	str1 = "content";  str1.append("tail", 1, 3);// str1 contains "contentail" now
	str1 = "content";  str1.append("appendix");// str1 contains "contentappendix" now

	for (char c = 'A'; c <= 'Z'; c++)
		the_string.push_back(c);
	cout << the_string << endl; //CONTENTABCDEFGHIJKLMNOPQRSTUVWXYZ

	string quote = "Whyserious?", anyword = "monsoon";
	quote.insert(3, 2, ' ').insert(4, anyword, 3, 2);
	cout << quote << endl;// Why so serious?

	string sky;
	cout << sky.assign(80, '*') << endl;//"********************************************************************************"

	string to_do = "I'll think about that in one hour";
	string schedule = "today yesterday tomorrow";
	cout << to_do.replace(22, 12, schedule, 16, 8) << endl;// I'll think about that tomorrow

	string where_are_we = "I've got a feeling we're not in Kansas anymore";
	cout << where_are_we.erase(38, 8).erase(25, 4) << endl;

	string drink = "A martini";
	string needs = "Shaken, not stirred";
	cout << drink << ". " << needs << "." << endl;
	drink.swap(needs);
	cout << drink << ". " << needs << "." << endl;

}

void print_info(string& s)

{

	cout << "length = " << s.length() << endl;

	cout << "capacity = " << s.capacity() << endl;

	cout << "max size = " << s.max_size() << endl;

	cout << "is empty? " << (s.empty() ? "yes" : "no") << endl;

	cout << "---------" << endl;

}