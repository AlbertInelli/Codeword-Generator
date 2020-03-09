#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "codeword.h"
#include "mint.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

template <class T>
class Codebook
{
	private:
	vector<Codeword<T>> collectionName;
	
	public:
	//Codebook();
	Codebook(vector<Codeword<T>> _collectionName) : collectionName(_collectionName){};
	int minimumWeight();
	vector<int> calcDistance();
	int minimumDistance();
	void display();
	const vector<Codeword<T>> getCodeBook();
};

template<class T>
const vector<Codeword<T>> Codebook<T>::getCodeBook()
{
	return collectionName;
}


//this function we get the weight from each codeword and compare it to the lowest weight found so far. if it islower then thelowest weight is set to thatweight
template<class T>
int Codebook<T>::minimumWeight()
{
	int tempWeight = 0;
	int lowestWeight = 60000;
	for(int i = 1; i < collectionName.size(); i++)//i starts at 1 to skip the zero codeword
	{
		tempWeight = collectionName[i].weight();//callsweight function from codeword

		if(tempWeight < lowestWeight)//if what we got it lower than current lowest, assign lowest variable to new lowest.
		{
			lowestWeight = tempWeight;
		}
		
	}
	return lowestWeight;
}

//displays all codewords in the codebook.
template<class T>
void Codebook<T>::display()
{
	int minWeight = 0; 
	int minDistance = 0;
	
	for(int i = 0; i < collectionName.size(); i++)
	{
		collectionName[i].display();
	}
	cout << endl;
	
	
	minWeight = minimumWeight();
	cout << "Minimum Weight: " << minWeight << endl;
	minDistance = minimumDistance();
	cout << "Minimum Distance excluding 0's: " << minDistance << endl;
	

}
//this function compares each codeword to everyother codeword and getst he distance between all of them.
template<class T>
vector<int> Codebook<T>::calcDistance()
{
	vector<int> allDistances;
	int distance = 0; //distance variable to capture the distance between two codewords
	int counterOne = 1;//counter for the codeword that calls the function
	int counterTwo = 1;//counter for codeword being passed in
	
	while(counterOne < collectionName.size())//counter 1 will increment once it has passed in call other codewords into the function.
	{
		counterTwo = 1;//restarts the passed in variable to 1 (not 0 to skip the 0 codeword.)
		while(counterTwo < collectionName.size())//countertwo increments to keep the calling codeword the same but increment the passed in codeword.
		{
			distance = collectionName[counterOne].distance(collectionName[counterTwo]);//calls distance function and getst he distance between 2 codewords

			if(distance > 0)
			{
				allDistances.push_back(distance);//pushes it into vector so we can get minimum later in min distance, only ones above 0
			}
			counterTwo++;
		}
		
		counterOne++;
	}
	
	return allDistances;
}

//this function loops through the vector of distances recieved from calcDistance and gets the smallest one to return.
template<class T>
int Codebook<T>::minimumDistance()
{
	vector<int> allDistances = calcDistance();
	int tempDistance = 0;
	int minDistance = 60000;


	for(int i = 0; i< allDistances.size(); i++)
	{
		tempDistance = allDistances[i];
		
		if(tempDistance < minDistance && tempDistance > 0)//makesure it doesnt count any 0's as min distance and if the distance is smaller than the already smallest, it sets smallest to that one.
		{
			minDistance = tempDistance;
		}
		
	}
	return minDistance;
}

