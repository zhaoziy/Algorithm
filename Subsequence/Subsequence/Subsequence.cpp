// Subsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Subsequence {
public:
	int shortestSubsequence(vector<int> A, int n)
	{
		// write code here
		int MAX = A[0];
		int right = 0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] >= MAX)
			{
				MAX = A[i];
			}
			else
			{
				right = i;
			}
		}

		int MIN = A[n - 1];
		int left = n - 1;
		for (int i = n - 1; i >= 0; --i)
		{
			if (A[i] <= MIN)
			{
				MIN = A[i];
			}
			else
			{
				left = i;
			}
		}
		if (left >= right)
		{
			return 0;
		}
		else
		{
			return right - left + 1;
		}
	}
};

int main()
{
	int temp[6] = { 1,2,3,3,8,9 };
	vector<int> init_Array;
	for (int i = 0; i < 6; ++i)
	{
		init_Array.push_back(temp[i]);
	}
	int B = 0;
	Subsequence subsequence;
	B = subsequence.shortestSubsequence(init_Array, init_Array.size());

	cout << B << endl;

	return 0;
}
