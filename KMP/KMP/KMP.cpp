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
		int *next = NULL;
		next = getNext(pattern);
		int target_pt = 0;
		int pattern_pt = 0;
		while ( target_pt < target.size() && pattern_pt < pattern.size())
		{
			if (target[target_pt] != pattern[pattern_pt])
			{
				pattern_pt = next[pattern_pt + 1];
				pattern_pt--;
			}
			else
			{
				target_pt++;
				pattern_pt++;
			}

			if (pattern_pt == -1)
			{
				target_pt++;
				pattern_pt++;
			}
		}
		if (pattern_pt >= pattern.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int* getNext(string Pattern)
	{
		string Temp = " " + Pattern;
		int *next = new int[Temp.size()];
		next[0] = next[1] = 0;
		int i = 1;
		int j = 0;
		while (i < Pattern.size())
		{
			if ( j==0 || Temp[i] == Temp[j])
			{
				i++;
				j++;
				if (Temp[i] == Temp[j])
				{
					next[i] = next[j];
				}
				else
				{
					next[i] = j;
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
	string str1 = "ababaaabcababaaabb";
	string str2 = "ababaaaba";
	KMP kmp;
	bool result = false;
	result = kmp.kmp(str1, str2);
	cout << result << endl;
    return 0;
}
