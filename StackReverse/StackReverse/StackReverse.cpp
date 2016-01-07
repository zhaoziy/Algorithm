// StackReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class StackReverse {
	stack<int> stack1;
public:
	vector<int> reverseStack(vector<int> A, int n) {
		// write code here
		for (int i = n-1; i >= 0; --i)
		{
			stack1.push(A[i]);
		}
		reverse(stack1);
		vector<int> result;
		for (int i = 0; i < n; ++i)
		{
			result.push_back(stack1.top());
			stack1.pop();
		}
		return result;
	}

	void reverse(stack<int> &stackNum)
	{
		if (!stackNum.empty())
		{
			int ret = GetNum(stackNum);
			reverse(stackNum);
			stackNum.push(ret);
		}
		else
		{
			return;
		}
	}

	int GetNum(stack<int> &stackNum)
	{
		int num = stackNum.top();
		stackNum.pop();
		if (stackNum.empty())
		{
			return num;
		}
		int ret = GetNum(stackNum);
		stackNum.push(num);
		return ret;
	}
};

int main()
{
	int num[4] = { 4,3,2,1 };
	vector<int> ope;
	for (int i = 0; i < 4; ++i)
	{
		ope.push_back(num[i]);
	}
	StackReverse sr;
	vector<int> result = sr.reverseStack(ope, ope.size());
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i];
	}
	return 0;
}
