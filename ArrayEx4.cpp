//============================================================================
// Name        : ArrayEx4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

enum ItemType
{
	ITEM_HEALTH_POTION,
	ITEM_TORCHEs,
	ITEM_ARROW,
	MAX_ITEM
};

int countTotalItem(int *items)
{
	int totalItems= 0;
	for(int item=0;item<MAX_ITEM;item++)
		totalItems+=items[item];

	return totalItems;
}

int main() {

	int items[MAX_ITEM] = {2,5,10};

	cout << "The Player has " <<countTotalItem(items)<< " total in Items" << endl;
	return 0;
}
