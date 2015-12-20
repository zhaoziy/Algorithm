// HeapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class HeapSort {
public:
	int* heapSort(int* A, int n) {
		// write code here
		int temp = 0;

		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(A, i);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int i = n / 2; i >= 0; i--)
			{
				heapify(A, i);
			}
			temp = A[0];
			A[0] = A[n - i - 1];
			A[n - i - 1] = temp;
		}

		return A;
	}

	void heapify(int* A, int i)
	{
		int temp = 0;
		int Left = 2 * i + 1;
		int Right = 2 * i + 2;

		if (A[i] < A[Left])
		{
			temp = A[i];
			A[i] = A[Left];
			A[Left] = temp;
		}

		if (A[i] < A[Right])
		{
			temp = A[i];
			A[i] = A[Right];
			A[Right] = temp;
		}
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