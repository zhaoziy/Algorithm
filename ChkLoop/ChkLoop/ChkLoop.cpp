// ChkLoop.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class ChkLoop {
public:
	int chkLoop(ListNode* head, int adjust) {
		// write code here
		ListNode *pFast = head;
		ListNode *pSlow = head;
		do
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}
		while (pFast != pSlow && pFast != NULL && pFast->next != NULL);

		if (pFast == NULL || pFast->next == NULL)
		{
			return -1;
		}
		else
		{
			pFast = head;
			while (pFast != pSlow)
			{
				pFast = pFast->next;
				pSlow = pSlow->next;
			}
			return pFast->val;
		}
	}
};

int main()
{
	ListNode *NODE1 = new ListNode(1);
	ListNode *NODE2 = new ListNode(2);
	ListNode *NODE3 = new ListNode(3);
	ListNode *NODE4 = new ListNode(4);
	
	NODE1->next = NODE2;
	NODE2->next = NODE3;
	NODE3->next = NODE4;
	NODE4->next = NODE2;

	ChkLoop C;
	C.chkLoop(NODE1, 2);
	return 0;
}

