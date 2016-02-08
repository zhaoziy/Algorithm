// DFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
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

class DFS
{
public:
	vector<int> dfs(TreeNode* root)
	{
		vector<int> result;
		TreeNode *cur = root;
		Stack.push(cur);
		while (!Stack.empty())
		{
			result.push_back(cur->val);
			if (cur->right != NULL)
				Stack.push(cur->right);
			if (cur->left != NULL)
				Stack.push(cur->left);
			cur = Stack.top();
			Stack.pop();
		}
		return result;
	}

private:
	stack<TreeNode *> Stack;
};

int main()
{
	TreeNode Node1(1);
	TreeNode Node2(2);
	TreeNode Node3(3);
	TreeNode Node4(4);
	TreeNode Node5(5);
	TreeNode Node6(6);
	TreeNode Node7(7);
	Node1.left = &Node2;
	Node1.right = &Node3;
	Node2.left = &Node4;
	Node2.right = &Node5;
	Node3.left = &Node6;
	Node3.right = &Node7;

	DFS dfs;
	vector<int> Result;
	Result = dfs.dfs(&Node1);

	for (int i = 0; i < Result.size(); ++i)
	{
		cout << Result[i] << " ";
	}
	cout << endl;
	return 0;
}
