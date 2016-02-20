// multiply.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> left;
		vector<int> right;
		vector<int> B;
		int size = (int)A.size();
		if (size <= 1)
			return B;
		left.push_back(1);
		left.push_back(A[0]);
		right.push_back(1);
		right.push_back(A[size - 1]);
		for (int i = 2; i < size; ++i)
		{
			left.push_back(left[i - 1] * A[i - 1]);
			right.push_back(right[i - 1] * A[size - i]);
		}
		B.push_back(right[size - 1]);
		for (int i = 1; i < size - 1; ++i)
		{
			B.push_back(left[i] * right[size - i - 1]);
		}
		B.push_back(left[size - 1]);
		return B;
	}
};

int main()
{
	vector<int> A;
	A.push_back(1);
	//A.push_back(2);
	/*A.push_back(3);
	A.push_back(4);
	A.push_back(5);*/
	Solution s;
	vector<int> B;
	B = s.multiply(A);
    return 0;
}

