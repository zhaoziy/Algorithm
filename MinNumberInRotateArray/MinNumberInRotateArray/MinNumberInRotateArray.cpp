// MinNumberInRotateArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		vector<int> temp;
		int Min = 0;
		for(int i = 0; i < rotateArray.size(); ++i)
		{
			if (Min > rotateArray[i])
			{
				Min = rotateArray[i];
			}
		}
		for (int j = 0; j < 2; ++j)
		{
			for (int i = 0; i < rotateArray.size(); ++i)
			{
				temp.push_back(rotateArray[i]);
			}
		}
		

	}
};

int main()
{
    return 0;
}

