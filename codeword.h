#ifndef CODEWORD_H
#define CODEWORD_H
#include <iostream>
#include <string>
#include <vector>
#include "mint.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;

//may have to use size from the input arguments as the size here
template<class T>
class Codeword
{
	private:
	vector<T> symbols;
	
	public:
	Codeword();
	Codeword(vector<T> _symbols) : symbols(_symbols) {};
	int weight();
	const vector<T> getSymbols();
	int distance(Codeword<T> codeWordTwo);
	void display();
};

template<class T>
const vector<T> Codeword<T>::getSymbols()
{
	return symbols;
}

//this templates function checks if inside of thecontainer there is a 0 or a which represents 0.
//if its not it increases the weight by 1
template<class T>
int Codeword<T>::weight()
{
	int weight = 0;
	for(int i = 0; i < symbols.size(); i++)
	  {
		if(symbols[i].getNumber() != 0 && symbols[i].getNumber() != 'a')
		{
			weight++;
		}
	}
	return weight;
}

//this function displays each element in the container and also calls the weight function above and gets the weight to display.
template<class T>
void Codeword<T>::display()
{
	int genWeight = weight();
	for(int i = 0; i < symbols.size(); i++)
	{
		cout << symbols[i].getNumber() << " ";
	}
	cout << "	";
	cout << "Weight: " << genWeight << endl;
}

//This function compares the difference between two codewords by using overloaded - operator.
//prints out each codeword and answer seperately so that enabled me to get the desired output looking like it should.
template<class T>
int Codeword<T>::distance(Codeword<T> otherCodeword)
{
	vector<T> otherSymbols = otherCodeword.getSymbols();
	int difference = 0;
	int totalDifference = 0;
	
	cout << endl;
	for(int i = 0; i < symbols.size(); i++)//print out all the first codeword symbols
	{
			cout << symbols[i].getNumber() << " ";  
			
	}
	cout << " - " << endl;
	
	for(int i = 0; i < otherSymbols.size(); i++)//print out secondcodeword symbol
	{
			cout << otherSymbols[i].getNumber()<< " ";  
			
	}
	cout << endl;
	cout << "--------- " << endl;
	
	for(int i = 0; i < symbols.size(); i ++)
	{
			difference = symbols[i] - otherSymbols[i]; //use overloaded - operator to get difference
			cout << difference << "+";
			totalDifference += difference; // get total difference for that codeword - that codeword 
			
	}
	cout << "	= " << totalDifference << endl;
	return totalDifference;	
}
#endif


   
