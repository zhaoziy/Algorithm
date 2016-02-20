// deleteDuplication.cpp : 定义控制台应用程序的入口点。
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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode *head = pHead;
		ListNode *pre = pHead;
		ListNode *cur = pre->next;

		while (pre->val == cur->val)
		{
			cur = cur->next;
		}
		head = cur;

		ListNode *next = cur->next;

		while (cur != NULL)
		{
			if (next != NULL)
			{
				if (next->val != cur->val)
				{
					cur->next = next;
					cur = cur->next;
				}
				else
				{
					next = next->next;
				}
			}
			else
			{
				cur->next = next;
				cur = cur->next;
			}
		}
		return pHead;
	}
};

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(1);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(2);
	ListNode* node5 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	Solution s;
	s.deleteDuplication(node1);
	return 0;
}

