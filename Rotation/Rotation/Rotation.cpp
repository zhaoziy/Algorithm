// Rotation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Rotation {
public:
	bool chkRotation(string A, int lena, string B, int lenb) {
		// write code here
		return true;
	}
};

int main()
{
	string A = "abc";
	string B = "bca";
	Rotation rotation;
	bool Result = false;
	Result = rotation.chkRotation(A, 3, B, 3);
	cout << Result << endl;
	return 0;
}
