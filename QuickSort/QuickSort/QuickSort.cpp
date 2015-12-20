// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class QuickSort {
public:
	int* quickSort(int* A, int n) {
		// write code here
		Partition(A, 0, n-1);
		return A;
	}

	void Partition(int* A, int start, int end)
	{
		if (end - start <= 0)
		{
			return;
		}

		int mid = (start +end) / 2;
		int temp = 0;
		temp = A[mid];
		A[mid] = A[end];
		A[end] = temp;
		int count = start;
		for (int i = start; i < end; ++i)
		{
			if (A[i] < A[end])
			{
				temp = A[i];
				A[i] = A[count];
				A[count] = temp;
				count++;
				continue;
			}
		}
		temp = A[count];
		A[count] = A[end];
		A[end] = temp;
		Partition(A, start, count -1);
		Partition(A, count + 1, end);
	}
};


int main()
{
	int init_Array[13] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };
	QuickSort sort;
	sort.quickSort(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}