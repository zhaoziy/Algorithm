// Partition.cpp : �������̨Ӧ�ó������ڵ㡣
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
		ListNode* cur = pHead;
		ListNode* NEXT = cur->next;
		if (cur->val < x) {
			NodeX->next = cur->next;
			cur->next = Nodex;
		}
		while (NEXT != NULL) {
			if (NEXT->val < x) {
				NodeX->next = NEXT->next;
				NEXT->next = Nodex;
			}

		}
	}
};

int main()
{
	return 0;
}

