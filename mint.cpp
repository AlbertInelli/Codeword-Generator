#include <iostream>
#include <string>
#include "mint.h"

using std::string;

const int Mint::getNumber()
{
	return number;
}

//overloaded - operator for the distances
//outside of this we must add on modulo if the answer goes below 0.
int Mint::operator-(Mint &obj)
{
	int result = number - obj.getNumber();

	if(result < 0)
	{
		result = result + modulus;
	}
	
	return result;
}
	