// RandomListNodeClone.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode* cur = pHead;
		while (cur != NULL)
		{
			RandomListNode* newNode = new RandomListNode(cur->label);
			newNode->next = cur->next;
			cur->next = newNode;
			cur = cur->next->next;
		}
		cur = pHead;
		while (cur != NULL)
		{
			if (cur->random != NULL)
			{
				cur->next->random = cur->random->next;
			}
			else
			{
				cur->next->random = NULL;
			}
			cur = cur->next->next;
		}
		RandomListNode* ret = pHead->next;
		cur = pHead;
		RandomListNode* move = cur->next;
		while (move != NULL)
		{
			cur->next = cur->next->next;
			cur = move;
			move = move->next;
		}
		return ret;
	}
};

int main()
{
	RandomListNode* Node1 = new RandomListNode(1);
	RandomListNode* Node2 = new RandomListNode(2);
	RandomListNode* Node3 = new RandomListNode(3);
	RandomListNode* Node4 = new RandomListNode(4);
	RandomListNode* Node5 = new RandomListNode(5);
	RandomListNode* Node6 = new RandomListNode(6);
	RandomListNode* Node7 = new RandomListNode(7);
	Node1->next = Node2;
	/*Node2->next = Node3;
	Node3->next = Node4;
	Node4->next = Node5;
	Node5->next = Node6;
	Node6->next = Node7;*/
	Node1->random = Node1;
	/*Node2->random = Node4;
	Node3->random = Node5;
	Node4->random = Node6;
	Node5->random = Node7;
	Node6->random = Node1;
	Node7->random = Node2;*/
	Solution s;
	s.Clone(NULL);
	return 0;
}

