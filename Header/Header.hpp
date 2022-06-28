#ifndef __HEADER_INCLUDED__
#define __HEADER_INCLUDED__


#include <iostream>
#include <ctime> // time calculating 
#include <fstream> // log in input and save output
#include <string>

using namespace std;

// read input file
// @param n the number of elements (the first line of the input file)
// @param a the array containing input data (the rest lines in the input file)
// @param index the index of the file
template<typename T>
void readFile(T*&, T&, int);

// random number generator
// @return a random number 
int getRandom();

// create a file containing __size random number
// @param size the size of the file
// @param index the index of the file
void createAFile(const int&, const int&);

// Quick Sort process
// @param index the index of the file
void QS(const int&);

// Bubble Sort process
// @param index the index of the file
void BS(const int&);

// Insertion Sort process
// @param index the index of the file
void IS(const int&);

// Interchange Sort process
// @param index the index of the file
void IcS(const int&);

// Heap Sort process
// @param index the index of the file
void HS(const int&);

// Merge Sort process
// @param index the index of the file
void MS(const int&);

// Radix Sort process
// @param index the index of the file
void RS(const int&);

// Selection Sort process
// @param index the index of the file
void SS(const int&);

// Shaker Sort process
// @param index the index of the file
void ShkS(const int&);

// Shell Sort process
// @param index the index of the file
void SheS(const int&);


#endif //__HEADER_INCLUDED__