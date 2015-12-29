// HeapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class HeapSort {
public:
	int* heapSort(int* A, int n) {
		// write code here
		for (int j = 0; j < n; ++j)
		{
			heapify(A, 0, n - j);
			swap(A[0], A[n - j - 1]);
		}
		return A;
	}

	void heapify(int* A, int j, int n)
	{
		for (int i = n / 2 - 1; i >= j; i--)
		{
			int Left = 2 * i + 1;
			int Right = 2 * i + 2;
			int large = i;

			if (Left < n)
			{
				if (A[i] < A[Left])
				{
					large = Left;
					if (Right < n && A[large] < A[Right])
					{
						large = Right;
					}
				}
				else if (Right < n && A[i] < A[Right])
				{
					large = Right;
				}				
			}

			if (large != i)
			{
				swap(A[i], A[large]);
				heapify(A, large, n);
			}
		}
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
	HeapSort sort;
	sort.heapSort(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}