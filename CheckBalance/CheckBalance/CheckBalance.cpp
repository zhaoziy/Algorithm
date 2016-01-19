// CheckBalance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class CheckBalance {
public:
	bool check(TreeNode* root) {
		// write code here
		int i = Level(root);
		return (i == -1) ? (false) : (true);
	}

	int Level(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		int LH = 0;
		int RH = 0;
		int LH_temp = 0;
		int RH_temp = 0;
		LH_temp = Level(root->left);
		if (LH_temp != -1)
			LH += LH_temp;
		else
			return -1;

		RH_temp = Level(root->right);
		if (RH_temp != -1)
			RH += RH_temp;
		else
			return -1;

		return (abs(LH - RH) > 1 || LH == -1 || RH == -1) ? (-1) : ((LH > RH) ? (LH + 1) : (RH + 1));
	}
};

int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	/*TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);*/

	node1->left = node2;
	node1->right = node3;

	node2->left = node4;

	node3->right = node5;

	node4->left = node6;

	/*node4->left = node8;
	node4->right = node9;*/

	CheckBalance c;
	int a = c.check(node1);
	return 0;
}

