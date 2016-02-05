// PrintFromTopToBottom.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
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
	vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		deque<TreeNode *> de;
		de.push_back(root);
		while (!de.empty())
		{
			TreeNode *cur = de.front();
			ret.push_back(cur->val);
			if (cur->left != NULL)
			{
				de.push_back(cur->left);
			}
			if (cur->right != NULL)
			{
				de.push_back(cur->right);
			}
			de.pop_front();
		}
		return ret;
	}
};

int main()
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	Solution s;
	s.PrintFromTopToBottom(node1);
	return 0;
}

