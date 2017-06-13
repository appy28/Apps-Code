//============================================================================
// Name        : calHeightOfFallingBallusingloop.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "constant.h"
using namespace std;

double getHeightOfTower()
{
	double height;
	cout<<"Enter Initial Height of the Tower::";
	cin>>height;
	return height;
}

double calulateHeight(double initial_height,int seconds)
{
	double distance_fallen = (myConstant1::gravity_cont * seconds * seconds)/2;
	double current_height = initial_height - distance_fallen;
	return current_height;
}

void printHeight(double current_height, int seconds )
{
	if (current_height > 0.0)
		cout<<"At "<<seconds<<" the Ball is at Height:"<<current_height<<endl;
	else
		cout<<"At "<<seconds<<" Ball is at Ground"<<endl;
}

int main() {

	const double initial_height = getHeightOfTower();
	int seconds = 0;
	double height;

	do
	{
		height=calulateHeight(initial_height,seconds);
		printHeight(height, seconds );
		++seconds;
	} while(height>0.0);

	return 0;
}

