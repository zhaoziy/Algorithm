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
		ListNode *res = head;  //����ͷ��㣨������Ҫ�����ͷ����ǰһ����㣩
		ListNode *ret = head->next; //������Ҫ���صĽ�㣨��Ϊ���ص���β��㣬����ǰ����ͷ��㣩
		ListNode *cur1 = res->next; //�������1
		ListNode *cur2 = cur1->next;//�������2
		ListNode *cur3 = cur2->next;//�������3
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

		ListNode *front = new ListNode(-1);  //��ͷ���ǰ������㣬��ֹ������Ҳ���ͷ���
		front->next = head;  //��ͷ������ӵ��½ڵ��ϣ��˽��Ϊ�µ�ͷ��㣬���Ҳ���
		ListNode *current = head; //�����ڵ�
		ListNode *tailNext = NULL;  //ÿ�ڵ�β�����һ����㣬��Ϊ�����β����仯���Ƚ��м�¼
		ListNode *tail = front; //β��㣨�任��Ϊβ��㣬����ǰΪͷ��㣩
		int i = 1;
		while (current != NULL)
		{
			if (i++ % k == 0)  //ÿk������һ���������
			{
				tailNext = current->next;  //��ǰ����������һ���ڵ����β�����һ��
				current->next = NULL;  //�����ڽض�
				tail = reverseList(tail, current); //tail��ת��ǰ��ͷ��㣬ת����������β��㣬tail���β���
				tail->next = tailNext; //��������β����֮��Ľ������
				current = tail;  //��������β�������ΪĿǰ�Ĺ�����㣬֮����ƾ͵���һ�׶���
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

