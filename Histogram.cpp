/***************************************************************
  Students Name: Jace Domingo
                 Alan Benitez
  File Name: Histogram.cpp
  Assignment number: Project 2

  This class adds to the histogram and prints the histogram
***************************************************************/

#include "Histogram.hpp"

//Initializes historgram array
Histogram::Histogram(){
    for(int i = 0; i < MAXSTOPPINGTIME; i++){
        histogram[i] = 0;
    }
}

//Increments stoppings times in histogram array
void Histogram::addToHistogram(int index){
    histogram[index]++;
}

//Prints histogram
void Histogram::printHistogram(){
    for(int i = 0; i < MAXSTOPPINGTIME; i++){
        cout << i << ", "<< histogram[i] << endl;
    }
}
