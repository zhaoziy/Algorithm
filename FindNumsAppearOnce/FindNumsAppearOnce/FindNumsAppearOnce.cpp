// FindNumsAppearOnce.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int size = data.size() / 2 + 1;
		int *array = new int[size];
		for (int i = 0; i < size; ++i)
		{
			array[i] = 0;
		}

		for (int i = 0; i < (int)data.size(); ++i)
		{
			array[data[i]]++;
		}
		int a = 0, b = 0;

		for (int i = 0; i < size; ++i)
		{
			if (array[i] % 2 == 1 && a == 0)
			{
				a = array[i];
				continue;
			}
			if (array[i] % 2 == 1 && b == 0)
			{
				a = array[i];
				break;
			}
		}
		*num1 = a;
		*num2 = b;
	}
};

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(1);
	data.push_back(2);
	data.push_back(2);
	data.push_back(3);
	data.push_back(4);
	Solution s;
	int a = 0;
	int b = 0;
	s.FindNumsAppearOnce(data, &a, &b);
    return 0;
}

