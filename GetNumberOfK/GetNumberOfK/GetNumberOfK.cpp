// GetNumberOfK.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if ((int)data.size() == 0)
			return 0;
		int left = 0;
		int right = (int)data.size() - 1;
		int mid = 0;
		int start = -1;
		int end = -1;
		while (left  <= right)
		{
			mid = left + (right - left) / 2;
			if (data[mid] >= k)
			{
				right = mid - 1;
				if (data[mid] == k)
				{
					start = mid;
				}
			}
			else
			{
				left = mid + 1;
			}
		}

		left = start;
		right = (int)data.size() - 1;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (data[mid] > k)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
				if (data[mid] == k)
				{
					end = mid;
				}
			}
		}
		return (end == -1 || start == -1) ? (0) : (end - start + 1);
	}
};

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(3);
	data.push_back(3);
	data.push_back(3);
	data.push_back(4);
	data.push_back(5);
	Solution s;
	s.GetNumberOfK(data, 3);
    return 0;
}

