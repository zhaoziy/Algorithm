// Fibonacci.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	int Fibonacci(int n) {
		if (n == 1)
		{
			return 1;
		}
		else if (n == 2)
		{
			return 1;
		}
		int num1 = 1;
		int num2 = 1;
		int result = 0;
		for (int i = 2; i < n; ++i)
		{
			result = num1 + num2;
			num1 = num2;
			num2 = result;
		}
		return result;
	}
};

//class Solution {
//public:
//	int Fibonacci(int n) {
//		if (n == 1)
//		{
//			return 1;
//		}
//		else if (n == 2)
//		{
//			return 1;
//		}
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//};

int main()
{
	Solution so;
	int i = so.Fibonacci(6);
    return 0;
}

