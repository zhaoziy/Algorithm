// isSymmetrical.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		return Symmetrical(pRoot->left, pRoot->right);
	}

	bool Symmetrical(TreeNode* node1, TreeNode* node2)
	{
		if (node1 == NULL && node2 != NULL)
			return false;
		if (node1 != NULL && node2 == NULL)
			return false;
		if (node1 == NULL && node2 == NULL)
			return true;
		if (node1->val != node2->val)
			return false;
		return Symmetrical(node1->left, node2->right) && Symmetrical(node1->right, node2->left);
	}
};

int main()
{
	return 0;
}

