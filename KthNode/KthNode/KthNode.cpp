// KthNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

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
	TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
	{
		if (pRoot == NULL || k == 0)
			return NULL;
		vector<TreeNode*> ret;
		rev(pRoot, ret);
		if (k <= ret.size())
			return ret[k - 1];
		else
			return NULL;
	}

	void rev(TreeNode* pRoot, vector<TreeNode*> &ret)
	{
		if (pRoot->left != NULL)
			rev(pRoot->left, ret);
		ret.push_back(pRoot);
		if (pRoot->right != NULL)
			rev(pRoot->right, ret);
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
	TreeNode* node7 = new TreeNode(7);
	node4->left = node2;
	node4->right = node6;
	node2->left = node1;
	node2->right = node3;
	node6->left = node5;
	node6->right = node7;
	Solution s;
	TreeNode* a = s.KthNode(node4, 0);
	return 0;
}

