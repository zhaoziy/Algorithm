// FindKthToTail.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		int count = 0;
//		ListNode* Curent = pListHead;
//		while(Curent !=NULL)
//		{
//			count++;
//			Curent = Curent->next;
//		}
//
//		int num = count - k + 1;
//		int i = 1;
//		Curent = pListHead;
//		while (Curent != NULL)
//		{
//			if (i == num)
//			{
//				return Curent;
//			}
//			else
//			{
//				i++;
//				Curent = Curent->next;
//			}
//		}
//	}
//};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int count = 0;
		ListNode* head = pListHead;
		ListNode* tail = pListHead;
		int i = 0;
		while (tail != NULL)
		{
			if (i < k)
			{
				i++;
				tail = tail->next;
			}
			else
			{
				head = head->next;
				tail = tail->next;
			}
		}
		if (i < k)
		{
			return NULL;
		}
		else
		{
			return head;
		}
	}
};

int main()
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	Solution so;
	ListNode *result = NULL;
	result = so.FindKthToTail(&node1, 5);
	return 0;
}

