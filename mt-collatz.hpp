#ifndef MT_COLLATZ_HPP
#define MT_COLLATZ_HPP
/***************************************************************
  Students Name: Jace Domingo
                 Alan Benitez
  File Name: main.cpp
  Assignment number: Project 2

  This is the header file of the mt-collatz.cpp
***************************************************************/
#include <mutex>
#include <iostream>
#include <thread>
#include "Histogram.hpp"

    using namespace std;
class mt_collatz{
    public:
        mt_collatz(int numMax, int lock);
        int lock;
        int COUNTER = 2;
        int numMax;
        mutex mtx;
        Histogram hist;
        void collatz(long long index);
        void startCollatz();
        void printHistogram();
};
#endif
