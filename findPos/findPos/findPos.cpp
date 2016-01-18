// findPos.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Find {
public:
	int findPos(vector<int> arr, int n) {
		// write code here
		if (arr[0] > n - 1 || arr[n - 1] < 0)
		{
			return -1;
		}
		int min = -1;
		int left = 0;
		int right = n - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (arr[mid] < mid)
			{
				left = mid + 1;
			}
			else if (arr[mid] > mid)
			{
				right = mid - 1;
			}
			else
			{
				min = mid;
				right = mid - 1;
			}
		}
		return min;
	}
};

int main()
{
	vector<int> arr;
	arr.push_back(-3);
	arr.push_back(1);
	arr.push_back(4);
	//arr.push_back(9);
	//arr.push_back(3);
	//arr.push_back(618);
	Find m;
	m.findPos(arr, 3);
	return 0;
}

