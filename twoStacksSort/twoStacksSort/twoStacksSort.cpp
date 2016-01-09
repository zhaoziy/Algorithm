// twoStacksSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//class TwoStacks {
//public:
//	vector<int> twoStacksSort(vector<int> numbers) {
//		// write code here
//		stack<int> stackNum;
//		stack<int> stackResult;
//		vector<int> result;
//		
//		for (int i = 0; i < numbers.size(); ++i)
//		{
//			stackNum.push(numbers[i]);
//		}
//		for (int i = 0; i < numbers.size(); ++i)
//		{
//			stackResult.push(GetMin(stackNum));
//		}
//		for (int i = 0; i < numbers.size(); ++i)
//		{
//			result.push_back(stackResult.top());
//			stackResult.pop();
//		}
//		return result;
//	}
//
//	int GetMin(stack<int> &stackNum)
//	{
//		int num = stackNum.top();
//		stackNum.pop();
//		int num1 = 0;
//		if (stackNum.empty())
//		{
//			return num;
//		}
//		else
//		{
//			num1 = GetMin(stackNum);
//		}
//
//		if (num < num1)
//		{
//			stackNum.push(num1);
//			return num;
//		}
//		else
//		{
//			stackNum.push(num);
//			return num1;
//		}
//	}
//};

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		// write code here
		stack<int> stackNum;
		stack<int> stackResult;
		vector<int> result;

		return result;
	}
};

int main()
{
	vector<int> Num;
	Num.push_back(1);
	Num.push_back(2);
	Num.push_back(3);
	Num.push_back(4);
	Num.push_back(5);
	TwoStacks ts;
	vector<int> i = ts.twoStacksSort(Num);
    return 0;
}

