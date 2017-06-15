//============================================================================
// Name        : ClassConstructorEx1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

class Point2d
{
	double m_x;
	double m_y;

	public:
	Point2d(double pt1 = 0.0, double pt2 = 0.0)
	:m_x(pt1),m_y(pt2)
	{}

	void print()
	{
		cout<<"Point2D("<<m_x<<", "<<m_y<<")"<<endl;
	}

	double distanceTo(Point2d other)
	{
		return sqrt((m_x-other.m_x)*(m_x-other.m_x)+(m_y-other.m_y)*(m_y-other.m_y));
	}
};

int main() {

	Point2d first;
		Point2d second(3.0, 4.0);
		first.print();
		second.print();
		std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

	    return 0;
}
