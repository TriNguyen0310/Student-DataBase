#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "Student.h"

using namespace std;

//taken from https://www.geeksforgeeks.org/timsort/
//converted to use templates by Noah

// This function sorts array from left index to
// to right index which is of size atmost RUN
const int RUN = 16;

template<typename T> 
void insertionSort(T arr[], int left, int right){
	for (int i = left + 1; i <= right; i++)
	{
		T temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

// Merge function merges the sorted runs

template<typename T>
void merge(T arr[], int l, int m, int r){
	
  cout << "\n Merging";

	// Original array is broken in two parts
	// left and right array
	int len1 = m - l + 1, len2 = r - m;
	T left[len1], right[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// After comparing, we
	// merge those two array
	// in larger sub array
	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of left, if any
	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}

	// Copy remaining element of right, if any
	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}

// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)

template<typename T>
void timSort(T arr[], int n){
	

  
	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i+=RUN)
		insertionSort(arr, i, min((i+RUN-1),
									(n-1)));

	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n;
							size = 2*size)
	{
		
		// pick starting point of
		// left sub array. We
		// are going to merge
		// arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we
		// increase left by 2*size
		for (int left = 0; left < n;
							left += 2*size)
		{
			
			// find ending point of
			// left sub array
			// mid+1 is starting point
			// of right sub array
			int mid = left + size - 1;
			int right = min((left + 2*size - 1),
											(n-1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			if(mid < right)
				merge(arr, left, mid, right);
		}
	}
}

// Utility function to print the Array

template<typename T>
void printArray(T arr[], int n){
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	printf("\n");
}
 
//----- New functions to sort Students by certain attributes -----

void insertionSortByEnglishGrade(Student arr[], int left, int right){
	for (int i = left + 1; i <= right; i++)
	{
		Student temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j].getEnglish_grade() > temp.getEnglish_grade())
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void mergeByEnglishGrade(Student arr[], int l, int m, int r){
	
  cout << "\n Merging";

	// Original array is broken in two parts
	// left and right array
	int len1 = m - l + 1, len2 = r - m;
	Student left[len1], right[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// After comparing, we
	// merge those two array
	// in larger sub array
	while (i < len1 && j < len2)
	{
		if (left[i].getEnglish_grade() <= right[j].getEnglish_grade())
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of left, if any
	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}

	// Copy remaining element of right, if any
	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}

void timSortByEnglishGrade(Student arr[], int n){
	

  
	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i+=RUN)
		insertionSortByEnglishGrade(arr, i, min((i+RUN-1),
									(n-1)));

	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n;
							size = 2*size)
	{
		
		// pick starting point of
		// left sub array. We
		// are going to merge
		// arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we
		// increase left by 2*size
		for (int left = 0; left < n;
							left += 2*size)
		{
			
			// find ending point of
			// left sub array
			// mid+1 is starting point
			// of right sub array
			int mid = left + size - 1;
			int right = min((left + 2*size - 1),
											(n-1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			if(mid < right)
				mergeByEnglishGrade(arr, left, mid, right);
		}
	}
}

void insertionSortByMathGrade(Student arr[], int left, int right){
	for (int i = left + 1; i <= right; i++)
	{
		Student temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j].getMath_grade() > temp.getMath_grade())
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void mergeByMathGrade(Student arr[], int l, int m, int r){
	
  cout << "\n Merging";

	// Original array is broken in two parts
	// left and right array
	int len1 = m - l + 1, len2 = r - m;
	Student left[len1], right[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// After comparing, we
	// merge those two array
	// in larger sub array
	while (i < len1 && j < len2)
	{
		if (left[i].getMath_grade() <= right[j].getMath_grade())
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of left, if any
	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}

	// Copy remaining element of right, if any
	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}

void timSortByMathGrade(Student arr[], int n){
	

  
	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i+=RUN)
		insertionSortByMathGrade(arr, i, min((i+RUN-1),
									(n-1)));

	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n;
							size = 2*size)
	{
		
		// pick starting point of
		// left sub array. We
		// are going to merge
		// arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we
		// increase left by 2*size
		for (int left = 0; left < n;
							left += 2*size)
		{
			
			// find ending point of
			// left sub array
			// mid+1 is starting point
			// of right sub array
			int mid = left + size - 1;
			int right = min((left + 2*size - 1),
											(n-1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			if(mid < right)
				mergeByMathGrade(arr, left, mid, right);
		}
	}
}

void insertionSortByLastName(Student arr[], int left, int right){
	for (int i = left + 1; i <= right; i++)
	{
		Student temp = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void mergeByLastName(Student arr[], int l, int m, int r){
	
  cout << "\n Merging";

	// Original array is broken in two parts
	// left and right array
	int len1 = m - l + 1, len2 = r - m;
	Student left[len1], right[len2];
	for (int i = 0; i < len1; i++)
		left[i] = arr[l + i];
	for (int i = 0; i < len2; i++)
		right[i] = arr[m + 1 + i];

	int i = 0;
	int j = 0;
	int k = l;

	// After comparing, we
	// merge those two array
	// in larger sub array
	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of left, if any
	while (i < len1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}

	// Copy remaining element of right, if any
	while (j < len2)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}

void timSortByLastName(Student arr[], int n){
	

  
	// Sort individual subarrays of size RUN
	for (int i = 0; i < n; i+=RUN)
		insertionSortByLastName(arr, i, min((i+RUN-1),
									(n-1)));

	// Start merging from size RUN (or 32).
	// It will merge
	// to form size 64, then 128, 256
	// and so on ....
	for (int size = RUN; size < n;
							size = 2*size)
	{
		
		// pick starting point of
		// left sub array. We
		// are going to merge
		// arr[left..left+size-1]
		// and arr[left+size, left+2*size-1]
		// After every merge, we
		// increase left by 2*size
		for (int left = 0; left < n;
							left += 2*size)
		{
			
			// find ending point of
			// left sub array
			// mid+1 is starting point
			// of right sub array
			int mid = left + size - 1;
			int right = min((left + 2*size - 1),
											(n-1));

			// merge sub array arr[left.....mid] &
			// arr[mid+1....right]
			if(mid < right)
				mergeByLastName(arr, left, mid, right);
		}
	}
}
//------------------------------------------------------------