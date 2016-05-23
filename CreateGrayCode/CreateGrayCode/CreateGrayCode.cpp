// CreateGrayCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> BRGC(int n)
{
	if (n == 1)
	{
		vector<string> temp;
		temp.push_back("0");
		temp.push_back("1");
		return temp;
	}
	else
	{
		vector<string> L1, L2;
		L1 = BRGC(n - 1);
		for (int i = 0; i < L1.size(); ++i)
			L2.push_back(L1.at(L1.size() - i - 1));
		for (int i = 0; i < L1.size(); ++i)
			L1.at(i) = "0" + L1.at(i);
		for (int i = 0; i < L2.size(); ++i)
			L2.at(i) = "1" + L2.at(i);
		for (int i = 0; i < L2.size(); ++i)
			L1.push_back(L2.at(i));
		return L1;
	}
}

int main()
{
	vector<string> RE;
	RE = BRGC(4);
	for (int i = 0; i < RE.size(); ++i)
	{
		cout << RE.at(i) << endl;
	}
    return 0;
}

