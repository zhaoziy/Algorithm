// RadixSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class RadixSort {
public:
	int* radixSort(int* A, int n) {
		// write code here
		int Max = 0;
		for (int i = 0; i < n; ++i)
		{
			int temp = A[i];
			int count = 1;
			while (temp >= 10)
			{
				count++;
				temp = temp / 10;
			}
			if (count > Max)
			{
				Max = count;
			}
		}
		
		vector<int> num[10];
		for (int j = 0; j < Max; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				num[(int)(A[i] / pow(10,j)) % 10].push_back(A[i]);
			}
			int count = 0;
			for (int i = 0; i < 10; ++i)
			{
				for (int k = 0; k < num[i].size(); ++k)
				{
					A[count] = num[i][k];
					count++;
				}
			}
			for (int i = 0; i < 10; ++i)
			{
				num[i].clear();
			}
		}
		return A;
	}
};

int main()
{
	int init_Array[13] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };
	//int init_Array[4] = { 4,3,2,1 };
	RadixSort sort;
	sort.radixSort(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}
