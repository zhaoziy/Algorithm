// Palindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
	ListNode *ReverseList(ListNode *head, ListNode *tail)
	{

	}

	bool isPalindrome(ListNode* pHead) 
	{
		// write code here
		if (pHead == NULL || pHead->next == NULL)
		{
			return true;
		}
		ListNode *curFront = pHead;
		ListNode *fast = pHead;
		ListNode *slow = pHead;
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ReverseList(slow, fast);
		ListNode *curRear= fast;
		while (curRear != slow)
		{
			if (curRear->val == curFront->val)
			{
				curRear = curRear->next;
				curFront = curFront->next;
			}
			else
			{
				return false;
			}
		}
		ReverseList(fast, slow);
		return true;
	}
};

int main()
{
	ListNode *NODE1 = new ListNode(1);
	ListNode *NODE2 = new ListNode(2);
	ListNode *NODE3 = new ListNode(3);
	ListNode *NODE4 = new ListNode(4);
	ListNode *NODE5 = new ListNode(4);
	ListNode *NODE6 = new ListNode(3);
	ListNode *NODE7 = new ListNode(2);
	//ListNode *NODE8 = new ListNode(1);

	NODE1->next = NODE2;
	NODE2->next = NODE3;
	NODE3->next = NODE4;
	NODE4->next = NODE5;
	NODE5->next = NODE6;
	NODE6->next = NODE7;
	//NODE7->next = NODE8;

	Palindrome C;
	C.isPalindrome(NODE1);
	return 0;
}

