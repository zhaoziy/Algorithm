// MinNumberInRotateArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		int min = rotateArray[left];
		if (rotateArray[left] > rotateArray[right])
		{
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (rotateArray[left] < rotateArray[right])
				{
					return rotateArray[left];
				}
				if (rotateArray[mid] >= rotateArray[right])
				{
					min = rotateArray[right];
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
		}
		else if (rotateArray[left] == rotateArray[right])
		{
			while (left <= right)
			{
				if (min > rotateArray[left])
				{
					min = rotateArray[left];
				}
				left++;
			}
		}
		return min;
	}
};

int main()
{
	vector<int> a;
	a.push_back(6);
	a.push_back(7);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	Solution s;
	s.minNumberInRotateArray(a);
    return 0;
}

