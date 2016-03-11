// FindNumsAppearOnce.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if ((int)data.size() < 2)
			return;
		int temp = 0;
		for (int i = 0; i < (int)data.size(); ++i)
			temp ^= data[i];
		int j = 0;
		for (; j < 8 * sizeof(int); ++j)
			if (((temp >> j) & 1) == 1)
				break;
		*num1 = 0;
		*num2 = 0;
		for (int i = 0; i < (int)data.size(); ++i)
			if (((data[i] >> j) & 1) == 0)
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
	}
};

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(4);
	Solution s;
	int a = 0;
	int b = 0;
	s.FindNumsAppearOnce(data, &a, &b);
    return 0;
}

