#pragma once
#ifndef __NAMESPACES__
#define __NAMESPACES__

#include <iostream>

using namespace std; // Global standard namespace

namespace Hogwarts { //original name space
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


void run();

#endif // !__NAMESPACES__