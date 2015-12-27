// TreeToSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class TreeToSequence {
public:
	vector<vector<int> > convert(TreeNode* root)
	{
		// write code here
	}

	void preOrderTraverse(TreeNode* root, vector<int> &ref)
	{
	}
	void inOrderTraversal(TreeNode* root, vector<int> &ref)
	{
	}
	void postOrderTraversal(TreeNode* root, vector<int> &ref)
	{
	}
};

int main()
{
	return 0;
}

