// ScaleSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class ScaleSort {
public:
	vector<int> sortElement(vector<int> A, int n, int k) {
		// write code here
	}
};

int main()
{
	int init_Array[13] = { 54,35,48,36,27,12,44,44,8,14,26,17,28 };
	//int init_Array[4] = { 4,3,2,1 };
	ScaleSort sort;
	sort.sortElement(init_Array, 13);
	for (int i = 0; i < 13; ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}
