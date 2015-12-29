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
