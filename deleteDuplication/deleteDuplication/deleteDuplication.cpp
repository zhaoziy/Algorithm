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
		ListNode *head = new ListNode(0);
		head->next = pHead;
		ListNode *pre = head;
		ListNode *cur = pHead;
		ListNode *next = pHead->next;
		while (next != NULL)
		{
			while (next != NULL && cur->val == next->val)
				next = next->next;
			if (cur->next == next)
			{
				pre = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				pre->next = next;
				cur = next;
				if (next != NULL)
					next = next->next;
			}
		}
		return head->next;
	}
};

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(1);
	/*ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(3);
	ListNode* node5 = new ListNode(4);
	ListNode* node6 = new ListNode(4);
	ListNode* node7 = new ListNode(5);*/
	node1->next = node2;
	/*node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;*/
	Solution s;
	ListNode* RET = s.deleteDuplication(node1);
	return 0;
}

