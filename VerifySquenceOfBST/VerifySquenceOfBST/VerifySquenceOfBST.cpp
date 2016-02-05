// VerifySquenceOfBST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;
		return judge(sequence, 0, sequence.size() - 1);
	}

	bool judge(vector<int> &sequence, int left, int right)
	{
		if (sequence.size() == 0 || left >= right)
			return true;

		int i = 0;
		for (i = right; i >= left; --i)
		{
			if (sequence[i] < sequence[right])
			{
				break;
			}
		}
		for (int j = i; j >= left; --j)
		{
			if (sequence[j] > sequence[right])
			{
				return false;
			}
		}
		return judge(sequence, left, i) && judge(sequence, i + 1, right - 1);
	}
};

//class Solution {
//public:
//	bool VerifySquenceOfBST(vector<int> sequence) {
//		if (sequence.size() == 0)
//			return false;
//		return judge(sequence);
//	}
//
//	bool judge(vector<int> sequence)
//	{
//		if (sequence.size() == 0)
//			return true;
//		int root = sequence[sequence.size() - 1];
//		bool ret = true;
//		vector<int> leftVec;
//		vector<int> rightVec;
//		int i = 0;
//		for (i = 0; i < sequence.size() - 1; ++i)
//		{
//			if (sequence[i] < root)
//			{
//				leftVec.push_back(sequence[i]);
//			}
//			else
//			{
//				break;
//			}
//		}
//		for (; i < sequence.size() - 1; ++i)
//		{
//			if (sequence[i] < root)
//			{
//				return false;
//			}
//			else
//			{
//				rightVec.push_back(sequence[i]);
//			}
//		}
//		return judge(leftVec) && judge(rightVec);
//	}
//};

int main()
{
	vector<int> leftVec;
	leftVec.push_back(1);
	leftVec.push_back(3);
	leftVec.push_back(2);
	leftVec.push_back(5);
	leftVec.push_back(7);
	leftVec.push_back(6);
	leftVec.push_back(4);
	Solution s;
	s.VerifySquenceOfBST(leftVec);

    return 0;
}

