// ListMerge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *Result_Temp = new ListNode(0);
		ListNode *Result_Head = Result_Temp;
		while (pHead1 != NULL && pHead2 != NULL)
		{
			ListNode *Temp = new ListNode(0);
			Result_Temp->next = Temp;
			if (pHead1->val < pHead2->val)
			{
				Temp->val = pHead1->val;
				pHead1 = pHead1->next;
			}
			else
			{
				Temp->val = pHead2->val;
				pHead2 = pHead2->next;
			}
			Result_Temp->val = Temp->val;
			Result_Temp = Result_Temp->next;
		}
		while (pHead1 != NULL)
		{
			ListNode *Temp = new ListNode(0);
			Result_Temp->next = Temp;
			Temp->val = pHead1->val;
			pHead1 = pHead1->next;
			Result_Temp->val = Temp->val;
			Result_Temp = Result_Temp->next;
		}
		while (pHead2 != NULL)
		{
			ListNode *Temp = new ListNode(0);
			Result_Temp->next = Temp;
			Temp->val = pHead2->val;
			pHead2 = pHead2->next;
			Result_Temp->val = Temp->val;
			Result_Temp = Result_Temp->next;
		}
		Result_Temp = NULL;
		return Result_Head;
	}
};

int main()
{
	ListNode Node1(1);
	ListNode Node2(2);
	ListNode Node3(3); 
	ListNode Node4(4); 
	Node1.next = &Node3;
	Node2.next = &Node4;
	Solution so;
	so.Merge(&Node1, &Node2);
	return 0;
}

