#pragma once
#include "../../Header/Header.hpp"

template<typename T>
void readFile(T *&a, T &n, int index){
    // open input file 
    ifstream isFile("../../Input/inputF"+to_string(index)+".txt");
    if (isFile.fail()) {
        cout << "\nCannot open input file";
        exit(1);
    }

    // get input data 
    isFile >> n; // read size
    a = new int [n];
    int i = 0;
    while (isFile >> a[i]) i++; // read numbers
    isFile.close();
}
