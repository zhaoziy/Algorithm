// CountingSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class CountingSort {
public:
	typedef struct  Num
	{
		int num;
		int length;
	};
	int* countingSort(int* A, int n) {
		// write code here
		int Max = A[0];
		int Min = A[0];
		for (int i = 0; i < n; ++i)
		{
			if (A[i] > Max)
			{
				Max = A[i];
			}
			if (A[i] < Min)
			{
				Min = A[i];
			}
		}
		int Length = Max - Min + 1;
		Num *B = new Num[Length];
		for (int i = 0; i < Length; ++i)
		{
			B[i].num = 0;
			B[i].length = 0;
		}
		for (int i = 0; i < n; ++i)
		{
			B[A[i] - Min].num = A[i];
			B[A[i] - Min].length += 1;
		}
		int count = 0;
		for (int i = 0; i < Length; ++i)
		{
			for (int k = 0; k < B[i].length; ++k)
			{
				A[count] = B[i].num;
				count++;
			}
		}
		return A;
	}
};

int main()
{
	int init_Array[13] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };
	//int init_Array[4] = { 4,3,2,1 };
	CountingSort sort;
	sort.countingSort(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}
