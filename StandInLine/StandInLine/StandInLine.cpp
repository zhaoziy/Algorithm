// StandInLine.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

class StandInLine {
public:
	vector<int> getWays(int n, int a, int b) {
		// write code here
		vector<int> ret;
		int num = n;
		int temp = 1;
		for (int i = 0; i < n; ++i)
		{
			temp *= i + 1;
		}
		ret.push_back(temp / 2);
		temp = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			temp *= i + 1;
		}
		ret.push_back(temp);
		return ret;
	}
};

int main()
{
    return 0;
}

