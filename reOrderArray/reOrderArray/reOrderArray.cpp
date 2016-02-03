// reOrderArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> a;
		vector<int> b;
		for (int i = 0; i < array.size(); ++i)
		{
			if (array[i] % 2)
			{
				a.push_back(array[i]);
			}
			else
			{
				b.push_back(array[i]);
			}
		}
		for (int i = 0; i < a.size(); ++i)
		{
			array[i] = a[i];
		}
		for (int i = 0; i < b.size(); ++i)
		{
			array[a.size() + i] = b[i];
		}
	}
};

int main()
{
    return 0;
}

