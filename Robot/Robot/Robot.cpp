// Robot.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Robot {
public: 
	int f[13][13];
public:
	int countWays(int x, int y) {
		// write code here
		for (int i = 0; i < 13; ++i)
		{
			for (int j = 0; j < 13; ++j)
				f[i][j] = 0;
		}
		if (x == 1 && y != 1)
		{
			f[x][y - 1] = fun(x, y - 1);
			return f[x][y - 1];
		}
		if (x != 1 && y == 1)
		{
			f[x - 1][y] = fun(x - 1, y);
			return f[x - 1][y];
		}
		if (x == 1 && y == 1)
			return 1;
		return fun(x, y - 1) + fun(x - 1, y);
	}

	int fun(int x, int y)
	{
		if (f[x][y] != 0)
			return f[x][y];
		int num1 = 0;
		int num2 = 0;
		if (x == 1 && y != 1)
		{
			f[x][y - 1] = fun(x, y - 1);
			return f[x][y - 1];
		} 
		if (x != 1 && y == 1)
		{
			f[x - 1][y] = fun(x - 1, y);
			return f[x - 1][y];
		}
		if (x == 1 && y == 1)
			return 1;
		return fun(x, y - 1) + fun(x - 1, y);
	}
};

int main()
{
	Robot a;
	int b = a.countWays(1, 11);
    return 0;
}

