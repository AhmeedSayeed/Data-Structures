#include <bits\stdc++.h>
using namespace std;


// Time : O(n ^ 2) , Space : O(1)
template <class T>
void insertionSort(T arr[] , int n)
{
    int curr , j;
    for (int i = 1; i < n; ++i)
    {
        curr = arr[i] , j = i-1;
        while(j >= 0 && curr < arr[j])
            arr[j+1] = arr[j] , j--;
        arr[j+1] = curr;
    }
}