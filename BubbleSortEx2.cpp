//============================================================================
// Name        : BubbleSortEx2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<algorithm>
#include <iostream>
using namespace std;

int main() {
	const int length(9);
		int array[length] = { 6, 3, 2, 9, 7, 1, 5, 8, 4 };

		for (int iteration=0;iteration<length-1;iteration++)
		{
			int endOfArrayIndex =(length-iteration);
			bool swapped(false);

			for (int currentIndex=0;currentIndex<endOfArrayIndex-1;currentIndex++)
			{
				if(array[currentIndex]>array[currentIndex+1])
				{
					swap(array[currentIndex],array[currentIndex+1]);
					swapped=true;
				}
			}
			if (!swapped)
		{
				cout<<"Early Termination on Iteration "<<iteration+1<<endl;
				break;
		}
			for(int index=0;index<length;index++)
						cout<<array[index]<<' ';

					cout<<"\n";
		}
	return 0;
}
