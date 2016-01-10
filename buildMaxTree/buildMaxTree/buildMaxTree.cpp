// buildMaxTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class MaxTree {
public:
	vector<int> buildMaxTree(vector<int> A, int n) {
		// write code here
		stack<int> stackNum;
		vector<int> result;
		int *front = new int[n];
		int *back = new int[n];
		for (int i = 0; i < n; ++i)
		{
			if (stackNum.empty())
			{
				stackNum.push(i);
				front[i] = -1;
			}
			else	if (A[i] < A[stackNum.top()])
			{
				front[i] = stackNum.top();
				stackNum.push(i);
			}
			else
			{
				stackNum.pop();
				i--;
			}
		}

		while (!stackNum.empty())
		{
			stackNum.pop();
		}

		for (int i = n-1; i >=0; --i)
		{
			if (stackNum.empty())
			{
				stackNum.push(i);
				back[i] = -1;
			}
			else	if (A[i] < A[stackNum.top()])
			{
				back[i] = stackNum.top();
				stackNum.push(i);
			}
			else
			{
				stackNum.pop();
				i++;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (front[i] == -1 && back[i] == -1)
			{
				result.push_back(-1);
			}
			else if(front[i] == -1 && back[i] != -1)
			{
				result.push_back(back[i]);
			}
			else if (front[i] != -1 && back[i] == -1)
			{
				result.push_back(front[i]);
			}
			else if(A[front[i]] < A[back[i]])
			{
				result.push_back(front[i]);
			}
			else
			{
				result.push_back(back[i]);
			}
		}

		return result;
	}
};

int main()
{
	vector<int> NUM;
	NUM.push_back(3);
	NUM.push_back(1);
	NUM.push_back(4);
	NUM.push_back(2);
	
	MaxTree mt;
	vector<int> result;
	result = mt.buildMaxTree(NUM, 4);
    return 0;
}

