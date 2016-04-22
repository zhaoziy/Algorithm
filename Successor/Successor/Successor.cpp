// Successor.cpp : 定义控制台应用程序的入口点。
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

class Successor {
public:
	int findSucc(TreeNode* root, int p) {
		// write code here
		int ret = -1, mode = 0;
		traverse(root, p, ret, mode);
		return ret;
	}

	int traverse(TreeNode *root, int p, int &ret, int &mode)
	{
		if (root == NULL)
			return 0;
		int left = 0;
		int right = 0;
		if (root->left != NULL)
			left = traverse(root->left, p, ret, mode);
		if (left == -1)
			return -1;
		if (mode == 0)
		{
			if (root->val == p)
			{
				mode = 1;
			}
		}
		else
		{
			ret = root->val;
			return -1;
		}
		if (root->right != NULL)
			right = traverse(root->right, p, ret, mode);
		if (right == -1)
			return -1;
		return 0;
	}
};

int main()
{
	return 0;
}

