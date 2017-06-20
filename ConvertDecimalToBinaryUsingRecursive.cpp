//============================================================================
// Name        : ConvertDecimalToBinaryUsingRecursive.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printBinary(int x)
{
	if (x <= 0)
		return;

	printBinary(x/2);

	cout<< x % 2 ;
}

int main() {

	int x;
	cout << "Enter an Integer = ";
	cin>>x;

	printBinary(x);

	return 0;
}
