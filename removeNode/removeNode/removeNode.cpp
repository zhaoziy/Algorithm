// removeNode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Remove {
public:
	bool removeNode(ListNode* pNode) {
		// write code here
		if (pNode == NULL)
			return false;
		if (pNode->next == NULL)
			return false;
		
		pNode->val = pNode->next->val;
		pNode = pNode->next;
		return true;
	}
};

int main()
{
	return 0;
}

