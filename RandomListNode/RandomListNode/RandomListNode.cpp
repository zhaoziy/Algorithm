// RandomListNode.cpp : �������̨Ӧ�ó������ڵ㡣
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

	}
};

int main()
{
	return 0;
}

