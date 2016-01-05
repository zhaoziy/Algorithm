// Transform.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Transform {
public:
	bool chkTransform(string A, int lena, string B, int lenb)
	{
		// write code here
		int stringA[256] = { 0 };
		int stringB[256] = { 0 };
		for (int i = 0; i < lena; ++i)
		{
			stringA[(int)A[i]]++;
		}
		for (int i = 0; i < lenb; ++i)
		{
			stringB[(int)B[i]]++;
		}
		for (int i = 0; i < 256; ++i)
		{
			if (stringA[i] != stringB[i])
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	string A = "abc";
	string B = "bca";
	Transform transform;
	bool Result = false;
	Result = transform.chkTransform(A, 3, B, 3);
	cout << Result << endl;
    return 0;
}

