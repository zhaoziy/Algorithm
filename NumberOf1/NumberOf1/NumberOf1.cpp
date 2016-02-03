// NumberOf1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		int m = 0;
		int flag = 1;
		while (m++ < 32)
		{
			if ((n & flag) == flag)
			{
				count++;
			}
			flag = flag << 1;
		}
		return count;
	}
};

int main()
{
	Solution a;
	a.NumberOf1(0);
    return 0;
}

