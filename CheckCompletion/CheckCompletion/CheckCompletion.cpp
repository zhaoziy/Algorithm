// CheckCompletion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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

class CheckCompletion {
public:
	bool chk(TreeNode* root) {
		// write code here
		deque<TreeNode*> deq;
		bool tail = false;
		TreeNode *cur = NULL;
		deq.push_back(root);
		while (!deq.empty())
		{
			cur = deq.front();
			if (cur->right != NULL && cur->left == NULL)
			{
				return false;
			}
			if (cur->right == NULL && cur->left == NULL)
			{
				tail = true;
			}
			if (tail == true && (cur->right != NULL || cur->left != NULL))
			{
				return false;
			}
			deq.pop_front();
			if (cur->left != NULL)
			{
				deq.push_back(cur->left);
			}
			if (cur->right != NULL)
			{
				deq.push_back(cur->right);
			}
		}
		return true;
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

	node1->left = node2;
	node1->right = node3;

	node2->left = node4;
	node2->right = node5;

	node3->left = node6;
	node3->right = node7;

	node4->left = node8;
	node4->right = node9;

	CheckCompletion c;
	int a = c.chk(node1);
	return 0;
}

