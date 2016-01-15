// KInverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class KInverse {
public:
	ListNode* inverse(ListNode* head, int k) {
		// write code here
		if (k == 1)
		{
			return head;
		}
		ListNode *front = NULL;
		ListNode *current = head;
		ListNode *rear = NULL;
		while (current != NULL)
		{
			int i = 0;
			while (i < k && current != NULL)
			{
				if (i == 0)
				{
					front = current;
					current = current->next;
				}
				else if (i == k - 1)
				{
					rear = current;
					current = current->next;
				}
				else
				{
					current = current->next;
				}
				i++;
			}

			ListNode *cur1 = front;
			ListNode *cur2 = cur1->next;
			ListNode *cur3 = cur2->next;

			if (i == k)
			{
				ListNode *cur1 = front;
				ListNode *cur2 = cur1->next;
				ListNode *cur3 = cur2->next;
				int j = 0;
				while (j < i)
				{
					cur2->next = cur1;
					
				}
			}
		}
		return head;
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
	ListNode *NODE7 = new ListNode(7);
	ListNode *NODE8 = new ListNode(8);

	NODE1->next = NODE2;
	NODE2->next = NODE3;
	NODE3->next = NODE4;
	NODE4->next = NODE5;
	NODE5->next = NODE6;
	NODE6->next = NODE7;
	NODE7->next = NODE8;

	KInverse C;
	C.inverse(NODE1, 3);
	return 0;
}

