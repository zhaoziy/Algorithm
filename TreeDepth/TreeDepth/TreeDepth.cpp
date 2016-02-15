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
		TreeNode* cur = NULL;
		TreeNode* last = NULL;
		deq.push_back(pRoot);
		while (deq.empty() != 0)
		{
			cur = deq.front();
			if (cur->left != NULL)
				deq.push_back(cur->left);
			if (cur->right != NULL)
				deq.push_front(cur->right);
		}
	}
};

int main()
{
	return 0;
}

