// jumpFloorII.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 1)
			return 1;
		return 2 * jumpFloorII(number - 1);
	}
};

int main()
{
	Solution s;
	int i = s.jumpFloorII(2);
    return 0;
}

