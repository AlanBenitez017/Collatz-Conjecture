/***************************************************************
  Students Name: Jace Domingo
                 Alan Benitez
  File Name: main.cpp
  Assignment number: Project 2

  This is the main class
***************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "mt-collatz.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    
    //Throws error if incorrect number of arguments
    if (argc < 3) {
        cout << "Must enter at least two arguments." << endl;
        exit(-1);
    }
   
    //Initializes parameters set by user
    int numMax = atoi(argv[1]);
    int threadMax = atoi(argv[2]);
    
    //Initializes argument string
    string arg;
    
    //Initializes a vector of threads
    vector <thread> threads;
    
    //Initializes clock variable
    clock_t t;
    
    //Lock boolean set to false if -nolock is set by user
    int lock = 1;
    
    for (int i = 0; i < argc; i++) {
        arg = argv[i];
        if (arg == "-nolock")
            lock = 0;
    }
    
    mt_collatz * colObj = nullptr;
    colObj = new mt_collatz(numMax, lock);

    //Starts timer
    t = clock();

    //Fills vector with threadMax threads each executing the startCollatz function
    for(int i = 0; i < threadMax; i++)
    {
      	threads.push_back(thread(&mt_collatz::startCollatz, colObj));
    }

    //Waits for each thread in the vector to finish
    for(thread &t : threads)
    {
      	if(t.joinable())
      	{
       		t.join();
       	}
    }
    //Stop timer
    t = clock() - t;
    //Prints histogram
    colObj->printHistogram();
    
    //Prints time to standard error stream
    double totalTime = ((float)t) / CLOCKS_PER_SEC;
    cerr << numMax << ", " << threadMax << ", " << totalTime << endl;
    
    threads.clear();
    delete colObj;

    return(0);
}
