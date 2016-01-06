// chkParenthesis.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n % 2 == 1)
		{
			return false;
		}

		int num = 0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == '(')
			{
				num++;
			}
			else if(A[i] == ')')
			{
				num--;
			}
			if (num < 0)
			{
				return false;
			}
		}
		if (num != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	string A = "(()())";
	Parenthesis pa;
	bool result = pa.chkParenthesis(A, 6);
	cout << result;
    return 0;
}

