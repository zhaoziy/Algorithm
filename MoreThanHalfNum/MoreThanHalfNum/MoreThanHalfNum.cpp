// MoreThanHalfNum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if (numbers.size() == 0)
//			return 0;
//		int max = numbers[0];
//		int min = numbers[0];
//		for (int i = 1; i < numbers.size(); ++i)
//		{
//			if (numbers[i] > max)
//			{
//				max = numbers[i];
//			}
//			if (numbers[i] < min)
//			{
//				min = numbers[i];
//			}
//		}
//		int *hash = new int[max - min + 1];
//		for (int i = 0; i < numbers.size(); ++i)
//		{
//			hash[numbers[i] - min] = 0;
//		}
//		for (int i = 0; i < numbers.size(); ++i)
//		{
//			hash[numbers[i] - min]++;
//		}
//		for (int i = 0; i < max - min + 1; ++i)
//		{
//			if (hash[i] > numbers.size() / 2)
//				return i + min;
//		}
//		return 0;
//	}
//};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
		int size = numbers.size();
		int k = numbers[0];
		int count = 1;
		for (int i = 1; i < size; ++i)
		{
			if (numbers[i] == k)
				++count;
			else
				--count;
			if (count < 0)
			{
				k = numbers[i];
				count = 1;
			}
		}
		count = 0;
		for (int i = 0; i < size; ++i)
		{
			if (numbers[i] == k)
				++count;
		}
		return (count * 2 > size) ? (k) : (0);
	}
};

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	a.push_back(2);
	a.push_back(2);
	a.push_back(5);
	a.push_back(4);
	a.push_back(2);
	Solution ba;
	ba.MoreThanHalfNum_Solution(a);
    return 0;
}

