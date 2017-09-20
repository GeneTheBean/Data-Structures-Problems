//
//  main.cpp
//
//

#include <iostream>
#include "Stack.h"
#include "Stack_A.h"

using namespace std;

int main(int argc, const char * argv[]) {

	Stack <int> testStack;
	cout << endl << endl <<"Testing stack implemented with a vector" << endl;
	cout << "Is stack empty? " << (testStack.isEmpty()? "Yes" : "No") << endl;
	int value = 3;
	int secondValue = 5;
	int topValue;

	cout << "Original numbers: " << endl;
	cout << "first value = " << value << " second value = " << secondValue << endl;

	testStack.push (value);
	cout << "Is stack empty after one push? " << (testStack.isEmpty()? "Yes" : "No") << endl;

	testStack.push (secondValue);
	topValue = testStack.top();
	testStack.pop();
	cout << "First popped value = " << topValue << endl;
	topValue = testStack.top();
	testStack.pop();
	cout << "Second popped value = " << topValue << endl;

	cout << "Testing pushing 50 elements" << endl;
	for (int i = 0;i<50;i++)
		testStack.push(i);

	cout << endl << endl <<"Testing stack implemented with an array" << endl;
	Stack_A <int> testStack_A;
	cout << "Is stack empty? " << (testStack_A.isEmpty()? "Yes" : "No") << endl;

	testStack_A.push (value);
	cout << "Is stack empty after one push? " << (testStack.isEmpty()? "Yes" : "No") << endl;
	testStack_A.push (secondValue);
	topValue = testStack_A.top();
	testStack_A.pop();
	topValue = testStack_A.top();
	cout << "Is stack empty after popping? " << (testStack_A.isEmpty()? "Yes" : "No") << endl;
	cout << "Testing pushing more elements than size of array" << endl;
	for (int i = 0;i<20;i++)
		testStack_A.push(i);

	cout << endl << endl;
}
