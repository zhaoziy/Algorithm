// TreeDepth.cpp : 定义控制台应用程序的入口点。
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

class Solution {
	deque<TreeNode*> deq;
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		TreeNode* cur = NULL;
		TreeNode* last = pRoot;
		TreeNode* nlast = pRoot;
		int count = 0;
		deq.push_back(pRoot);
		while (!deq.empty())
		{
			cur = deq.front();
			deq.pop_front();
			if (cur->left != NULL)
			{
				deq.push_back(cur->left);
				nlast = cur->left;
			}
			if (cur->right != NULL)
			{
				deq.push_back(cur->right);
				nlast = cur->right;
			}
			if (cur == last)
			{
				count++;
				last = nlast;
			}
		}
		return count;
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
	int Result = treePrinter.TreeDepth(&Node0);

	return 0;
}

