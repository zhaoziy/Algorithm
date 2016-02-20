// GetNext.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	}
};

class Solution {
	vector<TreeLinkNode *> ret;
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode *head = pNode;
		while (head->next != NULL)
			head = head->next;
		Next(head);
		for (int i = 0; i < (int)ret.size(); ++i)
		{
			if (pNode == ret[i] && i != (int)ret.size() -1)
				return ret[i + 1];
		}
		return NULL;
	}

	void Next(TreeLinkNode* pNode)
	{
		if (pNode->left)
			Next(pNode->left);
		ret.push_back(pNode);
		if (pNode->right)
			Next(pNode->right);
	}
};

int main()
{
	TreeLinkNode *NODE1 = new TreeLinkNode(1);
	TreeLinkNode *NODE2 = new TreeLinkNode(2);
	TreeLinkNode *NODE3 = new TreeLinkNode(3);
	TreeLinkNode *NODE4 = new TreeLinkNode(4);
	TreeLinkNode *NODE5 = new TreeLinkNode(5);

	NODE1->left = NODE2;
	NODE1->right = NODE3;
	NODE3->left = NODE4;
	NODE3->right = NODE5;
	Solution s;
	s.GetNext(NODE1);
	return 0;
}

