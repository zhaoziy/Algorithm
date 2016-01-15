// ClearValue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class ClearValue {
//public:
//	ListNode* clear(ListNode* head, int val) {
//		// write code here
//		ListNode *ret = new ListNode(-1);
//		ret->next = head;
//		ListNode *cur1 = ret;
//		ListNode *cur2 = ret->next;
//		while (cur2 != NULL)
//		{
//			if (cur2->val == val)
//			{
//				ListNode *cur2Next = cur2->next;
//				delete cur2;
//				cur1->next = cur2Next;
//				cur2 = cur2Next;
//			}
//			else
//			{
//				cur1 = cur2;
//				cur2 = cur2->next;
//			}
//		}
//		return ret->next;
//	}
//}; //进行遍历，和val相同的进行删除

class ClearValue {
public:
	ListNode* clear(ListNode* head, int val) {
		// write code here
		ListNode *tail = head;
		ListNode *cur = head;
		while (tail != NULL)
		{
			if (head->val == val)
			{
				head = head->next;
				tail = tail->next;
				cur = cur->next;
			}
			else if(cur == tail)
			{
				tail = tail->next;
			}
			else if(tail->val == val)
			{
				cur->next = tail->next;
				delete tail;
				tail = cur->next;
			}
			else
			{
				tail = tail->next;
				cur = cur->next;
			}
		}
		return head;
	}
}; //进行遍历，构建新的链表

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

	ClearValue C;
	C.clear(NODE1, 2);
	return 0;
}

