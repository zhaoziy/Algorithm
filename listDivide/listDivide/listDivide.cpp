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
		ListNode *pre = new ListNode(0);
		ListNode *mid = new ListNode(0);
		ListNode *rear = new ListNode(0);
		ListNode *pre_cu = pre;
		ListNode *mid_cu = mid;
		ListNode *rear_cu = rear;
		ListNode *current = head;
		while (current != NULL)
		{
			if (current->val < val)
			{
				pre_cu->next = current;
				pre_cu = pre_cu->next;
				current = current->next;
				pre_cu->next = NULL;
			}
			else if(current->val > val)
			{
				rear_cu->next = current;
				rear_cu = rear_cu->next;
				current = current->next;
				rear_cu->next = NULL;
			}
			else
			{
				mid_cu->next = current;
				mid_cu = mid_cu->next;
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

