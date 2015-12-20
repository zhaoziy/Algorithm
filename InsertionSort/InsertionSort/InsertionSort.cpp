// InsertionSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class InsertionSort {
public:
	int* insertionSort(int* A, int n) {
		// write code here
		for (int i = 1; i < n; ++i)
		{
			for (int j = i - 1; j >= 0 && A[j + 1] < A[j]; j--)
			{
				swap(A[j + 1], A[j]);
			}
		}
		return A;
	}

	void swap(int &a, int &b)
	{
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
};

int main()
{
	int init_Array[13] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };
	//int init_Array[4] = { 54,35,48,36 };
	InsertionSort sort;
	sort.insertionSort(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}