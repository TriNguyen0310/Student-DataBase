#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//take from https://www.geeksforgeeks.org/binary-search/
//convert to template version with recursive call

//Making by Tri and Noah

/*
  Describe how it work
  l,r which mean start value from array and end value from array
  it will run this code below to fight that in array
  if find will printout correct result otherwise it will return -1
  x which mean value want to search
*/
template<typename T>
int binarySearch(T arr[], int l, int r, T x)
{
    if (l <= r) {
        int mid = (l + r)/2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        else if (arr[mid] < x)
            return binarySearch(arr, mid + 1,r, x);
  
        else
            return binarySearch(arr,l,r-1,x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}