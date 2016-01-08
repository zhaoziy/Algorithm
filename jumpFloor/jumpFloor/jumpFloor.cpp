// jumpFloor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int JumpFloor(int target) {
		if (target <= 0) {
			return -1;
		}
		else if (target == 1) {
			return 1;
		}
		else if (target == 2) {
			return 2;
		}
		else {
			return  JumpFloor(target - 1) + JumpFloor(target - 2);
		}
	}
};

int main()
{
	Solution so;
	int result = 0;
	result = so.jumpFloor(2);
    return 0;
}

