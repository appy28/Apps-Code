//============================================================================
// Name        : ClassEx1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Dateclass
{
	// access specifier private by default
	int m_date;
	int m_month;
	int m_year;

public:

	void setDate(int date,int month,int year)
	{
		m_date = date;
		m_month = month;
		m_year = year;
	}

	void printDate()
	{
		cout << "Date is:"<< m_date <<"/"<< m_month<<"/"<<m_year<<endl;
	}

	void copyClass(Dateclass &d)
	{
		m_date = d.m_date;
		m_month=d.m_month;
		m_year = d.m_year;
	}
};

int main() {

	Dateclass date;

    date.setDate(5,5,2017);
    date.printDate();

    Dateclass newDate;
    newDate.copyClass(date);
    newDate.printDate();

	return 0;
}
