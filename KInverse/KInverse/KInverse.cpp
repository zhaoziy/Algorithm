// KInverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class KInverse {
public:
	ListNode *reverseList(ListNode *head, ListNode *tail)
	{
		ListNode *res = head;  //设置头结点（包含需要逆序的头结点的前一个结点）
		ListNode *ret = head->next; //设置需要返回的结点（因为返回的是尾结点，逆序前就是头结点）
		ListNode *cur1 = res->next; //工作结点1
		ListNode *cur2 = cur1->next;//工作结点2
		ListNode *cur3 = cur2->next;//工作结点3
		ret->next = NULL;
		do
		{
			cur2->next = cur1;
			cur1 = cur2;
			cur2 = cur3;
			if (cur3 != NULL)
			{
				cur3 = cur3->next;
			}
		} while (cur2 != NULL);
		res->next = cur1;
		return ret;
	}

	ListNode* inverse(ListNode* head, int k) {
		// write code here
		if (k == 1)
			return head;

		ListNode *front = new ListNode(-1);  //在头结点前建立结点，防止逆序后找不到头结点
		front->next = head;  //将头结点连接到新节点上，此结点为新的头结点，并且不变
		ListNode *current = head; //工作节点
		ListNode *tailNext = NULL;  //每节的尾结点后的一个结点，因为逆序后尾结点会变化，先进行记录
		ListNode *tail = front; //尾结点（变换后为尾结点，逆序前为头结点）
		int i = 1;
		while (current != NULL)
		{
			if (i++ % k == 0)  //每k个进入一次逆序过程
			{
				tailNext = current->next;  //当前工作结点的下一个节点就是尾结点下一个
				current->next = NULL;  //将本节截断
				tail = reverseList(tail, current); //tail是转换前的头结点，转换后函数返回尾结点，tail编程尾结点
				tail->next = tailNext; //将逆序后的尾结点和之后的结点连接
				current = tail;  //将逆序后的尾结点设置为目前的工作结点，之后后移就到下一阶段了
			}
			current = current->next;
		}
		return front->next;
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

	KInverse C;
	C.inverse(NODE1, 2);
	return 0;
}

