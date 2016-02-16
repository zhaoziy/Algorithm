// FirstNotRepeatingChar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if ((int)str.size() == 0)
			return -1;
		int *hash = new int[52];
		int ret = -1;
		for (int i = 0; i < 52; ++i)
		{
			hash[i] = 0;
		}
		for (int i = 0; i < (int)str.size(); ++i)
		{
			hash[str[i] - 'A'] += 1;
		}
		for (int j = 0; j < (int)str.size(); ++j)
		{
			if (hash[str[j] - 'A'] == 1)
			{
				ret = j;
				break;
			}
		}
		return ret;
	}
};

int main()
{
	string a = "google";
	Solution s;
	s.FirstNotRepeatingChar(a);
	return 0;
}

