// getLessIndex.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int getLessIndex(vector<int> arr) {
		if (arr.size() == 0)
			return -1;
		else if (arr.size() == 1)
			return arr[0];
		if (arr[0] < arr[1])
			return arr[0];
		if (arr[arr.size() - 1] < arr[arr.size() - 2])
			return arr[arr.size() - 1];
	}
};

int main()
{
	vector<int> arr;
    return 0;
}

