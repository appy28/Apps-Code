//============================================================================
// Name        : ConstructorUsingMemberInitializerList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdint>
using namespace std;

class RGBA
{
	uint8_t m_red, m_green, m_blue,m_alpha;

public:
	RGBA(uint8_t red=0,uint8_t green=0,uint8_t blue=0,uint8_t alpha=255)
        : m_red(red),m_green(green),m_blue(blue),m_alpha(alpha)
{

}
	void print()
	{
		cout<<"R="<<static_cast<int>(m_red)<<" G="<<static_cast<int>(m_green)<<" B="
				  <<static_cast<int>(m_blue)<<" A="<<static_cast<int>(m_alpha)<<endl;
	}
};
int main() {

	RGBA teal(0, 127, 127);
	teal.print();
	return 0;
}
