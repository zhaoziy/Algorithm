// GetMedian.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
	vector<int> arr;
public:
	void Insert(int num)
	{
		arr.push_back(num);
		sort(arr);
	}

	double GetMedian()
	{
		int size = (int)arr.size();
		if (size % 2 == 1)
		{
			return (double)arr[size / 2];
		}
		else
		{
			int a = arr[size / 2 - 1];
			int b = arr[size / 2];
			return (double)(a + b) / 2;
		}
	}

	void sort(vector<int> &arr)
	{
		for (int i = 0; i < (int)arr.size() + 1; ++i)
			for (int j = i + 1; j < (int)arr.size(); ++j)
			{
				if (arr[i] > arr[j])
				{
					swap(arr[i], arr[j]);
				}
			}
	}
};

int main()
{
	Solution s;
	s.Insert(5);
	s.Insert(2);
	s.GetMedian();
	return 0;
}

