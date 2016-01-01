// reConstructBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ReConstructBinaryTree {
public:
	struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
		if (pre.size() == 0)
			return NULL;

		vector<int> pre_left;
		vector<int> pre_right;
		vector<int> in_left;
		vector<int> in_right;
		struct TreeNode *head = new TreeNode(pre[0]);

		bool flag = false;
		for (int i = 0; i < in.size(); ++i)
		{
			if (in[i] != pre[0])
			{
				if (flag == false)
				{
					in_left.push_back(in[i]);
				}
				else
				{
					in_right.push_back(in[i]);
				}
			}
			else
			{
				flag = true;
			}
		}
		for (int i = 0; i < pre.size(); ++i)
		{
			for (int j = 0; j < in_left.size(); ++j)
			{
				if (pre[i] == in_left[j])
				{
					pre_left.push_back(pre[i]);
					break;
				}
			}

			for (int j = 0; j < in_right.size(); ++j)
			{
				if (pre[i] == in_right[j])
				{
					pre_right.push_back(pre[i]);
					break;
				}
			}
		}

		head->left = reConstructBinaryTree(pre_left, in_left);
		head->right = reConstructBinaryTree(pre_right, in_right);

		return head;
	}
};

int main()
{
	int pre[8] = { 1,2,4,7,3,5,6,8 };
	int in[8] = { 4,7,2,1,5,3,8,6 };

	vector<int> pre_vec;
	vector<int> in_vec;

	for (int i = 0; i < 8; ++i)
	{
		pre_vec.push_back(pre[i]);
		in_vec.push_back(in[i]);
	}

	ReConstructBinaryTree sol;
	struct TreeNode *head(0);

	head = sol.reConstructBinaryTree(pre_vec, in_vec);
	return 0;
}
