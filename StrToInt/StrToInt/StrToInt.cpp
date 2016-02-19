// StrToInt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int i = 0;
		int ret = 0;
		bool signal = false;
		while (i < (int)str.size())
		{
			if (str[i] == '+')
				signal = false;
			else if (str[i] == '-')
				signal = true;
			else if (str[i] < '0' || str[i]> '9')
				return 0;
			else if (str[i] != '-' && str[i] != '+')
				ret = ret * 10 + (str[i] - '0');
			i++;
		}
		if (signal == true)
			ret = -1 * ret;
		return ret;
	}
};

int main()
{
	string a = "123";
	Solution s;
	int b = s.StrToInt(a);
    return 0;
}

