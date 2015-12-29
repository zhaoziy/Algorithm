// ThreeColor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class ThreeColor {
public:
	vector<int> sortThreeColor(vector<int> A, int n)
	{
		// write code here
		int front = 0;
		int rear = n - 1;
		int cur = 0;
		while (cur <= rear)
		{
			if (A[cur] == 0)
			{
				swap(A[cur++], A[front++]);
			}
			else if (A[cur] == 1)
			{
				cur++;
			}
			else
			{
				swap(A[cur], A[rear--]);
			}
		}
		return A;
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
	int temp[12] = { 2,2,2,2,2,1,1,1,1,0,0,0 };
	vector<int> init_Array;
	for (int i = 0; i < 12; ++i)
	{
		init_Array.push_back(temp[i]);
	}
	vector<int> B;
	ThreeColor threeColor;
	B = threeColor.sortThreeColor(init_Array, init_Array.size());
	for (int i = 0; i < 6; ++i)
	{
		cout << B[i] << endl;
	}
	return 0;
}

