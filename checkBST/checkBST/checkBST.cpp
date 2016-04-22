// checkBST.cpp : 定义控制台应用程序的入口点。
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

class Checker {
public:
	bool checkBST(TreeNode* root) {
		// write code here
		if (root == NULL)
			return false;
		vector<int> ret;
		Traverse(root, ret);
		for (int i = 0; i < (int)ret.size() - 1; ++i)
		{
			if (ret[i] > ret[i + 1])
				return false;
		}
		return true;
	}

	void Traverse(TreeNode* root, vector<int> &ret)
	{
		if (root == NULL)
			return;
		if (root->left != NULL)
			Traverse(root->left, ret);
		ret.push_back(root->val);
		if (root->right != NULL)
			Traverse(root->right, ret);
	}
};

int main()
{
	return 0;
}

