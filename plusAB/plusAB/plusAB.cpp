// plusAB.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Plus {
public:
	ListNode* plusAB(ListNode* a, ListNode* b) {
		// write code here
		ListNode* cura = a;
		ListNode* curb = b;
		ListNode* head = new ListNode(0);
		ListNode* cur = head;
		while (cura != NULL && curb != NULL) {
			ListNode* temp = new ListNode(1);
			temp->val = cura->val + curb->val;
			cur->next = temp;
			cur = cur->next;
			cura = cura->next;
			curb = curb->next;
		}
		while (cura != NULL) {
			ListNode* temp = new ListNode(1);
			temp->val = cura->val;
			cur->next = temp;
			cur = cur->next;
			cura = cura->next;
		}
		while (curb != NULL) {
			ListNode* temp = new ListNode(1);
			temp->val = curb->val;
			cur->next = temp;
			cur = cur->next;
			curb = curb->next;
		}
		cur = head;
		while (cur != NULL) {
			if (cur->val > 9) {
				cur->val -= 10;
				if (cur->next != NULL)
					cur->next->val += 1;
				else {
					ListNode* temp = new ListNode(1);
					cur->next = temp;
				}
			}
			cur = cur->next;
		}
		return head->next;
	}
};

int main()
{
	ListNode* NODE1 = new ListNode(1);
	ListNode* NODE2 = new ListNode(2);
	ListNode* NODE3 = new ListNode(3);
	NODE1->next = NODE2;
	NODE2->next = NODE3;

	ListNode* NODE4 = new ListNode(4);
	ListNode* NODE5 = new ListNode(5);
	ListNode* NODE6 = new ListNode(6);
	NODE4->next = NODE5;
	NODE5->next = NODE6;

	Plus a;
	a.plusAB(NODE1, NODE4);
	return 0;
}

