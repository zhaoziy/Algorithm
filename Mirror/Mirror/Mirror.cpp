// Mirror.cpp : 定义控制台应用程序的入口点。
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
	void Mirror(TreeNode *pRoot) 
	{
		if (pRoot == NULL)
			return;
		swap(pRoot);
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}

	void swap(TreeNode *pRoot)
	{
		TreeNode *node_temp = NULL;
		node_temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = node_temp;
	}
};


int main()
{
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);
	TreeNode node8(8);
	TreeNode node9(9);
	TreeNode node10(10);
	TreeNode node11(11);

	node8.left = &node6;
	node8.right = &node10;

	node10.left = &node9;
	node10.right = &node11;

	node6.left = &node5;
	node6.right = &node7;

	Solution so;
	so.Mirror(&node8);
	return 0;
}

