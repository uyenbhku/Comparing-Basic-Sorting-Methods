#pragma once
#include "../../Header/Header.hpp"

// ascending sorting
void BubbleSort(int *&a, int n){
    
}



void BS(const int& index)
{
    int n;      // number of elements
    int *a = NULL; // a storing data that need sorting
    readFile(a, n, index);
    // check if the reading file section is successful
    if (!a) {
        cout << "\nRead file failed";
        exit(1);
    }

    ofstream timeLog("../../Output/Time_log.txt", ios::app);
    ofstream osFile("../../Output/BSResults"+to_string(index)+".txt");
    // save results
    if (!timeLog.fail() && !osFile.fail()){
        clock_t startT = clock(); // start time
        BubbleSort(a, n);     // conducting sorting method
        clock_t endT = clock(); // end time
        // save time log
        timeLog<<"\nWith the capacity of " << n << ", Bubble Sort method took: " << ((double)endT - startT)/CLOCKS_PER_SEC << " seconds";
        // print results 
        for (int i = 0; i < n; i++) osFile << a[i] << "\n";
    }
    else cout << "\nCannot open file";
    timeLog.close();
    osFile.close();
}