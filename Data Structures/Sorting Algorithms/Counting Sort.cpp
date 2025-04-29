#include <bits\stdc++.h>
using namespace std;


// Time : O(n) , Space : O(n)
template <class T>
void countingSort(T arr[] , int n)
{
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if(arr[i] > mx)
            mx = arr[i];
    }
    T *c , *sarr;
    c = new T[mx+1] , sarr = new T[n+1];
    for (int i = 0; i <= mx; ++i)
        c[i] = 0;
    for (int i = 0; i < n; ++i)
        c[arr[i]]++;
    for (int i = 1; i <= mx; ++i)
        c[i] += c[i-1];
    for (int i = n-1; i >= 0; --i)
        sarr[c[arr[i]]] = arr[i] , c[arr[i]]--;
    for (int i = 0; i < n; ++i)
        arr[i] = sarr[i+1];
    delete [] c; delete [] sarr;
}