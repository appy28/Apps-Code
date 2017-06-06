//============================================================================
// Name        : BinarySearchwithIterativeVersion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise

int binarySearch(int *array, int target, int min, int max)
{
    while (min <= max)
    {
    	int midpoint = min + ((max-min)/2);

    	if (array[midpoint] > target)
    	{
    		max = midpoint - 1;
    	}
    	else if (array[midpoint] < target)
    	{
    		min = midpoint + 1;
    	}
    	else
    		return midpoint;
    }
    return -1;
}
int main() {

	int array[] = {3,6,8,12,14,17,20,21,26,32,36,37,42,44,48};

	 // We're going to test a bunch of values to see if they produce the expected results
	    const int numTestValues = 9;
	    // Here are the test values
	    int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	    // And here are the expected results for each value
	    int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	    for (int count;count < numTestValues ; count++)
	    {
	    	int index = binarySearch(array,testValues[count],0,14);

	    	if (index == expectedValues[count])
	    		cout << "test Value "<<testValues[count]<<" passed.."<<endl;
	    	else
	    		cout<<"test values "<<testValues[count]<<" failed. There is something wrong with your code"<<endl;
	    }

	return 0;
}
