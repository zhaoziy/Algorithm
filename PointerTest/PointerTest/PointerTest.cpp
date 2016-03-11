// PointerTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void pointerTest(int *a)
{
	*a = 5;
}

int main()
{
	int c = 4;
	int *d = &c;
	pointerTest(d);
    return 0;
}

