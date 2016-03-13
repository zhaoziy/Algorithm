// TheTime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
using namespace std;

int main()
{
	char input[10] = { 0 };
	int h = 0, m = 0;
	while (~scanf("%d:%d", &h, &m))
	{
		int input_Time = 0;
		scanf("%d", &input_Time);

		m += input_Time;
		while (m >= 60)
		{
			m -= 60;
			h += 1;
			if (h > 23)
				h -= 24;
		}

		printf("%0.2d:%0.2d\n", h, m);
	}
	return 0;
}