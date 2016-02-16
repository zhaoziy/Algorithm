// EntryNodeOfLoop.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode* pFast = pHead;
		ListNode* pSlow = pHead;
		do
		{
			if (pSlow->next != NULL)
				pSlow = pSlow->next;
			else
				return NULL;
			if (pFast->next->next != NULL)
				pFast = pFast->next->next;
			else
				return NULL;
		} while (pFast != pSlow);
		pFast = pHead;
		while (pFast != pSlow)
		{
			pFast = pFast->next;
			pSlow = pSlow->next;
		}
		return pSlow;
	}
};

int main()
{
	return 0;
}

