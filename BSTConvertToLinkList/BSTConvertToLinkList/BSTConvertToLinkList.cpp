// BSTConvertToLinkList.cpp : 定义控制台应用程序的入口点。
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree)
			return NULL;
		TreeNode* pre = pRootOfTree;
		while (pre->left!=NULL)
		{
			pre = pre->left;
		}
		TreeNode* ret = pre;
		traverse(pRootOfTree, &pre);
		return ret;
	}

	void  traverse(TreeNode* node, TreeNode **pre)
	{
		if(node->left)
			traverse(node->left, pre);
		if (*pre != node)
		{
			(*pre)->right = node;
			node->left = *pre;
			*pre = node;
		}
		if (node->right)
			traverse(node->right, pre);
	}
};

int main()
{
	TreeNode* Node1 = new TreeNode(1);
	TreeNode* Node2 = new TreeNode(2);
	TreeNode* Node3 = new TreeNode(3);
	TreeNode* Node4 = new TreeNode(4);
	TreeNode* Node5 = new TreeNode(5);
	TreeNode* Node6 = new TreeNode(6);
	TreeNode* Node7 = new TreeNode(7);
	Node4->left = Node2;
	Node4->right = Node6;
	Node2->left = Node1;
	Node2->right = Node3;
	Node6->left = Node5;
	Node6->right = Node7;
	Solution s;
	s.Convert(Node4);
	return 0;
}

