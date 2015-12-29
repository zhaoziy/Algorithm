// Checker.cpp : 定义控制台应用程序的入口点。
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
	/*TreeNode(int x) :	val(x), left(NULL), right(NULL)
	{
	}*/
};

class Checker {
public:
	bool checkDuplicate(vector<int> a, int n) {
		// write code here
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
	vector<int> init_Array;
	init_Array.push_back(1);
	init_Array.push_back(2);
	init_Array.push_back(3);
	init_Array.push_back(4);
	init_Array.push_back(5);
	init_Array.push_back(5);
	init_Array.push_back(6);

	Checker sort;
	bool result = false;
	result = sort.checkDuplicate(init_Array, init_Array.size());
	for (int i = 0; i < init_Array.size(); ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}