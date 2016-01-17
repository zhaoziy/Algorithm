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
		ListNode *enterCir1 = findNode(head1);
		ListNode *enterCir2 = findNode(head2);
		ListNode *cur1 = head1;
		ListNode *cur2 = head2;
		if ((enterCir1 != NULL && enterCir2 == NULL) || (enterCir2 != NULL && enterCir1 == NULL))
		{
			return false;
		}	

		int i = 0;
		while (cur1 != enterCir1)
		{
			cur1 = cur1->next;
			i++;
		}

		int j = 0;
		while (cur2 != enterCir2)
		{
			cur2 = cur2->next;
			j++;
		}

		cur1 = head1;
		cur2 = head2;
		if (i > j)
		{
			int m = i - j;
			while (m--)
			{
				cur1 = cur1->next;
			}
		}
		else if(j > i)
		{
			int m = j - i;
			while (m--)
			{
				cur2 = cur2->next;
			}
		}

		while (cur1 != enterCir1)
		{
			if (cur1 == cur2)
			{
				return true;
			}
			else
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}

		do 
		{
			if (cur1 == enterCir2)
			{
				return true;
			}
			else
			{
				cur1 = cur1->next;
			}
		} while (cur1 != enterCir1);
		return false;
	}

	ListNode *findNode(ListNode* head)
	{
		ListNode *pfast = head;
		ListNode *pslow = head;
		do
		{
			pslow = pslow->next;
			pfast = pfast->next->next;
		} while (pfast != pslow);
		pfast = head;
		while (pfast != pslow)
		{
			pslow = pslow->next;
			pfast = pfast->next;
		}
		return pslow;
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

	NODE1->next = NODE2;
	NODE2->next = NODE3;
	NODE3->next = NODE4;
	NODE4->next = NODE2;

	NODE5->next = NODE6;
	NODE6->next = NODE3;
	
	ChkIntersection C;
	C.chkInter(NODE1, NODE5, 1, 2);
	return 0;
	return 0;
}

