// MinValue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class MinValue {
public:
	int getMin(vector<int> arr, int n) {
		// write code here
		int min = 0;
		int left = 0;
		int right = n - 1;
		int mid = 0;

		if (arr[left] < arr[right])
		{
			return arr[0];
		}
		
		while (right > left)
		{
			if (left + 1 == right)
			{
				break;
			}
			mid = left + (right - left) / 2;
			if (arr[left] > arr[mid])
			{
				min = arr[mid];
				right = mid;
				continue;
			}
			if (arr[mid] > arr[right])
			{
				min = arr[right];
				left = mid;
				continue;
			}
			int i = 0;
			min = arr[0];
			while (i++ < n)
			{
				if (min > arr[i])
				{
					min = arr[i];
				}
			}
		}
		return min;
	}
};

int main()
{
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(3);
	//arr.push_back(618);
	MinValue m;
	m.getMin(arr, 5);
    return 0;
}

