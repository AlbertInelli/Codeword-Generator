#ifndef MELT_H
#define MELT_H
#include <iostream>
#include <string>

using std::string;

class Melt
{
	private:
	char symbol;
	
	public:
	Melt(char _symbol) : symbol(_symbol){};
	const char getNumber();//called get number so it works in templated ontainer class too.
	int operator-(Melt &obj);
};

#endif
