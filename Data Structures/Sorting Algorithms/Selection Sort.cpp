#include <bits\stdc++.h>
using namespace std;

// Time : O(n ^ 2) , Space : O(1)
template <class T>
void selectionSort(T arr[] , int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        int mnIdx = i;
        for (int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[mnIdx])
                mnIdx = j;
        }
        swap(arr[i],arr[mnIdx]);
    }
}