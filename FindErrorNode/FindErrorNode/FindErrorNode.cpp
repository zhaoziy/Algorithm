// FindErrorNode.cpp : 定义控制台应用程序的入口点。
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

class FindErrorNode {
public:
	vector<int> findError(TreeNode* root) {
		// write code here
		vector<int> node;
		vector<int> res;
		int max = 0;
		int min = 0;
		bool first = false;
		traversal(root, node);
		for (int i = 0; i < (int)node.size() - 1; ++i)
		{
			if (first == false && node[i + 1] < node[i])
			{
				max = node[i];
				min = node[i + 1];
				first = true;
				continue;
			}

			if (first == true && node[i + 1] < node[i])
			{
				min = node[i + 1];
				break;
			}
		}
		res.push_back(min);
		res.push_back(max);
		return res;
	}

	void traversal(TreeNode* root, vector<int> &node)
	{
		if (root == NULL)
			return;
		traversal(root->left, node);
		node.push_back(root->val);
		traversal(root->right, node);
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

	node3->left = node5;
	node3->right = node6;

	node5->left = node1;

	node6->left = node2;
	node6->right = node9;

	node2->left = node4;

	node9->left = node8;
	node8->left = node7;

	FindErrorNode c;
	vector<int> a = c.findError(node3);
	return 0;
}

