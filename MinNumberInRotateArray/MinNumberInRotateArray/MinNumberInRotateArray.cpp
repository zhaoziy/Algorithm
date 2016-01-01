// MinNumberInRotateArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int MinIndex = 0;
		int Min = rotateArray[0];
		for (int i = 0; i < rotateArray.size(); ++i)
		{
			if (rotateArray[i] < Min)
			{
				MinIndex = i;
			}
		}

	}
};

int main()
{
    return 0;
}

