#include <bits\stdc++.h>
using namespace std;


// Time : (n ^ 3/2) , Space : O(1)
template <class T>
void shellSort(T arr[] , int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            for (;j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}