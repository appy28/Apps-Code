//============================================================================
// Name        : doubleNum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int DoubleNum(int x)
{
	return 2*x;
}
int main() {
	int y;
	cout<<"Enter a number:"<<endl;
	cin>>y;
	cout << "given Numbers Double value is" <<DoubleNum(y)<< endl;
	return 0;
}
