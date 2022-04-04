CXXFLAGS = -g -std=c++14 -pthread -Wall -Werror=return-type -Werror=uninitialized 
CXX = g++
objects = main.o mt-collatz.o Histogram.o

all: mt-collatz

mt-collatz: $(objects)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp mt-collatz.cpp

mt-collatz.o: Histogram.o 

.PHONY : clean

clean: 
	$(RM) mt-collatz $(objects)
