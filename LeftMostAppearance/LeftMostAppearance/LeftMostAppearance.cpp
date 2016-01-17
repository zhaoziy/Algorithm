// LeftMostAppearance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class LeftMostAppearance {
public:
	int findPos(vector<int> arr, int n, int num) {
		// write code here
		if (arr[0] == num)
		{
			return 0;
		}
		int res = -1;
		int left = 0;
		int right = n - 1;
		int mid = left + (right - left) / 2;
		while (right - left >= 0)
		{
			if (arr[mid] >= num)
			{
				if (arr[mid] == num)
				{
					res = mid;
				}
				right = mid - 1;
				mid = left + (right - left) / 2;
			}
			else
			{
				left = mid + 1;
				mid = left + (right - left) / 2;
			}
		}
		return res;
	}
};

int main()
{
	vector <int> arr;
	arr.push_back(36);
	arr.push_back(62);
	arr.push_back(146);
	arr.push_back(208);
	arr.push_back(210);
	arr.push_back(369);
	arr.push_back(616);
	LeftMostAppearance l;
	l.findPos(arr, 7, 616);
    return 0;
}

