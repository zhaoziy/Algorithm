// stringTranslation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Translation {
public:
	string stringTranslation(string A, int n, int len) {
		// write code here
		swap(A, 0, len -1);
		swap(A, len, n - 1);
		swap(A, 0, n - 1);
		return A;
	}

	void swap(string &A, int begin, int end)
	{
		char temp = ' ';
		for (int i = begin; i <= (end + begin) / 2; ++i)
		{
			temp = A[i];
			A[i] = A[end - (i - begin)];
			A[end - (i - begin)] = temp;
		}
	}
};

int main()
{
	string STR = "ABCDE";
	Translation tra;
	string Result = tra.stringTranslation(STR, 5, 3);
	cout << Result;
    return 0;
}

