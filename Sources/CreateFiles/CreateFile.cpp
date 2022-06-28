#include "../../Header/Header.hpp"

#define RAND_RANGE 2031312329

int getRandom()
{ 
    return rand() % RAND_RANGE;
}

void createAFile(const int& size, const int& index){
    ofstream osFile("../../Input/inputF"+to_string(index)+".txt");  // open/create an output file
    if (!osFile.fail()){
        osFile << size << endl;
        // create a file with random numbers
        for (int i=0; i<size; i++){ 
            osFile << getRandom() << endl;
        }
    }
    else cout << "\nCannot open file";
    osFile.close();
}

int main()
{
    srand(time(NULL));
    // int size; cout<<"\nSize of file: "; cin >> size;    // input size of input file
    int size = 100;
    for (int i = 1; i <= 8; i++)
    {
        createAFile(size, i);
        size *= 10;
    }

    return 0;
}