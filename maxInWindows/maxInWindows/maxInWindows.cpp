// maxInWindows.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> result;
		deque<int> qmax;
		int i = 0;
		while (i < (int)num.size())
		{
			if (qmax.empty() || num[i] <= num[qmax.back()])
				qmax.push_back(i);
			else
			{
				qmax.pop_back();
				continue;
			}

			if (i >= size - 1)
			{
				if (i < size + qmax.front())
				{
					result.push_back(num[qmax.front()]);
					i++;
				}
				else
					qmax.pop_front();
			}
			else
				i++;
		}
		return result;
	}
};

int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(2);
	a.push_back(6);
	a.push_back(2);
	a.push_back(5);
	a.push_back(1);

	Solution s;
	s.maxInWindows(a, 3);
    return 0;
}

