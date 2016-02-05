// IsPopOrder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() == true || popV.empty() == true)
			return false;
		stack<int> temp;
		int j = 0;
		for (int i = 0; i < pushV.size(); ++i)
		{
			if (pushV[i] == popV[j])
			{
				j++;
			}
			else if (temp.empty()!= true && popV[j] == temp.top())
			{
				temp.pop();
			}
			else
			{
				temp.push(pushV[i]);
			}
		}
		if (!temp.empty())
		{
			for (; j < popV.size(); j++)
			{
				if (popV[j] == temp.top())
				{
					temp.pop();
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<int> pushV;
	vector<int> popV;

	pushV.push_back(1);
	pushV.push_back(2);
	pushV.push_back(3);
	pushV.push_back(4);
	pushV.push_back(5);

	popV.push_back(1);
	popV.push_back(3);
	popV.push_back(4);
	popV.push_back(2);
	popV.push_back(5);

	Solution s;
	s.IsPopOrder(pushV, popV);

    return 0;
}

