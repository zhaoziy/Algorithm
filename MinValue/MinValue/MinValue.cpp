// MinValue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class MinValue {
public:
	int getMin(vector<int> arr, int n) {
		// write code here
	}
};

int main()
{
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(3);
	MinValue m;
	m.getMin(arr, 5);
    return 0;
}

