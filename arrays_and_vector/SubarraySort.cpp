#include<bits/stdc++.h>
using namespace std ;


bool isOutOfOrder(vector<int> arr, int i)
{
    if (i == 0)  return arr[i] > arr[1] ;

    if (i == arr.size()-1) return arr[i] < arr[arr.size()-1] ;

    return arr[i] > arr[i+1] or arr[i] < arr[i-1] ;
}

vector<int> min_length_subarray_sort(vector<int> arr)
{
    int n = arr.size() ;
    int smallest = INT_MAX , largest = INT_MIN ;
    for (int i = 0 ; i < n ; i++)
    {
        if (isOutOfOrder(arr, i)) {
            if (smallest > arr[i]) smallest = arr[i] ;
            if (largest < arr[i]) largest = arr[i] ;
        }
    }

    if (smallest == INT_MIN) return vector<int>{-1, -1} ;

    int smallest_ind = 0 , largest_ind = n-1 ;

    while (smallest_ind < n)
    {
        if (arr[smallest_ind] <= smallest) smallest_ind++ ;
        else break ;
    }

    while (largest_ind >= 0)
    {
        if (arr[largest_ind] >= largest) largest_ind-- ;
        else break ;
    }

    return vector<int>{smallest_ind, largest_ind} ;



}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11} ;
    vector<int> subArrayToSort = min_length_subarray_sort(arr) ;
    for (auto x : subArrayToSort) cout << x << " " ;
}














