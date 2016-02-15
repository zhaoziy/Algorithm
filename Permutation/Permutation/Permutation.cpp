// Permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> ret;
		if (str.size() == 0)
			return ret;
		set<string> retset;
		FullArray(str, str.size(), 0, retset);
		set<string>::iterator it;
		for (it = retset.begin(); it != retset.end(); ++it)
		{
			ret.push_back(*it);
		}
		return ret;
	}

	void swap(string &str, int i, int j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	void FullArray(string &str, int size, int index, set<string> &ret)
	{
		if (index >= size)
		{
			ret.insert(str);
		}

		for (int i = index; i < size; ++i)
		{
			swap(str, i, index);
			FullArray(str, size, index + 1, ret);
			swap(str, i, index);
		}
	}
};

int main()
{
	string a;
	Solution s;
	s.Permutation(a);
    return 0;
}

