// PrintListFromTailToHead.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	vector<int> printListFromTailToHead(struct ListNode* head)
	{
		vector<int> outRes;
		vector<int> temp;
		struct ListNode* pt1 = head;

		struct ListNode* pt = head;

		while (pt != NULL)
		{
			temp.push_back(pt->val);
			pt = pt->next;
		}

		for (int i = temp.size() - 1; i >= 0; --i)
		{
			outRes.push_back(temp[i]);
		}

		return outRes;
	}
};

int main()
{
	return 0;
}

