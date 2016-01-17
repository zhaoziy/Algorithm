// getLessIndex.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int getLessIndex(vector<int> arr) {
		if (arr.size() == 0)
			return -1;
		else if (arr.size() == 1)
			return 0;

		if (arr[0] < arr[1])
			return 0;
		if (arr[arr.size() - 1] < arr[arr.size() - 2])
			return arr.size() - 1;

		int left = 0;
		int mid = arr.size() / 2;
		int right = arr.size() - 1;
		while (right - left > 1)
		{
			if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
			{
				return mid;
			}
			else if (arr[mid - 1] < arr[mid + 1])
			{
				right = mid;
				mid = (left + right) / 2;
			}
			else
			{
				left = mid;
				mid = (left + right) / 2;
			}
		}
		return -1;
	}
};

int main()
{
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(1);
	arr.push_back(5);
	arr.push_back(9);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(5);
	arr.push_back(3);
	arr.push_back(0);
	arr.push_back(8);
	arr.push_back(4);
	arr.push_back(5); 
	arr.push_back(8);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(0);
	arr.push_back(5);
	arr.push_back(0);
	arr.push_back(4);
	Solution s;
	s.getLessIndex(arr);
    return 0;
}

