//============================================================================
// Name        : DynamicallyAllocatingArrayEx.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

void sortArray(string *array,int numofNames)
{
	for(int startIndex=0;startIndex<numofNames-1;startIndex++)
	{
		int smallestIndex=startIndex;

		for (int currentIndex=startIndex+1;currentIndex<numofNames;currentIndex++)
		{
			if(array[currentIndex]<array[smallestIndex])
				smallestIndex=currentIndex;
		}
		swap(array[startIndex],array[smallestIndex]);
	}
}

int main() {

	cout<<"How many Names would you like to enter ?"<<endl;
	int numOfNames;
	cin>>numOfNames;

	string *names = new string[numOfNames];

	for (int count=0;count<numOfNames;count++)
	{
		cout<<"Enter Name #"<<count+1<<":";
		cin>>names[count];
	}

	sortArray(names,numOfNames);

	cout<<"Here is your sorted List::"<<endl;

	for (int index=0;index<numOfNames;index++)
	{
		cout<<"Name #"<<index+1<<":"<<names[index]<<endl;;
	}

		delete []names;
		names=0;

	return 0;
}
