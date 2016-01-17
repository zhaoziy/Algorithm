// MinValue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class MinValue {
public:
	int getMin(vector<int> arr, int n) {
		// write code here
		if (arr[0] < arr[n - 1])
		{
			return arr[0];
		}
		int min = 0;
		int left = 0;
		int right = n - 1;
		int mid = left + (right - left) / 2;
		while (right > left)
		{
			if (arr[left] > arr[mid])
			{
				min = arr[mid];
				if (right != mid)
				{
					right = mid;
				}
				else
				{
					break;
				}
				mid = left + (right - left) / 2;
			}
			else if (arr[mid] > arr[right])
			{
				min = arr[right];
				if (left != mid)
				{
					left = mid;
				}
				else
				{
					break;
				}
				mid = left + (right - left) / 2;
			}
			else
			{
				int i = 0;
				min = arr[0];
				while (i++ < n)
				{
					if (min > arr[i])
					{
						min = arr[i];
					}
				}
				break;
			}
		}
		return min;
	}
};

int main()
{
	vector<int> arr;
	arr.push_back(66);
	arr.push_back(240);
	arr.push_back(326);
	arr.push_back(330);
	arr.push_back(577);
	arr.push_back(618);
	MinValue m;
	m.getMin(arr, 6);
    return 0;
}

