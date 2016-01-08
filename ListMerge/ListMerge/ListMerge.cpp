// ListMerge.cpp : 定义控制台应用程序的入口点。
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;

		ListNode* Head = NULL;
		ListNode* Current = NULL;
		if (pHead1->val < pHead2->val)
		{
			Head = Current = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			Head = Current = pHead2;
			pHead2 = pHead2->next;
		}

		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val < pHead2->val)
			{
				Current->next = pHead1;
				pHead1 = pHead1->next;
				Current = Current->next;
			}
			else
			{
				Current->next = pHead2;
				pHead2 = pHead2->next;
				Current = Current->next;
			}
		}

		if (pHead1 != NULL)
		{
			Current->next = pHead1;
		}

		if (pHead2 != NULL)
		{
			Current->next = pHead2;
		}
	
		return Head;
	}
};

int main()
{
	ListNode Node1(1);
	ListNode Node2(2);
	ListNode Node3(3);
	ListNode Node4(4);
	Node1.next = &Node3;
	Node2.next = &Node4;
	Solution so;
	so.Merge(&Node1, &Node2);
	return 0;
}

