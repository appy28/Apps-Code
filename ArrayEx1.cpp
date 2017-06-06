//============================================================================
// Name        : ArrayEx1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
namespace Animals
{
enum Animals
{
   ANIMAL_CHICKEN,
   ANIMAL_DOG,
   ANIMAL_CAT,
   ANIMAL_ELEPHANT,
   ANIMAL_DUCK,
   ANIMAL_SNACK,
   MAX_ANIMALS
};
}

int main() {

	int LEGS[Animals::MAX_ANIMALS]={2,4,4,4,2,0};
	cout<<"An Elephant has "<< LEGS[Animals::ANIMAL_ELEPHANT]<<" legs"<<endl;
	return 0;
}
