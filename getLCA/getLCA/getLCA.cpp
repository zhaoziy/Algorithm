// getLCA.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
			{
				a = a / 2;
			}
			else
			{
				b = b / 2;
			}
		}
		return a;
	}
};

int main()
{
    return 0;
}

