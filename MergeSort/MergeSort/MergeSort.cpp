// MergeSort.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;

class MergeSort {
public:
	int* mergeSort(int* A, int n)
	{
		// write code here
		divide(A, 0, n - 1);
		return A;
	}

	void divide(int *A, int start, int end)
	{
		if (end == start)
		{
			return;
		}
		else
		{
			int mid = (end + start) / 2;
			divide(A, start, mid);
			divide(A, mid + 1, end);
			merge(A, start, mid, end);
		}
	}

	void merge(int *A, int start, int mid, int end)
	{
		int l = start;
		int r = end;
		int m = mid + 1;
		int *ptc = new int[end - start + 1];
		int count = 0;
		while (l <= mid && m <= end)
		{
			if (A[l] > A[m])
			{
				ptc[count++] = A[m];
				m++;
			}
			else
			{
				ptc[count++] = A[l];
				l++;
			}
		}
		if (l == mid + 1)
		{
			while (m <= end)
			{
				ptc[count++] = A[m];
				m++;
			}
		}
		else
		{
			while (l <= mid)
			{
				ptc[count++] = A[l];
				l++;
			}
		}
		count = 0;
		for (int i = start; i <= end; ++i)
		{
			A[i] = ptc[count++];
		}
	}
};

int main()
{
	int init_Array[13] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };
	MergeSort sort;
	sort.mergeSort(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}