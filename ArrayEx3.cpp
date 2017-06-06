//============================================================================
// Name        : ArrayEx3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const int arrayLength(9);
	int array[arrayLength] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	int number;

	do
	{
	cout<<"Please Enter Number between 1 to 9 ::";
	cin>>number;

	// if the user entered something invalid
	if (cin.fail())
	{
	    cin.clear(); // reset any error flags
	}
	    cin.ignore(32767, '\n'); // ignore any characters in the input buffer

	}while(number < 1 && number > 9);

	for (int index=0;index<arrayLength;index++)
        cout<<array[index]<<" ";

	cout<<"\n";

	for (int index=0;index<arrayLength;index++)
	{
		if(array[index] == number)
		{
			cout <<"The number user has chosen is at "<<index<< " index"<<endl;
		    break;
		}
	}
	return 0;
}


