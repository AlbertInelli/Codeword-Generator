#include <iostream>
#include <vector>
#include "codeword.h"
#include "codebook.h"
#include "mint.h"
#include "melt.h"
#include <algorithm>
#include "generateValue.h"

using namespace std;

int main(int argc, char* argv[])
{
	//conversion of command line arguments to int.
	int mintMelt =  atoi(argv[1]); // mint or melt
	int seed;  //seed for random number generator
	int length; // length of each CODEWORD
	int size; //length of each CODEBOOK
	int modulus;//numbers in codeword must be smaller than this.
	
	//check how many
	if(mintMelt == 0)
	{
		if(argc != 6)
		{
			cout << "Invalid argument number" << endl;
			abort();
		}
		
		seed = atoi(argv[2]);
		length = atoi(argv[3]); // length of each CODEWORD
		size = atoi(argv[4]); //length of each CODEBOOK
		modulus = atoi(argv[5]);
		
	}
	else if(mintMelt == 1)
	{
		if(argc != 5)
		{
			cout << "Invalid argument number" << endl;
			abort();
		}
		
		seed = atoi(argv[2]);
		length = atoi(argv[3]); // length of each CODEWORD
		size = atoi(argv[4]); //length of each CODEBOOK
	}
	
	//all checking for command line arguments.
	if(mintMelt < 0 || mintMelt > 1 )
	{
		cerr << "Mint or melt is out of bounds" << endl;
		abort();
	}
	if(seed <= 0)
	{
		cerr << "Seed cannot be less than 0" << endl;
		abort();
	}
	if(length <= 0)
	{
		cerr << "Length cannot be 0 or less" << endl;
		abort();
	}
	if(size <= 0)
	{
		cerr << "Cannot have a size of 0 or less" << endl;
		abort();
	}
	if(modulus <= 0)
	{
		cerr << "Cannot have a modulus of 0 or less" << endl;
		abort();
	}
	
	//put a codebook container outside of everything to add each codeword.

	//sequence of steps, mint objects are created depending on length and added to collection
	//collection is now a codeword and gets passed into constructor of a new codeword object.
	//will create more codewords until size is reached and each is added into a collection of codewords
	//these collection of codewords now become the codebook at the end.
	
	int bookCounter = 0;
	int zeroCounter = 0;
	vector<Codeword<Mint>> codeWordList;//create new codeword vector to store multiple codewords to be used to make codebook.
	vector<Codeword<Melt>> codeWordMeltList;//create new codeword vector to store multiple codewords to be used to make codebook.
	
	while(bookCounter < size)//outside while loop that continues until codebook size has been reached
	{
		//mintList.clear();//clears the mint list so
		if(mintMelt == 0)
		{
			 //create new CODEWORD template container object and pass in mint collection
			int wordCounter = 0; // counter to stop so it codeword equals command line argument length
			vector<Mint> mintList;//container to be passed into codeword constructor
			
			if(zeroCounter == 0)
			{
				
				//this section puts the zeros at the front of the codeword list for the same amount of length.
				while(zeroCounter < length)
				{
					Mint zeroMint(0, modulus); 
					mintList.push_back(zeroMint);
					zeroCounter++;
				}
				
				Codeword<Mint> codeWord(mintList);//create a new codeword just for the 0's
				codeWordList.push_back(codeWord);//push it into codewordlist
				mintList.clear(); // clear the mint list so 0 is not included everytime.
				
			}
			else 
			{
				while(wordCounter < length)// generates new integers until amount of desiered codewords have been reacheed.
				{
					Mint newMint(generateMint(seed, modulus), modulus); //called function from imported library and assigns a new mint object to return value.
					mintList.push_back(newMint); //add generated number to container
					wordCounter++;	
				}
				
				Codeword<Mint>codeWord(mintList); //create new CODEWORD template container object and pass in mint collection
				codeWordList.push_back(codeWord);//push the codeword into the codeword list, eventually all of these will be in CODEBOOK
			}
		}
		
		else if(mintMelt = 1)//for melts
		{
			int wordCounter = 0;
			vector<Melt>meltList; // list of melts to eventually become a codeword
			
			if(zeroCounter == 0)
			{
				while(zeroCounter < length)
				{
					Melt zeroMelt('a'); //zero symbol a
					meltList.push_back(zeroMelt);
					zeroCounter++;
				}
				
				Codeword<Melt> codeWord(meltList);//create a new codeword just for the a's
				codeWordMeltList.push_back(codeWord);//push it into codewordlist
				meltList.clear(); // clear the mint list so 0 is not included everytime.
				
			}
			else
			{
				while(wordCounter < length)//codeword length
				{
					Melt newMelt = generateMelt(seed);//create a new melt
					meltList.push_back(newMelt);
					wordCounter++;
				}
				
				Codeword<Melt>codeWord(meltList);
				codeWordMeltList.push_back(codeWord);
			}
		}
		
		bookCounter++;
	}
	
	if(mintMelt == 0)
	{
		Codebook<Mint> codeBook(codeWordList);// this is our code book, which has a collection of codewords inside and inside each of those collections are a collection of mints
		codeBook.display();
	}
	else if(mintMelt == 1)
	{
		Codebook<Melt>codeBook(codeWordMeltList);
		codeBook.display();
	}
}
