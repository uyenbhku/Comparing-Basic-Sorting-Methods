#pragma once
#include "../../Header/Header.hpp"

// ascending sorting
void InsertionSort(int *&a, int n){
    if (n > 1){
        int x, j;
        for (int i = 1; i < n; i++){
            x = a[i]; 
            // doi cho cac phan tu dang sau
            for (j = i; j != 0; j--){
                if (x <= a[j-1]) break;
                a[j] = a[j-1];
            }
            a[j] = x;
        }
    }
}


void IS(int index)
{
    int n;      // number of elements
    int *a = NULL; // a storing data that need sorting
    readFile(a, n, index);
    if (!a) {
        cout << "\nRead file failed";
        exit(1);
    }

    ofstream timeLog("../../Output/Time_log.txt", ios::app);
    ofstream osFile("../../Output/ISResults"+to_string(index)+".txt");
    // save results
    if (!timeLog.fail() && !osFile.fail()){
        clock_t startT = clock(); // start time
        InsertionSort(a, n);     // conducting sorting method
        clock_t endT = clock(); // end time
        // save time log
        timeLog<<"\nWith the capacity of " << n << ", Insertion Sort method took: " << ((double)endT - startT)/CLOCKS_PER_SEC << " seconds";
        // print results 
        for (int i = 0; i < n; i++) osFile << a[i] << "\n";
    }
    else cout << "\nCannot open file";
    timeLog.close();
    osFile.close();
}