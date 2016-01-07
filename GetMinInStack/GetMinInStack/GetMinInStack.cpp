// GetMinInStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;

class Solution {
	stack<int> stackData, stackMin;
public:
	void push(int value) {
		stackData.push(value);
		if (stackMin.empty())
		{
			stackMin.push(value);
		}
		else
		{
			if (value < stackMin.top())
			{
				stackMin.push(value);
			}
			else
			{
				stackMin.push(stackMin.top());
			}
		}
	}
	void pop() {
		stackMin.pop();
		stackData.pop();
	}
	int top() {
		return stackData.top();
	}
	int min() {
		return stackMin.top();
	}
};

int main()
{
	int num[6] = { 4,5,6,3,2,1 };
	Solution sou;
	for (int i = 0; i < 6; ++i)
	{
		sou.push(num[i]);
	}
	
	return 0;
}

