// LeftRotateString.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if ((int)str.size() == 0)
			return "";
		string temp = str + str;
		int i = n % ((int)str.size());
		return temp.substr(i, (int)str.size());
	}
};

int main()
{
	string S = "abcdefg";
	Solution s;
	string a = s.LeftRotateString(S, 2);
    return 0;
}

