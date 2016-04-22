// GoUpstairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class GoUpstairs {
public:
	long f[100000];
public:
	long countWays(int n) {
		// write code here
		for (int i = 0; i < 100000; ++i)
			f[i] = 0;
		f[1] = 1;
		f[2] = 2;
		f[3] = 4;
		return fun(n);
	}

	long fun(int n)
	{
		if (f[n] != 0)
			return f[n];
		else
		{
			long num = fun(n - 1) % 1000000007 + fun(n - 2) % 1000000007 + fun(n - 3) % 1000000007;
			num = num % 1000000007;
			f[n] = num;
			return num;
		}
	}
};

int main()
{
	GoUpstairs a;
	int b = a.countWays(36196);

    return 0;
}

