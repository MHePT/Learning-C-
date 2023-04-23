#include "Namespaces.h"

void run(){
	using Mordor::troll;
	using Hogwarts::wizard;
	namespace lets_make_new_name = std;

    cout << Hogwarts::troll << " " << wizard << endl;

	lets_make_new_name::cout << Troll << " " << Wizard << endl;

	cout << troll << " " << Mordor::wizard << endl;
}