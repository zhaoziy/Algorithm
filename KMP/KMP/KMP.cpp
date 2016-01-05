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
		int i = 1;
		int j = 0;
		int *next = new int[T.size()+1];

		next[0] = next[1] = 0;
		
		while (i < T.length())
		{
			if (j == 0 | |T[i] == T[j])
			{
				i++;
				j++;
				if (T[i] != T[j])
				{
					next[i] = j;
				}
				else
				{
					next[i] = next[j];
				}
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
