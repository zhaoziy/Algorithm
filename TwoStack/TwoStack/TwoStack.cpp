// TwoStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class TwoStack {
public:
	stack<int> stack1, stack2;
	vector<int> twoStack(vector<int> ope, int n) {
		// write code here
		vector<int> result;
		for (int i = 0; i < ope.size(); ++i)
		{
			if (ope[i] > 0)
			{
				stack1.push(ope[i]);
			}
			else if(ope[i] == 0)
			{
				while (!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
				result.push_back(stack2.top());
				stack2.pop();
				while (!stack2.empty())
				{
					stack1.push(stack2.top());
					stack2.pop();
				}
			}
		}
		return result;
	}
};

int main()
{
	int num[6] = { 1,2,3,0,4,0 };
	vector<int> ope;
	for (int i = 0; i < 6; ++i)
	{
		ope.push_back(num[i]);
	} 
	TwoStack ts;
	vector<int> result = ts.twoStack(ope, ope.size());
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i];
	}
	return 0;
}

