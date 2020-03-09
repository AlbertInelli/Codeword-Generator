#ifndef MINT_H
#define MINT_H
#include <iostream>
#include <string>

using std::string;

class Mint
{
	private:
	int number;
	int modulus;
	
	public:
	Mint(int _number, int _modulus) : number(_number), modulus(_modulus){};
	const int getNumber();
	int operator-(Mint &obj);
};

#endif



