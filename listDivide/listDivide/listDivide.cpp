// listDivide.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
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
		ListNode *rear = NULL;
		ListNode *pre_cu = NULL;
		ListNode *rear_cu = NULL;
		ListNode *current = head;
		while (current != NULL)
		{
			if (current->val <= val)
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
			else
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
		}

		vector<ListNode*> re;
		if (pre != NULL)
		{
			re.push_back(pre);
			re.push_back(pre_cu);
		}
		if (rear != NULL)
		{
			re.push_back(rear);
			re.push_back(rear_cu);
		}

		ListNode* result = re[0];
		if (re.size() == 4)
		{
			re[1]->next = re[2];
		}
		
		return result;
	}
};

int main()
{
	ListNode node1(1620);
	ListNode node2(1134);
	ListNode node3(861);
	ListNode node4(563);
	ListNode node5(1);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	Divide d;
	ListNode *result;
	result = d.listDivide(&node1,1134);
	return 0;
}

