// Power.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Solution {
public:
	double Power(double base, int exponent) {
		double result = 1.0;
		if (exponent > 0)
		{
			for (int i = 0; i < exponent; ++i)
			{
				result *= base;
			}
		}
		else if (exponent == 0)
		{
			return 1;
		}
		else
		{
			for (int i = 0; i < -exponent; ++i)
			{
				result /= base;
			}
		}
		
		return result;
	}
};

int main()
{
	Solution so;
	double i = so.Power(2.0, -3);

    return 0;
}

