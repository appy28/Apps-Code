//============================================================================
// Name        : ClassEx2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Point3D
{
	double m_x;
	double m_y;
	double m_z;

public:
	void setValues(double x, double y, double z)
	{
		m_x=x;
		m_y=y;
		m_z=z;
	}

	void printValues()
	{
		cout<<"< "<<m_x<<", "<<m_y<<", "<<m_z<<" >"<<endl;
	}

	bool isequal (const Point3D &point)
	{
		return (m_x==point.m_x && m_y==point.m_y && m_z==point.m_z);
	}
};
int main() {

	Point3D point1;
	    point1.setValues(1.0, 2.0, 3.0);

	    Point3D point2;
	    point2.setValues(1.0, 2.0, 3.0);

	    if (point1.isequal(point2))
	        std::cout << "point1 and point2 are equal\n";
	    else
	        std::cout << "point1 and point2 are not equal\n";

	    Point3D point3;
	    point3.setValues(3.0, 4.0, 5.0);

	    if (point1.isequal(point3))
	        std::cout << "point1 and point3 are equal\n";
	    else
	        std::cout << "point1 and point3 are not equal\n";

	    return 0;}
