// KMP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class KMP
{
public:
	bool kmp(string str1, string str2)
	{

		return true;
	}
};

int main()
{
	string str1 = "abcdef";
	string str2 = "bcd";
	KMP kmp;
	bool result = false;
	result = kmp.kmp(str1, str2);
	cout << result << endl;
    return 0;
}

