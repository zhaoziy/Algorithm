// ScaleSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class ScaleSort {
public:
	vector<int> sortElement(vector<int> A, int n, int k) {
		// write code here
		for (int i = 0; i < n; ++i)
		{
			if (i + k - 1 < n)
			{
				heapSort(A, i, i + k - 1);
			}
			else
			{
				heapSort(A, i, n - 1);
			}
		}
		return A;
	}

	void heapSort(vector<int> &A, int begin, int end)
	{
		int n = end - begin + 1;
		int *B = new int[n];
		for (int i = 0; i < n; ++i)
		{
			B[i] = A[begin + i];
		}
		int NotAlone = n / 2 - 1;
		for (int i = NotAlone; i >= 0; i--)
		{
			adjust(B, i, n);
		}
		for (int i = 0; i < n; ++i)
		{
			A[begin + i] = B[i];
		}
		delete B;
		B = NULL;
	}

	int *adjust(int *A, int i, int n)
	{
		int temp = 0;

		int LeftChild = 2 * i + 1;
		int RightChild = 2 * i + 2;
		if (RightChild < n && A[i] > A[RightChild])
		{
			temp = A[i];
			A[i] = A[RightChild];
			A[RightChild] = temp;
			adjust(A, RightChild, n);
		}
		if (LeftChild < n && A[i] > A[LeftChild])
		{
			temp = A[i];
			A[i] = A[LeftChild];
			A[LeftChild] = temp;
			adjust(A, LeftChild, n);
		}
		return A;
	}
};

int main()
{
	vector<int> init_Array;
	init_Array.push_back(2);
	init_Array.push_back(1);
	init_Array.push_back(4);
	init_Array.push_back(3);
	init_Array.push_back(6);
	init_Array.push_back(5);
	init_Array.push_back(8);
	init_Array.push_back(7);
	init_Array.push_back(10);
	init_Array.push_back(9);

	ScaleSort sort;
	init_Array = sort.sortElement(init_Array, init_Array.size(), 4);
	for (int i = 0; i < init_Array.size(); ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}
