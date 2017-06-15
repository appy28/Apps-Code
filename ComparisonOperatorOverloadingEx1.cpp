//============================================================================
// Name        : ComparisonOperatorOverloadingEx1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
	string m_make;
	string m_model;

public:
	Car(string make,string model)
       :m_make(make),m_model(model)
{}

	friend bool operator ==(const Car &c1, const Car &c2);
	friend bool operator !=(const Car &c1, const Car &c2);
};

bool operator ==(const Car &c1, const Car &c2)
{
	return (c1.m_make == c2.m_make &&
			c1.m_model == c2.m_model);
}

bool operator !=(const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}
int main() {

	Car corolla ("Toyota","Corolla");
	Car camry ("Toyota", "Camry");

	if(corolla == camry)
		cout<<"corolla and camry are the same"<<endl;
	if (corolla != camry)
		cout<<"corolla and camry are not same"<<endl;
	return 0;
}
