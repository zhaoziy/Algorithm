// CheckIntersect.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class CheckIntersect {
public:
	bool chkIntersect(ListNode* headA, ListNode* headB) {
		// write code here
		int i = 0;
		int j = 0;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while (pA != NULL)
		{
			pA = pA->next;
			i++;
		}
		while (pB != NULL)
		{
			pB = pB->next;
			j++;
		}
		if (i > j)
		{
			pA = headA;
			pB = headB;
			int m = i - j;
			while (m--)
			{
				pA = pA->next;
			}
			while (pA != NULL)
			{
				if (pA == pB)
				{
					return true;
				}
				pA = pA->next;
				pB = pB->next;
			}
			return false;
		}
		else
		{
			pA = headA;
			pB = headB;
			int m = j - i;
			if (m > 0)
			{
				while (m--)
				{
					pB = pB->next;
				}
			}
			while (pB != NULL)
			{
				if (pA == pB)
				{
					return true;
				}
				pA = pA->next;
				pB = pB->next;
			}
			return false;
		}
	}
};

int main()
{
	ListNode *NODE1 = new ListNode(1);
	ListNode *NODE2 = new ListNode(2);
	ListNode *NODE3 = new ListNode(3);
	ListNode *NODE4 = new ListNode(4);

	ListNode *NODE5 = new ListNode(5);
	ListNode *NODE6 = new ListNode(6);

	NODE1->next = NODE2;
	NODE2->next = NODE3;
	NODE3->next = NODE4;

	NODE5->next = NODE6;
	NODE6->next = NODE2;

	CheckIntersect C;
	C.chkIntersect(NODE1, NODE5);
	return 0;
}

