// rectCover.cpp : �������̨Ӧ�ó������ڵ㡣
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

