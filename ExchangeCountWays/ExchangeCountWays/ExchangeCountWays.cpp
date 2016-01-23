// ExchangeCountWays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Exchange {
public:
	int countWays(vector<int> penny, int n, int aim) {
		// write code here
		int result = Count(penny, 0, aim);
		return result;
	}

	int Count(vector<int> penny, int index, int aim) 
	{
		int res = 0;
		if (index == penny.size())
		{
			res = (aim == 0) ? 1 : 0;
		}
		else
		{
			for (int i = 0; penny[index] * i <= aim; ++i)
			{
				res += Count(penny, index + 1, aim - penny[index] * i);
				cout << i << endl;
			}
		}
		return res;
	}
};

int main()
{
	vector<int> penny;
	penny.push_back(5);
	penny.push_back(10);
	penny.push_back(25);
	penny.push_back(1);
	Exchange e;
	e.countWays(penny, 4, 100);
    return 0;
}

