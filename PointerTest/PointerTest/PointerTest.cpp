// PointerTest.cpp : �������̨Ӧ�ó������ڵ㡣
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

