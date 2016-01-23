// countWays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Robot {
public:
	int countWays(int x, int y) {
		// write code here
		int a = x + y - 2;
		int temp = 1;
		int temp_1 = 1;
		for (int i = 0; i < x - 1; ++i)
		{
			temp *= a--;
			temp_1 *= i + 1;
		}
		return temp / temp_1;
	}
};

int main()
{
    return 0;
}

