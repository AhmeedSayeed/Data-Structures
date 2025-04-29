#include <bits\stdc++.h>
using namespace std;


template <class T>
void merge(T arr[] , int l , int m , int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    T *L , *R;
    L = new T[n1] , R = new T[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = arr[i+l];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[i+m+1];
    int i = 0 , j = 0 , k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
    delete [] L; delete [] R;
}

// Time : O(nlog(n)) , Space : O(n)
template <class T>
void mergeSort(T arr[] , int l , int r)
{
    if(l < r)
    {
        int m = l + (r-l) / 2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}