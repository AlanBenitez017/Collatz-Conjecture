/***************************************************************
  Students Name: Jace Domingo
                 Alan Benitez
  File Name: main.cpp
  Assignment number: Project 2

  This is the header file of the Histogram.cpp
***************************************************************/
#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP
#include <iostream>

    using namespace std;

class Histogram{

    public:
        static const int MAXSTOPPINGTIME = 1000;
        int histogram[MAXSTOPPINGTIME];
        void printHistogram();
        Histogram();
        void addToHistogram(int index);
};

#endif
