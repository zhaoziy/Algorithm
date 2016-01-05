// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class KMP
{
public:
	bool kmp(string target, string pattern)
	{
		int *next;
		
		next = getNext(pattern);
		return true;
	}

	int* getNext(string T)
	{
		int *next = new int[T.size()];
		next[0] = -1;
		int i = 1;
		int j = 0;
		while (i < T.size() - 1)
		{
			if ( j==0||T[i] == T[j])
			{
				i++;
				j++;
				next[i - 1] = j -1;
			}
			else
			{
				j = next[j];
			}
		}
		return next;
	}
};

int main()
{
	string str1 = "abcdef";
	string str2 = "ababaaaba";
	KMP kmp;
	bool result = false;
	result = kmp.kmp(str1, str2);
	cout << result << endl;
    return 0;
}
