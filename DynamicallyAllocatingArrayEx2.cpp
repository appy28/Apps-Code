//============================================================================
// Name        : DynamicallyAllocatingArrayEx2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name;
	int grade;
};

void sortArray(Student *array, int length)
{
	for (int startIndex=0;startIndex<length-1;startIndex++)
	{
		int largeststIndex=startIndex;

		for (int currentIndex =startIndex+1;currentIndex<length;currentIndex++)
		{
			if(array[currentIndex].grade > array[largeststIndex].grade)
				largeststIndex = currentIndex;
		}
		swap(array[startIndex],array[largeststIndex]);
	}
}

int main() {

	cout << "How many students you want enter ?" ;
	int length;
	cin>>length;

	Student *arrOfStudent = new Student[length];

	for (int count=0;count<length;count++)
	{
		cin>>arrOfStudent[count].name;
		cin>>arrOfStudent[count].grade;
	}

	sortArray(arrOfStudent,length);

	for (int index =0;index<length;index++)
		cout<<arrOfStudent[index].name<<" has got a grade of "<<arrOfStudent[index].grade<<endl;

	delete [] arrOfStudent;
	return 0;
}
