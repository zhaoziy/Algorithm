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
	int findLongest(TreeNode* root) {
		// write code here
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

