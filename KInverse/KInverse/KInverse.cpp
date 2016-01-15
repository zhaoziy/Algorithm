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

	}

	ListNode* inverse(ListNode* head, int k) {
		// write code here
		if (k == 1)
			return head;

		ListNode *front = NULL;
		ListNode *current = head;
		ListNode *back = NULL;
		while (current != NULL)
		{
			int i = 0;
			while (i < k)
			{
				if (i++ == 0)
				{
					front = current;
				}
				else
				{
					back = current;
				}
				current = current->next;
			}
			reverseList(front, back)->next = current;
		}
		return head;
	}
};

//class KInverse {
//public:
//	ListNode *reverseList(ListNode *head, ListNode *last_tail)
//	{
//		ListNode *nextNode = head->next;
//		ListNode *res = head;
//
//		while (nextNode)
//		{
//			ListNode *tmp = nextNode->next;
//			nextNode->next = head;
//			head = nextNode;
//			nextNode = tmp;
//		}
//
//		last_tail->next = head;
//
//		return res;
//	}
//
//	ListNode* inverse(ListNode* head, int k) {
//		// 头结点的前一个结点
//		ListNode *resHead = new ListNode(-1);
//		resHead->next = head;
//
//		// 计数 是否到k个结点
//		int cnt = 0;
//		ListNode *curNode = head;
//		ListNode *tailNode = resHead;
//
//		while (curNode)
//		{
//			cnt++;
//			if (cnt == k)
//			{
//				// 保存第k个结点的下一个结点 便于将这k个结点逆序后连接下一个k个结点的头
//				ListNode *nextKHead = curNode->next;
//
//				curNode->next = NULL;
//				tailNode = reverseList(tailNode->next, tailNode);
//
//				// 逆序后的尾结点 与 下一组结点的头链接起来
//				tailNode->next = nextKHead;
//
//				// 这一组结点逆序完成 开始下一组逆序
//				curNode = nextKHead;
//				// 结点计数复位
//				cnt = 0;
//				continue;
//			}
//			curNode = curNode->next;
//		}
//
//		return resHead->next;
//	}
//};

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
	C.inverse(NODE1, 3);
	return 0;
}

