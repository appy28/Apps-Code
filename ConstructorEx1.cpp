//============================================================================
// Name        : ConstructorEx1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Ball
{
	string m_colour;
	double m_value;

public:
	Ball()
     {
		m_colour = "Black";
	    m_value = 10.0;
	 }

	Ball(const string &colour,double value)
     {
		m_colour = colour;
		m_value = value;
	 }

	Ball(const string &colour)
	{
		m_colour = colour;
		m_value = 10.0;
	}

	Ball(double value)
	{
		m_colour = "Black";
		m_value = value;
	}
/*
    // Constructor with both color and radius parameters
    // handles no parameter, color only, and color + radius cases.
    Ball(const string &colour="black", double value=10.0)
    {
	    m_colour = colour;
	    m_value = value;
    }
*/
	void print()
	{
		cout<<"Colour:"<<m_colour<<", Radius:"<<m_value<<endl;
	}
};
int main() {

	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	return 0;
}
