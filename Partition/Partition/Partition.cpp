// Partition.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* little = new ListNode(0);
		ListNode* big = new ListNode(0);
		ListNode* cur = pHead;
		ListNode* cur_Lit = little;
		ListNode* cur_Big = big;
		while(cur != NULL)
		{
			if (cur->val < x)
			{
				cur_Lit->next = cur;
				cur_Lit = cur_Lit->next;
				cur = cur->next;
				cur_Lit->next = NULL;
			}
			else
			{
				cur_Big->next = cur;
				cur_Big = cur_Big->next;
				cur = cur->next;
				cur_Big->next = NULL;
			}
		}
		cur_Lit->next = big->next;
		return little->next;
	}
};

int main()
{
	ListNode* node5 = new ListNode(5);
	ListNode* node4 = new ListNode(4);
	ListNode* node2 = new ListNode(2);
	ListNode* node1 = new ListNode(1);
	node5->next = node4;
	node4->next = node2;
	node2->next = node1;
	Partition p;
	p.partition(node5, 3);

	return 0;
}

