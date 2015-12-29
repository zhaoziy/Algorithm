// Merge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Merge {
public:
	int* mergeAB(int* A, int* B, int n, int m) {
		// write code here
		int i = n - 1;
		int j = m - 1;
		int count = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			if (A[i] < B[j])
			{
				A[count--] = B[j--];
			}
			else
			{
				A[count--] = A[i--];
			}
		}
		while (i >= 0)
		{
			A[count--] = A[i--];
		}
		while (j >= 0)
		{
			A[count--] = B[j--];
		}
		return A;
	}
};

int main()
{
	int A[3] = { 2,4,6 };
	int B[4] = { 1,3,5,7 };
	Merge sort;
	sort.mergeAB(A, B, 3, 4);
	for (int i = 0; i < 7; ++i)
	{
		cout << A[i] << endl;
	}
	return 0;
}
