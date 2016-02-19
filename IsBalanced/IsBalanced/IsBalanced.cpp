// IsBalanced.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL || BalancedLevel(pRoot) != -1)
			return true;
		else
			return false;
	}

	int BalancedLevel(TreeNode* pRoot) {
		int LeftNum = 0, RightNum = 0;
		if (pRoot->left)
			LeftNum = BalancedLevel(pRoot->left);
		if (pRoot->right)
			RightNum = BalancedLevel(pRoot->right);
		if (LeftNum == -1 || RightNum == -1 || LeftNum - RightNum < -1 || LeftNum - RightNum > 1)
			return -1;
		else
			return (LeftNum - RightNum > 0) ? (LeftNum + 1) : (RightNum + 1);
	}
};

int main()
{
	TreeNode Node0(0);
	TreeNode Node1(1);
	TreeNode Node2(2);
	TreeNode Node3(3);
	TreeNode Node4(4);
	TreeNode Node5(5);
	TreeNode Node6(6);
	TreeNode Node7(7);
	Node0.left = &Node1;
	Node0.right = &Node2;
	Node1.left = &Node3;
	Node1.right = &Node4;
	Node2.left = &Node5;
	Node2.right = &Node6;
	Node3.left = &Node7;

	Solution treePrinter;
	bool Result = treePrinter.IsBalanced_Solution(&Node0);
    return 0;
}

