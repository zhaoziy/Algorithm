// FindNumsAppearOnce.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int temp = 0;
		for (int i = 0; i < data.size(); ++i)
		{
			temp = temp^data[i];
		}
		*num1 = temp;
	}
};

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(1);
	data.push_back(2);
	//data.push_back(3);
	data.push_back(4);
	Solution s;
	int a = 0;
	int b = 0;
	s.FindNumsAppearOnce(data, &a, &b);
    return 0;
}

