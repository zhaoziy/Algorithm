// Sum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Solution {
public:
	int Sum_Solution(int n) {
		int ret = n;
		ret && (ret += Sum_Solution(n - 1));
		return ret;
	}
};

int main()
{
	Solution s;
	int a = s.Sum_Solution(5);

    return 0;
}

