#include <bits\stdc++.h>
using namespace std;

// Time : O(n ^ 2) , Space : O(1)
template <class T>
void bubbleSort(T arr[] , int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        bool sorted = 1;
        for (int j = 0; j < n-i-1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                sorted = 0;
            }
        }
        if(sorted)
            return;
    }
}