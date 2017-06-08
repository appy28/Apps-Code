//============================================================================
// Name        : BubblesortEx1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const int length(9);
	int array[length] = { 6, 3, 2, 9, 7, 1, 5, 0, 0 };

	for (int startIndex=0;startIndex<length-1;startIndex++)
	{
		for (int currentIndex=0;currentIndex<length-1;currentIndex++)
		{
			if(array[currentIndex]>array[currentIndex+1])
				swap(array[currentIndex],array[currentIndex+1]);
		}
		for(int index=0;index<length;index++)
			cout<<array[index]<<' ';

		cout<<"\n";
	}

	return 0;
}
