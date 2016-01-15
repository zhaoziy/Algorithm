// KInverse.cpp : �������̨Ӧ�ó������ڵ㡣
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
//		// ͷ����ǰһ�����
//		ListNode *resHead = new ListNode(-1);
//		resHead->next = head;
//
//		// ���� �Ƿ�k�����
//		int cnt = 0;
//		ListNode *curNode = head;
//		ListNode *tailNode = resHead;
//
//		while (curNode)
//		{
//			cnt++;
//			if (cnt == k)
//			{
//				// �����k��������һ����� ���ڽ���k����������������һ��k������ͷ
//				ListNode *nextKHead = curNode->next;
//
//				curNode->next = NULL;
//				tailNode = reverseList(tailNode->next, tailNode);
//
//				// ������β��� �� ��һ�����ͷ��������
//				tailNode->next = nextKHead;
//
//				// ��һ����������� ��ʼ��һ������
//				curNode = nextKHead;
//				// ��������λ
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

