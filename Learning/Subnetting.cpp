#include "Subnetting.h"

void Network4(string Network, string Mask) {

	vector<int> net{ 0,0,0,0 };
	vector<int> mask{ 0,0,0,0 };
	int start = 0, por = 0;


	for (int i = 0; i < Network.size(); i++) {
		if (Network[i] == '.') {
			net[por++] = stoi(Network.substr(start, i));
			start = i + 1;
		}
		if (por == 3)
			net[por++] = stoi(Network.substr(start));
	}

	start = por = 0;

	if (Mask.size() > 3) {

		for (int i = 0; i < Mask.size(); i++) {
			if (Mask[i] == '.') {
				mask[por++] = stoi(Mask.substr(start, i));
				start = i + 1;
			}
			if (por == 3)
				mask[por++] = stoi(Mask.substr(start));
		}

	}
	else
		SubnetMask_Intialize(mask, Mask);


	for (int i = 0; i < 4; i++)
		cout << (int)(net[i] & mask[i]) << ".";


}




void SubnetMask_Intialize(vector<int>& mask, string Mask) {

	if (Mask == "/32" || Mask == "32") {
		for (int i = 0; i < 4; i++)
			mask[i] = 0b11111111;
	}
	else if (Mask == "/31" || Mask == "31") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
		mask[3] = 0b11111110;
	}
	else if (Mask == "/30" || Mask == "30") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
		mask[3] = 0b11111100;
	}
	else if (Mask == "/29" || Mask == "29") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
		mask[3] = 0b11111000;
	}
	else if (Mask == "/28" || Mask == "28") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
		mask[3] = 0b11110000;
	}
	else if (Mask == "/27" || Mask == "27") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
		mask[3] = 0b11100000;
	}
	else if (Mask == "/26" || Mask == "26") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
		mask[3] = 0b11000000;
	}
	else if (Mask == "/25" || Mask == "25") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
		mask[3] = 0b10000000;
	}
	else if (Mask == "/24" || Mask == "24") {
		for (int i = 0; i < 3; i++)
			mask[i] = 0b11111111;
	}
	else if (Mask == "/23" || Mask == "23") {
		for (int i = 0; i < 2; i++)
			mask[i] = 0b11111111;
		mask[2] = 0b11111110;
	}
	else if (Mask == "/22" || Mask == "22") {
		for (int i = 0; i < 2; i++)
			mask[i] = 0b11111111;
		mask[2] = 0b11111100;
	}
	else if (Mask == "/21" || Mask == "21") {
		for (int i = 0; i < 2; i++)
			mask[i] = 0b11111111;
		mask[2] = 0b11111000;
	}
	else if (Mask == "/20" || Mask == "20") {
		for (int i = 0; i < 2; i++)
			mask[i] = 0b11111111;
		mask[2] = 0b11110000;
	}
	else if (Mask == "/19" || Mask == "19") {
		for (int i = 0; i < 2; i++)
			mask[i] = 0b11111111;
		mask[2] = 0b11100000;
	}
	else if (Mask == "/18" || Mask == "17") {
		for (int i = 0; i < 2; i++)
			mask[i] = 0b11111111;
		mask[2] = 0b11000000;
	}
	else if (Mask == "/16" || Mask == "16") {
		for (int i = 0; i < 2; i++)
			mask[i] = 0b11111111;
		mask[2] = 0b10000000;
	}
	else if (Mask == "/15" || Mask == "15") {
		mask[0] = 0b11111111;
		mask[1] = 0b11111110;
	}
	else if (Mask == "/14" || Mask == "14") {
		mask[0] = 0b11111111;
		mask[1] = 0b11111100;
	}
	else if (Mask == "/13" || Mask == "13") {
		mask[0] = 0b11111111;
		mask[1] = 0b11111000;
	}
	else if (Mask == "/12" || Mask == "12") {
		mask[0] = 0b11111111;
		mask[1] = 0b11110000;
	}
	else if (Mask == "/11" || Mask == "11") {
		mask[0] = 0b11111111;
		mask[1] = 0b11100000;
	}
	else if (Mask == "/10" || Mask == "10") {
		mask[0] = 0b11111111;
		mask[1] = 0b11000000;
	}
	else if (Mask == "/9" || Mask == "9") {
		mask[0] = 0b11111111;
		mask[1] = 0b10000000;
	}
	else if (Mask == "/8" || Mask == "8") {
		mask[0] = 0b11111111;
	}
	else if (Mask == "/7" || Mask == "7") {
		mask[0] = 0b11111110;
	}
	else if (Mask == "/6" || Mask == "6") {
		mask[0] = 0b11111100;
	}
	else if (Mask == "/5" || Mask == "5") {
		mask[0] = 0b11111000;
	}
	else if (Mask == "/4" || Mask == "4") {
		mask[0] = 0b11110000;
	}
	else if (Mask == "/3" || Mask == "3") {
		mask[0] = 0b11100000;
	}
	else if (Mask == "/2" || Mask == "2") {
		mask[0] = 0b11000000;
	}
	else if (Mask == "/1" || Mask == "1") {
		mask[0] = 0b10000000;
	}
}