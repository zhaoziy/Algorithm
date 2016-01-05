// chkRotation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Rotation {
public:
	bool chkRotation(string A, int lena, string B, int lenb) {
		// write code here
		if (lena != lenb)
		{
			return false;
		}
		else
		{
			string C = A + A;

		}
	}
	
};

int main()
{
	string A = "abcde";
	string B = "cdeab";
	Rotation rotation;
	bool result = false;
	result = rotation.chkRotation(A, 5, B, 5);
    return 0;
}

