// ShellSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class ShellSort {
public:
	int* shellSort(int* A, int n) {
		// write code here
		int step = n / 2;
		while (step > 0)
		{
			for (int i = step; i < n; ++i)
			{
				for (int j = i - step; j >= 0;  j -= step)
				{
					if (A[j + step] < A[j])
					{
						swap(A[j + step], A[j]);
					}
				}
			}
			step /= 2;
		}
		return A;
	}

	//int* shellSort(int* A, int n) {
	//	// write code here
	//	int step = n / 2;
	//	while (step > 0)
	//	{
	//		for (int i = step; i < n; ++i)
	//		{
	//			for (int j = i - step; j >= 0 && A[j + step] < A[j]; j -= step)
	//			{
	//				swap(A[j], A[j + step]);
	//			}
	//		}
	//		step /= 2;
	//	}
	//	return A;
	//}

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
	ShellSort sort;
	sort.shellSort(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}
