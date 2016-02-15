// FindGreatestSumOfSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.size() == 0)
//			return 0;
//		int size = (int)array.size();
//		int maxSum = array[0];
//		for (int i = 0; i < size; ++i)
//		{
//			for (int j = i; j < size; ++j)
//			{
//				int sum = 0;
//				for (int k = i; k <= j; ++k)
//				{
//					sum += array[k];
//				}
//				if (sum > maxSum)
//					maxSum = sum;
//			}
//		}
//		return maxSum;
//	}
//};

//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.size() == 0)
//			return 0;
//		vector<int> array1;
//		vector<vector<int>> array2;
//		int size = array.size();
//		int temp = 0;
//		for (int j = 0; j < size; ++j)
//		{
//			for (int i = j; i < size; ++i)
//			{
//				if (i == j)
//				{
//					array1.push_back(array[i]);
//				}
//				else
//				{
//					array1.push_back(array1[i - j - 1] + array[i]);
//				}
//			}
//			array2.push_back(array1);
//			array1.clear();
//		}
//		int max = array2[0][0];
//		for (int j = 0; j < size; ++j)
//		{
//			int size1 = array2[j].size();
//			for (int i = 0; i < size1; ++i)
//			{
//				if (max < array2[j][i])
//				{
//					max = array2[j][i];
//				}
//			}
//		}
//		return max;
//	}
//};

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() <= 0)
			return 0;
		vector<int> dp;
		dp.push_back(array[0]);
		int Max = dp[0];
		for (int i = 1; i < (int)array.size(); i++)
		{
			if (dp[i - 1] <= 0)
				dp.push_back(array[i]);
			else if (dp[i - 1]>0)
				dp.push_back(array[i] + dp[i - 1]);
			if (Max < dp[i])
				Max = dp[i];
		}
		return Max;
	}
};

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(-2);
	a.push_back(3);
	a.push_back(10);
	a.push_back(-4);
	a.push_back(7);
	a.push_back(2);
	a.push_back(-5);
	Solution s;
	s.FindGreatestSumOfSubArray(a);
    return 0;
}

