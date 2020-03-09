#include <iostream>
#include <string>
#include "melt.h"

using std::string;

const char Melt::getNumber()
{
	return symbol;
}

int Melt::operator-(Melt &obj)//overloaded - operator. When two melt objectsare subtracted form each other (melt1 - melt2),
{
	if(symbol == obj.getNumber())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
