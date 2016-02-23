// FirstAppearingOnce.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution
{
	string str;
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		str += ch;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int hash[256] = { 0 };
		for (int i = 0; i < (int)str.size(); ++i)
		{
			hash[str[i]]++;
		}
		for (int i = 0; i < (int)str.size(); ++i)
		{
			if (hash[str[i]] == 1)
				return str[i];
		}
		return '#';
	}
};

int main()
{
	Solution s;
	s.FirstAppearingOnce();
    return 0;
}

