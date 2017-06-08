//============================================================================
// Name        : BasicCalculatorUsingFunctionPointerEx2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int getInteger()
{
	cout<<"Enter an Integer :"<<endl;
	int num;
	cin>>num;
	return num;
}

char getOperation()
{
	char op;
	do
	{
		cout<<"Enter mathematical Operator(+,-,*,/):"<<endl;
		cin>>op;
	}
	while(op != '+'&& op != '-' && op != '*' && op != '/');

	return op;
}

int add (int x, int y)
{
	return x+y;
}

int subtract(int x, int y)
{
	return x-y;
}

int multiply(int x, int y)
{
	return x*y;
}

int divide (int x, int y)
{
	return x/y;
}

typedef int (*arithmeticFcn)(int, int);

struct arithmeticStruct
{
	char op;
	arithmeticFcn fcn;
};

static arithmeticStruct arithmaticArray[]=
{
	{'+',add},
	{'-',subtract},
	{'*',multiply},
	{'/',divide}
};

arithmeticFcn getArithmaticFuncion(char op)
{
   for(auto &arith:arithmaticArray)
   {
	   if(arith.op == op)
		   return arith.fcn;
   }
   return add;
}

int main() {

	int num1 = getInteger();
	char op = getOperation();
	int num2 = getInteger();

	arithmeticFcn fcn = getArithmaticFuncion(op);

	cout << num1 << ' ' << op << ' ' << num2 << " = " << fcn(num1,num2)<< endl;

	return 0;
}
