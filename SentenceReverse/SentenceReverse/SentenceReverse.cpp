// SentenceReverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		int begin = 0;
		int end = (int)str.size() - 1;
		Reverse(str, begin, end);
		for (int i = begin; i <= end + 1; ++i)
		{
			if (str[i] == ' ' || i == end + 1)
			{
				Reverse(str, begin, i - 1);
				begin = i + 1;
			}
		}
		return str;
	}

	void Reverse(string &str, int begin, int end)
	{
		while (begin < end)
		{
			char temp;
			temp= str[begin];
			str[begin++] = str[end];
			str[end--] = temp;
		}
	}
};

int main()
{
	string a = "student. a am I";
	Solution s;
	s.ReverseSentence(a);
    return 0;
}

