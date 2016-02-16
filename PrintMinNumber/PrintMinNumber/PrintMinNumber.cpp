// PrintMinNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <sstream>
using namespace std;

//class Solution {
//public:
//	string PrintMinNumber(vector<int> numbers) {
//		vector<string> ret;
//		per(numbers, 0, (int)numbers.size(), ret);
//		string minstr = ret[0];
//		for (int i = 1; i < (int)ret.size(); ++i)
//		{
//			if (minstr > ret[i])
//			{
//				minstr = ret[i];
//			}
//		}
//		return minstr;
//	}
//
//	void per(vector<int> numbers, int index, int size, vector<string> &ret)
//	{
//		if (index >= size)
//		{
//			string retstr;
//			for (int i = 0; i < size; ++i)
//			{
//				string str;
//				to_string(str, numbers[i]);
//				retstr += str;
//			}
//			ret.push_back(retstr);
//			return;
//		}
//		for (int i = index; i < size; ++i)
//		{
//			swap(numbers[i], numbers[index]);
//			per(numbers, index + 1, (int)numbers.size(), ret);
//			swap(numbers[i], numbers[index]);
//		}
//	}
//
//	void to_string(string &result, const int &t)
//	{
//		ostringstream oss;
//		oss << t;
//		result = oss.str();
//	}
//};

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> numbersStr;
		for (int i = 0; i < (int)numbers.size(); ++i)
		{
			numbersStr.push_back(to_string(numbers[i]));
		}
		for (int i = 0; i < (int)numbersStr.size() - 1; ++i)
		{
			for (int j = i + 1; j < (int)numbersStr.size(); ++j)
			{
				string a = numbersStr[i] + numbersStr[j];
				string b = numbersStr[j] + numbersStr[i];
				if (a > b)
				{
					swap(numbersStr[i], numbersStr[j]);
				}
			}
		}
		string str;
		for (int i = 0; i < (int)numbers.size(); ++i)
		{
			str += numbersStr[i];
		}
		return str;
	}

	string to_string(const int &t)
	{
		ostringstream oss;
		oss << t;
		return oss.str();
	}
};

int main()
{
	vector<int> numbers;
	numbers.push_back(456);
	numbers.push_back(1);
	numbers.push_back(23);
	Solution s;
	s.PrintMinNumber(numbers);
    return 0;
}

