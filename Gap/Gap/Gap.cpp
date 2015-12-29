// Gap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Gap {
public:
	int maxGap(vector<int> A, int n) {
		// write code here
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
	Gap gap;
	B = gap.maxGap(init_Array, init_Array.size());

	cout << B << endl;

	return 0;
}
