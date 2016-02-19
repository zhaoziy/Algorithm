// FindNumbersWithSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> temp;
		int LeftNum = 0;
		int RightNum = (int)array.size() - 1;
		for (LeftNum = 0; LeftNum < (int)array.size() - 2; ++LeftNum)
		{
			int left = LeftNum + 1;
			int right = RightNum;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (array[mid] < sum - array[LeftNum])
				{
					left = mid + 1;
				}
				else if (array[mid] > sum - array[LeftNum])
				{
					right = mid - 1;
				}
				else
				{
					temp.push_back(array[LeftNum]);
					temp.push_back(array[mid]);
					break;
				}
			}
			if ((int)temp.size() != 0)
				break;
		}
		return temp;
	}
};

int main()
{
	vector<int> array;
	/*array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);*/
	vector<int> ret;
	Solution s;
	ret = s.FindNumbersWithSum(array, 5);
    return 0;
}

