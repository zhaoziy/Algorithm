// GetUglyNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

//class Solution {
//public:
//	int GetUglyNumber_Solution(int index) {
//		int i = 1;
//		int j = 1;
//		while (i <= index)
//		{
//			if (isUglyNumber(j++) == 1)
//			{
//				i++;
//			}
//		}
//		return j - 1;
//	}
//
//	bool isUglyNumber(int num)
//	{
//		while (num % 2 == 0)
//		{
//			num /= 2;
//		}
//		while (num % 3 == 0)
//		{
//			num /= 3;
//		}
//		while (num % 5 == 0)
//		{
//			num /= 5;
//		}
//		if (num == 1)
//			return true;
//		else
//			return false;
//	}
//};

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		vector<int> UglyNum;
		UglyNum.push_back(1);
		UglyNum.push_back(2);
		UglyNum.push_back(3);
		UglyNum.push_back(4);
		UglyNum.push_back(5);
		if (index <= 5)
			return UglyNum[index - 1];
		int i = 5;
		while (i++ < index)
		{
			int num2 = GetUglyNumber(UglyNum, 2);
			int num3 = GetUglyNumber(UglyNum, 3);
			int num5 = GetUglyNumber(UglyNum, 5);
			UglyNum.push_back(max(num2, num3, num5));
		}
		return UglyNum[(int)UglyNum.size() - 1];
	}

	inline int max(int num1, int num2, int num3)
	{
		return (num1 > num2) ? ((num2 > num3) ? (num3) : (num2)) : ((num1 > num3) ? (num3) : (num1));
	}

	int GetUglyNumber(vector<int> &data, int num)
	{
		int size = (int)data.size();
		int MaxNum = data[size - 1];
		int left = 0;
		int right = size - 1;
		int mid = 0;
		while (left + 1 <= right)
		{
			if (left + 1 == right)
			{
				if (data[left] * num > MaxNum)
				{
					return data[left] * num;
				}
				else
				{
					return data[right] * num;
				}
			}
			mid = left + (right - left) / 2;
			if (data[mid] * num > MaxNum)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
		}
		return data[mid] * num;
	}
};

int main()
{
	Solution s;
	int a = s.GetUglyNumber_Solution(1500);
	return 0;
}

