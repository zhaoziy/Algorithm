// PrintZ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
#include <stack>
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<int> temp;
		vector<vector<int>> ret;
		if (!pRoot)
			return ret;
		stack<TreeNode*> LeftToRight;
		stack<TreeNode*> RightToLeft;
		int level = 1;
		LeftToRight.push(pRoot);
		while (!LeftToRight.empty() || !RightToLeft.empty())
		{
			if (level % 2 == 1)
			{
				TreeNode *cur = LeftToRight.top();
				LeftToRight.pop();
				if (cur->left)
					RightToLeft.push(cur->left);
				if (cur->right)
					RightToLeft.push(cur->right);
				temp.push_back(cur->val);
				if (LeftToRight.empty())
				{
					level++;
					ret.push_back(temp);
					temp.clear();
				}
			}
			else
			{
				TreeNode *cur = RightToLeft.top();
				RightToLeft.pop();
				if (cur->right)
					LeftToRight.push(cur->right);
				if (cur->left)
					LeftToRight.push(cur->left);
				temp.push_back(cur->val);
				if (RightToLeft.empty())
				{
					level++;
					ret.push_back(temp);
					temp.clear();
				}
			}
		}
		return ret;
 	}
};

int main()
{
	TreeNode *NODE8 = new TreeNode(8);
	TreeNode *NODE4 = new TreeNode(4);
	TreeNode *NODE12 = new TreeNode(12);
	TreeNode *NODE2 = new TreeNode(2);
	TreeNode *NODE6 = new TreeNode(6);
	TreeNode *NODE10 = new TreeNode(10);
	TreeNode *NODE14 = new TreeNode(14);
	TreeNode *NODE1 = new TreeNode(1);
	TreeNode *NODE3 = new TreeNode(3);
	TreeNode *NODE5 = new TreeNode(5);
	TreeNode *NODE7 = new TreeNode(7);
	TreeNode *NODE9 = new TreeNode(9);
	TreeNode *NODE11 = new TreeNode(11);
	TreeNode *NODE13 = new TreeNode(13);
	TreeNode *NODE15 = new TreeNode(15);

	NODE8->left = NODE4;
	NODE8->right = NODE12;
	NODE4->left = NODE2;
	NODE4->right = NODE6;
	NODE12->left = NODE10;
	NODE12->right = NODE14;
	NODE2->left = NODE1;
	NODE2->right = NODE3;
	NODE6->left = NODE5;
	NODE6->right = NODE7;
	NODE10->left = NODE9;
	NODE10->right = NODE11;
	NODE14->left = NODE13;
	NODE14->right = NODE15;

	Solution s;
	s.Print(NODE8);
	return 0;
}

