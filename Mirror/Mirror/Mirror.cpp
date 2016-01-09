// Mirror.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//class Solution {
//public:
//	void Mirror(TreeNode *pRoot) 
//	{
//		if (pRoot == NULL)
//			return;
//		swap(pRoot);
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//	}
//
//	void swap(TreeNode *pRoot)
//	{
//		TreeNode *node_temp = NULL;
//		node_temp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = node_temp;
//	}
//};

class Solution {
public:
	void Mirror(TreeNode *pRoot)
	{
		if (pRoot == NULL)
			return;
		TreeNode *Current = NULL;
		stack<TreeNode*> stackNum;
		Current = pRoot;
		stackNum.push(Current);

		while (!stackNum.empty())
		{
			swap(stackNum.top());
			Current = stackNum.top();
			stackNum.pop();

			if (Current->right != NULL)
			{
				stackNum.push(Current->right);
			}
			if (Current->left != NULL)
			{
				stackNum.push(Current->left);
			}
		}
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

