// rectCover.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int rectCover(int number) {
		if (number == 0 || number == 1)
			return 1;
		if (number == 2)
			return 2;
		return rectCover(number - 1) + rectCover(number - 2);
	}
};

int main()
{
    return 0;
}

