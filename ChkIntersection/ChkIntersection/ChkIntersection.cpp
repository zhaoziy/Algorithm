// ChkIntersection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class ChkIntersection {
public:
	bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) {
		// write code here
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

	ChkIntersection C;
	C.chkInter(NODE1, 2);
	return 0;
	return 0;
}

