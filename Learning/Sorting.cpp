#include <iostream>
#include <vector>

using namespace std;


inline void Bubble_Sort(vector<int>& numbers) {

	bool swapped;


	do { // we will decide if we need to continue this loop 

		swapped = false; // no swap occured yet



		for (int i = 0; i < 4; i++)
		{

			if (numbers[i] > numbers[i + 1]) {

				swapped = true;

				int aux = numbers[i];

				numbers[i] = numbers[i + 1];

				numbers[i + 1] = aux;

			}
		}

	} while (swapped);

	//return swapped;
}

void Bubble_Sort_Modified(int how_many_numbers) {

	if (how_many_numbers <= 0 || how_many_numbers > 1000000) {

		cout << "Are you kidding?" << endl;

		return;

	}

	int* numbers = new int[how_many_numbers];

	for (int i = 0; i < how_many_numbers; i++) {

		cout << "\nEnter the number #" << i + 1 << ": ";

		cin >> numbers[i];

	}

	bool swapped;

	do {

		swapped = false;

		for (int i = 0; i < how_many_numbers - 1; i++)

			if (numbers[i] > numbers[i + 1]) {

				swapped = true;

				int aux = numbers[i];

				numbers[i] = numbers[i + 1];

				numbers[i + 1] = aux;

			}

	} while (swapped);

	cout << endl << "The sorted array:" << endl;

	for (int i = 0; i < how_many_numbers; i++)

		cout << numbers[i] << " ";

	cout << endl;

	delete[] numbers;

}

