// LongestDistance.cpp : 定义控制台应用程序的入口点。
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

class LongestDistance {
public:
	void get(TreeNode *rt, int *mx, int &ret) 
	{
		int lmx = 0, rmx = 0;
		if (rt->left) 
		{
			get(rt->left, mx, ret); 
			lmx = mx[rt->left->val];
		}
		if (rt->right)
		{
			get(rt->right, mx, ret); 
			rmx = mx[rt->right->val];
		}
		mx[rt->val] = max(lmx, rmx) + 1;
		if (lmx + rmx + 1 > ret) 
			ret = lmx + rmx + 1;
	}

	int findLongest(TreeNode* root) {
		// write code here
		int ret = 0;
		int mx[550];
		get(root, mx, ret);
		return ret;
	}

	int max(int a, int b)
	{
		return (a > b) ? (a) : (b);
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
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);

	node3->left = node2;
	node3->right = node6;

	node2->left = node1;

	node6->left = node5;
	node6->right = node9;

	node5->left = node4;

	node9->left = node8;
	node8->left = node7;

	LongestDistance c;
	int a = c.findLongest(node3);
	return 0;
}

