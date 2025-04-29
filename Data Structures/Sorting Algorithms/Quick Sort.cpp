#include <bits\stdc++.h>
using namespace std;


template <class T>
int partioning(T arr[] , int l , int r)
{
    srand(static_cast<unsigned int>(time(0)));
    int rdmPiv = l + rand() % (r-l);
    int pivot = arr[rdmPiv] , i = l;
    swap(arr[l],arr[rdmPiv]);
    for (int j = i+1; j < r; ++j)
    {
        if(arr[j] < pivot)
            swap(arr[++i],arr[j]);
    }
    swap(arr[i],arr[l]);
    return i;
}

// Time : O(nlog(n)) , Space : O(1)
template <class T>
void quickSort(T arr[] , int l , int r)
{
    if(l < r)
    {
        int pivot = partioning(arr,l,r);
        quickSort(arr,l,pivot);
        quickSort(arr,pivot+1,r);
    }
}