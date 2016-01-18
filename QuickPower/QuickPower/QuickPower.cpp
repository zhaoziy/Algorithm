// QuickPower.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class QuickPower {
public:
	int getPower(int k, int N) {
		// write code here
		if (N == 0)
			return 1;
		if (N == 1)
			return k;
		long long temp = k;
		long long res = 1;
		while (N)
		{
			if (N & 1)
			{
				res = res * temp % 1000000007;
			}
			temp = temp * temp % 1000000007;
			N = N >> 1;
		}
		return res;
	}
};

int main()
{
	QuickPower q;
	int a = q.getPower(2, 14876069);
    return 0;
}

