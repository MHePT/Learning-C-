/*#include <iostream>using namespace std; // Global standard namespacenamespace Hogwarts { //original name space
	int troll = 1;
}

namespace Mordor { //original name space
	int troll = 2;
}

namespace Hogwarts { //extension name space
	float wizard = -0.5;
}

namespace Mordor { //extension name space
	float wizard = 0.5;
}

namespace {
	int Troll = 1;
	float Wizard = -0.5;
}

void run()
{	using Mordor::troll;
	using Hogwarts::wizard;	namespace lets_make_new_name = std;
    cout << Hogwarts::troll << " " << wizard << endl;	lets_make_new_name::cout << Troll << " " << Wizard << endl;
	cout << troll << " " << Mordor::wizard << endl;
}*/
