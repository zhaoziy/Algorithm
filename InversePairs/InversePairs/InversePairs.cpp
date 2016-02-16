// InversePairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

//class Solution {
//public:
//	int InversePairs(vector<int> data) {
//		if ((int)data.size() == 0)
//			return 0;
//		int count = 0;
//		for (int i = 0; i < (int)data.size() - 1; ++i)
//		{
//			for (int j = i + 1; j < (int)data.size(); ++j)
//			{
//				if (data[i] > data[j])
//					count++;
//			}
//		}
//		return count;
//	}
//};

class Solution {
public:
	int InversePairs(vector<int> data) {
		if ((int)data.size() == 0)
			return 0;
		int ret = mergeSort(data, 0, (int)data.size() - 1);
		return ret;
	}

	int mergeSort(vector<int> &data, int start, int end)
	{
		int mid = start + (end - start) / 2;
		int ret = 0;
		if (start < end)
		{
			ret += mergeSort(data, start, mid);
			ret += mergeSort(data, mid + 1, end);
			ret += merge(data, start, mid, end);
		}
		return ret;
	}

	int merge(vector<int> &data, int start, int mid, int end)
	{
		int i = start;
		int j = mid+1;
		int ret = 0;
		vector<int> temp;
		while (i <= mid && j <= end)
		{
			if (data[i]>data[j])
			{
				ret += end - j + 1;
				temp.push_back(data[i++]);
			}
			else
			{
				temp.push_back(data[j++]);
			}
		}
		while (i <= mid)
		{
			temp.push_back(data[i++]);
		}
		while (j <= end)
		{
			temp.push_back(data[j++]);
		}
		for (int i = start; i <= end; ++i)
		{
			data[i] = temp[i - start];
		}
		return ret;
	}
};

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(3);
	Solution s;
	s.InversePairs(a);
    return 0;
}

