// reverseSentence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Reverse 
{
public:
	string reverseSentence(string A, int n) {
		// write code here
		reverseString(A, 0 , n -1);
		int begin = 0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == ' ')
			{
				reverseString(A, begin, i - 1);
				begin = i + 1;
			}
			if (i == n - 1)
			{
				reverseString(A, begin, i);
			}
		}
		return A;
	}

	void reverseString(string &Str, int begin, int end)
	{
		char temp = ' ';
		for (int i = begin; i <= begin + (end - begin) / 2; ++i)
		{
			temp = Str[i];
			Str[i] = Str[end + begin - i];
			Str[end + begin - i] = temp;
		}
	}
};

int main()
{
	string  A = "TUM MKIALI KVJUBEN VBSEWFT JAD AIZWEL CP LG PTB";
	Reverse rev;
	string Result = rev.reverseSentence(A, 47);
	cout << Result;
    return 0;
}

