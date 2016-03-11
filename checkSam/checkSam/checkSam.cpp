// checkSam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Same {
public:
	bool checkSam(string stringA, string stringB) {
		// write code here
		vector<string> A;
		vector<string> B;
		string temp;
		for (int i = 0; i < (int)stringA.size(); ++i)
		{
			if (stringA[i] != ' ')
			{
				temp += stringA[i];
			}
			else
			{
				A.push_back(temp);
				temp.clear();
			}
		}
		A.push_back(temp);
		temp.clear();
		for (int i = 0; i < (int)stringB.size(); ++i)
		{
			if (stringB[i] != ' ')
			{
				temp += stringB[i];
			}
			else
			{
				B.push_back(temp);
				temp.clear();
			}
		}
		B.push_back(temp);
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (int i = 0; i < (int)A.size(); ++i)
		{
			if (A[i] != B[i])
				return false;
		}
		return true;
	}
};

int main()
{
	string A = "Here you are";
	string B = "Are you here";
	Same s;
	bool a = s.checkSam(A, B);
	return 0;
}

