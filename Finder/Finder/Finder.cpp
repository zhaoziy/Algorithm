// Finder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Finder {
public:
	bool findX(vector<vector<int> > mat, int n, int m, int x) {
		// write code here
	
		int i = 0;
		int j = m - 1;

		while (i < n && j >= 0)
		{
			if (mat[i][j] > x)
			{
				j--;
			}
			else if (mat[i][j] < x)
			{
				i++;
			}
			else
			{
				return true;
			}
		}
	
		return false;
	}
};

int main()
{
	vector<int> temp;
	vector<vector<int>> mat;
	int a1[4] = { 0, 1, 2, 4 };
	int a2[4] = { 2, 3, 4, 7 };
	int a3[4] = { 4, 4, 4, 8 };
	int a4[4] = { 5, 7, 7, 9 };
	int x = 10;
	for (int i = 0; i < 4; ++i)
	{
		temp.push_back(a1[i]);
	}
	mat.push_back(temp);
	temp.clear();

	for (int i = 0; i < 4; ++i)
	{
		temp.push_back(a2[i]);
	}
	mat.push_back(temp);
	temp.clear();

	for (int i = 0; i < 4; ++i)
	{
		temp.push_back(a3[i]);
	}
	mat.push_back(temp);
	temp.clear();

	for (int i = 0; i < 4; ++i)
	{
		temp.push_back(a4[i]);
	}
	mat.push_back(temp);
	temp.clear();

	bool result = false;
	Finder finder;
	result = finder.findX(mat, 4, 4, x);

	cout << result << endl;

    return 0;
}

