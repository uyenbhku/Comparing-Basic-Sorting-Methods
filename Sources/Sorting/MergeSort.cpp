#pragma once
#include "../../Header/Header.hpp"


// ascending sorting
void MergeSort(int *&a, int left, int right){
    if (left >= right) return; 

    int mid = (left + right)/2;
    // partition
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);

    Merge(a, left, mid, right);
}

void Merge(int *&a, int left, int mid, int right)
{
    int *res = new int [right - left + 1];

    // pour elements into res with order 
    int i = left, j = mid + 1, k = 0;
    while (!(i > mid && j > right)){
        if ((i <= mid && j <= right && a[i] < a[j]) || (j > right))
            res[k++] = a[i++];
        else 
            res[k++] = a[j++];
    }

    // pour elements back to a
    for (int i = left; i <= right; i++){
        a[left + i] = res[i];
    }
    delete[] res;
    res = NULL;
}

void MS(const int& index)
{
    int n;      // number of elements
    int *a = NULL; // a storing data that need sorting
    readFile(a, n, index);
    if (!a) {
        cout << "\nRead file failed";
        exit(1);
    }

    ofstream timeLog("../../Output/Time_log.txt", ios::app);
    ofstream osFile("../../Output/MSResults"+to_string(index)+".txt");
    
    // save results
    if (!timeLog.fail() && !osFile.fail()){
        clock_t startT = clock(); // start time
        MergeSort(a, 0, n-1);     // conducting sorting method
        clock_t endT = clock(); // end time
        
        // save time log
        timeLog<<"\nWith the capacity of " << n << ", Merge Sort method took: " 
                << ((double)endT - startT)/CLOCKS_PER_SEC << " seconds";
        
        // print results 
        for (int i = 0; i < n; i++) osFile << a[i] << "\n";
    }
    else cout << "\nCannot open file";
    timeLog.close();
    osFile.close();
}