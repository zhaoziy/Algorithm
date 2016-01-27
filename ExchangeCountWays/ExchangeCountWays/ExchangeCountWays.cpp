// ExchangeCountWays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <windows.h>
using namespace std;

class Exchange {
public:
	int countWays(vector<int> penny, int n, int aim) {
		// write code here
		DWORD start, end;
		start = GetTickCount();

		vector<int> line;
		vector< vector<int> > array;

		for (int i = 0; i < aim + 1; ++i)
		{
			for (int j = 0; j < penny.size() + 1; ++j)
				line.push_back(-1);
			array.push_back(line);
			line.erase(line.begin(), line.end());
		}

		int result = Count(penny, 0, aim, array);

		end = GetTickCount();
		printf("time=%d\n", end - start);
		return result;
	}

	int Count(vector<int> penny, int index, int aim, vector< vector<int> > &array)
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
				int temp = 0;
				if (array[aim - penny[index] * i][index + 1] == -1)
				{
					temp = Count(penny, index + 1, aim - penny[index] * i, array);
					array[aim - penny[index] * i][index + 1] = temp;
				}
				else
				{
					temp = array[aim - penny[index] * i][index + 1];
				}
				res += temp;
				//cout << i << endl;
			}
		}
		return res;
	}
};

//class Exchange {
//public:
//	int countWays(vector<int> penny, int n, int aim) {
//		 write code here
//		DWORD start, end;
//		start = GetTickCount();
//
//		int result = Count(penny, 0, aim);
//
//		end = GetTickCount();
//		printf("time=%d\n", end - start);
//
//		return result;
//	}
//
//	int Count(vector<int> penny, int index, int aim)
//	{
//		int res = 0;
//		if (index == penny.size())
//		{
//			res = (aim == 0) ? 1 : 0;
//		}
//		else
//		{
//			for (int i = 0; penny[index] * i <= aim; ++i)
//			{
//				res += Count(penny, index + 1, aim - penny[index] * i);
//				cout << i << endl;
//			}
//		}
//		return res;
//	}
//};

int main()
{
	vector<int> penny;
	penny.push_back(5);
	penny.push_back(10);
	penny.push_back(25);
	penny.push_back(1);
	Exchange e;
	e.countWays(penny, 4, 500);
	return 0;
}

