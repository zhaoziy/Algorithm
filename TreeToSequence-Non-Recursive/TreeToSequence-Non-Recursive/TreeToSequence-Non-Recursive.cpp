// TreeToSequence-Non-Recursive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	/*TreeNode(int x) :	val(x), left(NULL), right(NULL)
	{
	}*/
};

class TreeToSequence
{
public:
	vector<vector<int> > convert(TreeNode* root)
	{
		// write code here
		vector<int> A, B, C;
		vector<vector<int>> Result;
		preOrderTraverse(*root, A);
		inOrderTraversal(*root, B);
		postOrderTraversal(*root, C);
		Result.push_back(A);
		Result.push_back(B);
		Result.push_back(C);
		return Result;
	}

	void preOrderTraverse(TreeNode &root, vector<int> &ref)
	{
		stack<TreeNode*> S;
		TreeNode *cur = NULL;
		S.push(&root);
		while (S.empty() != true)
		{
			cur = S.top();
			S.pop();
			ref.push_back(cur->val);
			if (cur->right != NULL)
			{
				S.push(cur->right);
			}
			if (cur->left != NULL)
			{
				S.push(cur->left);
			}
		}
	}

	void inOrderTraversal(TreeNode &root, vector<int> &ref)
	{
		stack<TreeNode*> S;
		TreeNode *cur = &root;
		while (!(cur == NULL && S.empty() == true))
		{
			if (cur == NULL)
			{
				ref.push_back(S.top()->val);
				cur = S.top()->right;
				S.pop();
				continue;
			}
			S.push(cur);
			cur = cur->left;
		}
	}

	void postOrderTraversal(TreeNode &root, vector<int> &ref)
	{
		stack<TreeNode*> s1, s2;
		s1.push(&root);

		TreeNode *cur = NULL;
		while (s1.empty() != true)
		{
			cur = s1.top();
			s2.push(s1.top());
			s1.pop();
			if (cur->left != NULL)
			{
				s1.push(cur->left);
			}
			if (cur->right != NULL)
			{
				s1.push(cur->right);
			}
		}
		while (s2.empty() != true)
		{
			ref.push_back(s2.top()->val);
			s2.pop();
		}
	}
};

int main()
{
	TreeNode node[7];
	node[0].val = 0;
	node[0].left = &node[1];
	node[0].right = &node[2];

	node[1].val = 1;
	node[1].left = &node[3];
	node[1].right = &node[4];

	node[2].val = 2;
	node[2].left = &node[5];
	node[2].right = &node[6];

	node[3].val = 3;
	node[3].left = NULL;
	node[3].right = NULL;

	node[4].val = 4;
	node[4].left = NULL;
	node[4].right = NULL;

	node[5].val = 5;
	node[5].left = NULL;
	node[5].right = NULL;

	node[6].val = 6;
	node[6].left = NULL;
	node[6].right = NULL;

	TreeToSequence Sequene;
	vector<vector<int>> Result;
	Result = Sequene.convert(&node[0]);

	cout << "先序遍历" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << Result[0][i] << " ";
	}
	cout << endl;

	cout << "中序遍历" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << Result[1][i] << " ";
	}
	cout << endl;

	cout << "后序遍历" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << Result[2][i] << " ";
	}
	cout << endl;
	return 0;
}
