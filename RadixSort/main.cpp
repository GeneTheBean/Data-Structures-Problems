// File: prg8_2.cpp
// the program initializes a 50-element vector with 5-digit random
// integers in the range 0 to 99999 and sorts the vector using the
// radix sort. it outputs the numbers in 6 columns using the
// function displayVector()

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <rSort.h>
#include <Queue.h>

#include "d_sort.h"

using namespace std;

// output v, 6 elements per line
void displayVector(const vector<int>& v);

int main()
{
	// vector to hold the data that is sorted
	vector<int> intVector;

	int i;

	// initialize vector with 50 random numbers in range 0 - 99999
	for (i = 0; i < 50; i++)
		intVector.push_back(rand() % 100000);

	// apply the radix sort and output the sorted vector
	radixSort(intVector);
	displayVector(intVector);

	return 0;
}

void displayVector(const vector<int>& v)
{
	int i;

	for (i=0; i < v.size(); i++)
	{
		// output each element in 12 spaces
		cout << setw(12) << v[i];
		if ((i+1) % 6 == 0)		// newline every 6 numbers
			cout << endl;
	}
	cout << endl;
}


