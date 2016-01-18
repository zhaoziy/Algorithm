// CountNodes.cpp : 定义控制台应用程序的入口点。
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

class CountNodes {
public:
	int count(TreeNode* root) {
		// write code here
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		int Icount = 0;
		TreeNode *leftNode = root;
		while (leftNode != NULL)
		{
			Icount++;
			leftNode = leftNode->left;
		}
		int i = 1;
		leftNode = root;
		while (leftNode != NULL && leftNode->left != NULL)
		{
			leftNode = (i++ == 1) ? (leftNode->right) : (leftNode->left);
		}
		return (i == Icount) ? (pow(2, i - 1) - 1 + count(root->right) + 1) : (pow(2, i - 1) - 1 + count(root->left) + 1);
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
	node2->right = node5;

	node3->left = node6;
	/*node3->right = node7;

	node4->left = node8;
	node4->right = node9;*/

	CountNodes c;
	int a = c.count(node1);
	return 0;
}

