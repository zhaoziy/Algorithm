// listDivide.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Divide {
public:
	ListNode* listDivide(ListNode* head, int val) {
		// write code here
		ListNode *pre = NULL;
		ListNode *mid = NULL;
		ListNode *rear = NULL;
		ListNode *pre_cu = NULL;
		ListNode *mid_cu = NULL;
		ListNode *rear_cu = NULL;
		ListNode *current = head;
		while (current != NULL)
		{
			if (current->val < val)
			{
				if (pre_cu == NULL)
				{
					pre = current;
					pre_cu = current;
				}
				else
				{
					pre_cu->next = current;
					pre_cu = pre_cu->next;
				}
				current = current->next;
				pre_cu->next = NULL;
			}
			else if(current->val > val)
			{
				if (rear_cu == NULL)
				{
					rear = current;
					rear_cu = current;
				}
				else
				{
					rear_cu->next = current;
					rear_cu = rear_cu->next;
				}
				current = current->next;
				rear_cu->next = NULL;
			}
			else
			{
				if (mid_cu == NULL)
				{
					mid = current;
					mid_cu = current;
				}
				else
				{
					mid_cu->next = current;
					mid_cu = mid_cu->next;
				}
				current = current->next;
				mid_cu->next = NULL;
			}
		}

		
		return pre_cu;
	}
};

int main()
{
	ListNode node1(1);
	ListNode node2(4);
	ListNode node3(2);
	ListNode node4(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	Divide d;
	ListNode *result;
	result = d.listDivide(&node1, 3);
	return 0;
}

