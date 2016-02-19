// FindContinuousSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<int> temp;
		vector<vector<int>> result;
		for (int i = 1; i <= sum / 2; ++i)
		{
			for (int j = i + 1; i <= sum / 2 + 1; ++j)
			{
				int s = (i + j)*(j - i + 1) / 2;
				if (s == sum)
				{
					for (int k = i; k <= j; ++k)
					{
						temp.push_back(k);
					}
					result.push_back(temp);
					temp.clear();
					break;
				}
				else if(s > sum)
				{
					break;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	s.FindContinuousSequence(3);
    return 0;
}

