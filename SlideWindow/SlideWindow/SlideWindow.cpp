// SlideWindow.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
using namespace std;

//class SlideWindow {
//public:
//	vector<int> slide(vector<int> arr, int n, int w) {
//		// write code here
//		vector<int> result;
//		int MaxNum = 0;
//		for (int j = 0; j < n - w + 1; ++j)
//		{
//			if (MaxNum < j)
//			{
//				MaxNum = j;
//			}
//			int temp = arr[MaxNum];
//			for (int i = MaxNum; i < w + j; ++i)
//			{
//				if (temp < arr[i])
//				{
//					temp = arr[i];
//					MaxNum = i;
//				}
//			}
//			result.push_back(arr[MaxNum]);
//		}
//		return result;
//	}
//};

class SlideWindow {
public:
	vector<int> slide(vector<int> arr, int n, int w) {
		// write code here
		vector<int> result;
		deque<int> qMax;
		int i = 0;
		while (i < n)
		{
			if (qMax.empty() || arr[i] < arr[qMax.back()])
			{
				qMax.push_back(i);
			}
			else
			{
				qMax.pop_back();
				continue;
			}

			if (i >= w - 1)
			{
				if (qMax.front() < i - w + 1)
				{
					qMax.pop_front();
				}
				result.push_back(arr[qMax.front()]);
			}
			i++;
		}
		return result;
	}
};

int main()
{
	vector<int> num_result;
	vector<int> num;

	num.push_back(357);
	num.push_back(564);
	num.push_back(212);
	num.push_back(500);
	num.push_back(96);
	
	SlideWindow sw;
	num_result = sw.slide(num, 5, 3);
    return 0;
}
