// Checker.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Checker {
public:
	bool checkDuplicate(vector<int> a, int n) {
		// write code here
	}
};

int main()
{
	vector<int> init_Array;
	init_Array.push_back(1);
	init_Array.push_back(2);
	init_Array.push_back(3);
	init_Array.push_back(4);
	init_Array.push_back(5);
	init_Array.push_back(5);
	init_Array.push_back(6);

	Checker sort;
	bool result = false;
	result = sort.checkDuplicate(init_Array, init_Array.size());
	for (int i = 0; i < init_Array.size(); ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}