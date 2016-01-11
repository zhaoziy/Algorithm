// findCommonParts.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Common {
public:
	vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
		// write code here
		ListNode* A_cur = headA;
		ListNode* B_cur = headB;
		vector<int> result;
		while (A_cur != NULL && B_cur != NULL)
		{
			if (A_cur->val < B_cur->val)
			{
				A_cur = A_cur->next;
			}
			else if (A_cur->val > B_cur->val)
			{
				B_cur = B_cur->next;
			}
			else
			{
				result.push_back(A_cur->val);
				A_cur = A_cur->next;
				B_cur = B_cur->next;
			}
		}
		return result;
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

	ListNode *NODE8 = new ListNode(2);
	ListNode *NODE9 = new ListNode(4);
	ListNode *NODE10 = new ListNode(6);
	ListNode *NODE11 = new ListNode(8);
	ListNode *NODE12 = new ListNode(10);

	NODE1->next = NODE2;
	NODE2->next = NODE3;
	NODE3->next = NODE4;
	NODE4->next = NODE5;
	NODE5->next = NODE6;
	NODE6->next = NODE7;

	NODE8->next = NODE9;
	NODE9->next = NODE10;
	NODE10->next = NODE11;
	NODE11->next = NODE12;

	Common C;
	C.findCommonParts(NODE1, NODE8);
	return 0;
}

