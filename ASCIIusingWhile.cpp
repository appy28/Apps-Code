//============================================================================
// Name        : ASCIIusingWhile.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	char mychar = 'a';
	while(mychar <= 'z')
	{
	cout << mychar << "::" << static_cast<int>(mychar)<< endl;
	++mychar;
	}
	return 0;
}
