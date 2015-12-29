// ThreeColor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class ThreeColor {
public:
	vector<int> sortThreeColor(vector<int> A, int n) {
		// write code here
		
		return A;
	}
};

int main()
{
	int temp[6] = { 0,1,1,0,2,2 };
	vector<int> init_Array;
	for (int i = 0; i < 6; ++i)
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

