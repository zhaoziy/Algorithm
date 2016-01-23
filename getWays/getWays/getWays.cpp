// getWays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class LonelyA {
public:
	int getWays(int n, int A, int b, int c) {
		// write code here
		int headtail = (n - 2)*(n - 3);
		int noheadtail = (n - 3)*(n - 4);
		int other = 1;
		int num = n - 3;
		while (num)
		{
			other *= num--;
		}
		return other*(2 * headtail + (n - 2)*noheadtail);
	}
};

int main()
{
    return 0;
}

