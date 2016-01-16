// ReverseList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next ==NULL)
		{
			return pHead;
		}
		ListNode *cur1 = pHead;
		ListNode *cur2 = cur1->next;
		ListNode *cur3 = cur2->next;
		cur1->next = NULL;
		while (cur2 != NULL)
		{
			cur2->next = cur1;
			cur1 = cur2;
			cur2 = cur3;
			if (cur3 != NULL)
			{
				cur3 = cur3->next;
			}
		}
		return cur1;
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

	Solution C;
	C.ReverseList(NODE1);
	return 0;
}

