// RandomListNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

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
		RandomListNode *pCur = pHead;
		RandomListNode *pCurNext = pCur->next;
		while (pCur != NULL)
		{
			RandomListNode *NODE = new RandomListNode(pCur->label);
			pCur->next = NODE;
			NODE->next = pCurNext;
			pCur = pCurNext;
			pCurNext = (pCurNext != NULL) ? (pCurNext->next) : (NULL);
		}

		pCur = pHead;
		pCurNext = pCur->next;
		while (pCur != NULL)
		{
			pCurNext->random = (pCur->random != NULL) ? (pCur->random->next) : (NULL);
			pCur = pCur->next->next;
			pCurNext = (pCur != NULL) ? (pCurNext->next->next) : (NULL);
		}

		pCur = pHead;
		pCurNext = pCur->next;
		RandomListNode *pRet = pCur->next;
		while (pCur != NULL)
		{
			pCur->next = pCur->next->next;
			pCur = pCur->next;

			pCurNext->next = (pCurNext->next != NULL) ? (pCurNext->next->next) : (NULL);
			pCurNext = (pCurNext->next != NULL) ? (pCurNext->next) : (NULL);
		}
		return pRet;
	}
};

int main()
{
	RandomListNode *NODE1 = new RandomListNode(1);
	RandomListNode *NODE2 = new RandomListNode(2);
	RandomListNode *NODE3 = new RandomListNode(3);
	RandomListNode *NODE4 = new RandomListNode(4);
	RandomListNode *NODE5 = new RandomListNode(5);
	RandomListNode *NODE6 = new RandomListNode(6);
	RandomListNode *NODE7 = new RandomListNode(7);
	RandomListNode *NODE8 = new RandomListNode(8);

	NODE1->next = NODE2;
	NODE2->next = NODE3;
	NODE3->next = NODE4;
	NODE4->next = NODE5;
	NODE5->next = NODE6;
	NODE6->next = NODE7;
	NODE7->next = NODE8;

	NODE1->random = NODE8;
	NODE2->random = NODE1;
	NODE3->random = NODE2;
	NODE4->random = NODE3;
	NODE5->random = NODE4;
	NODE6->random = NODE5;
	NODE7->random = NODE6;
	NODE8->random = NODE7;

	Solution C;
	C.Clone(NODE1);
	return 0;
}

