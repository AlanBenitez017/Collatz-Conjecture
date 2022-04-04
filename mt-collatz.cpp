/***************************************************************
  Students Name: Jace Domingo
                 Alan Benitez
  File Name: mt-collatz.cpp
  Assignment number: Project 2

  This class does the calculations
***************************************************************/

#include "mt-collatz.hpp"

//Sets values in class
mt_collatz::mt_collatz(int numMax, int lock){

	this->numMax = numMax;
	this->lock = lock;
}

//Does the collatz calculations
void mt_collatz::collatz(long long index)
{
	int countTime = 0;
	while ( index!= 1){
		if(index %2 == 0)
		{
			index /= 2;
		}
		 else
		{
			index = (3*index)+1;
		}
			countTime++;
	}
	hist.addToHistogram(countTime);
}

//Prints the histogram
void mt_collatz::printHistogram(){
	hist.printHistogram();
}

//Applies mutex locks based on user specification
void mt_collatz::startCollatz(){
	int index;
	while (COUNTER < numMax) {
		if (lock) {
			mtx.lock();
			index = COUNTER;
			COUNTER++;
			mtx.unlock();
		}
		else {
			index = COUNTER;
			COUNTER++;
		}
		collatz(index);
	}
}
