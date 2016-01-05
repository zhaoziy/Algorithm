// findSmallest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Prior {
public:
	string findSmallest(vector<string> strs, int n) {
		// write code here
		string Result;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (Sort(strs[i], strs[j]) == 2)
				{
					swap(strs, i, j);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			Result += strs[i];
		}
		return Result;
	}

	int Sort(string str1, string str2)
	{
		if (str1 == str2)
		{
			return 0;
		}
		string strA = str1 + str2;
		string strB = str2 + str1;
		for (int i = 0; i < strA.size(); ++i)
		{
			if (strA[i] < strB[i])
			{
				return 1;
			}
			else if(strA[i] > strB[i])
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}
	}

	void swap(vector<string> &str, int i, int j)
	{
		string temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
};

int main()
{
	vector<string> B;
	string A[2];
	A[0] = "de";
	A[1] = "abc";
	B.push_back(A[0]);
	B.push_back(A[1]);
	Prior prior;
	string Result = prior.findSmallest(B, B.size());
	cout << Result;
    return 0;
}

