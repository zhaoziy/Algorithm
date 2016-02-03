// HasSubtree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <sstream>
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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		string RootStr1, RootStr2;
		Serialization(pRoot1, RootStr1);
		Serialization(pRoot2, RootStr2);
		return true;
	}

	void Serialization(TreeNode *pRoot, string &ret)
	{
		if (pRoot == NULL)
		{
			ret += "#!";
			return;
		}
		std::stringstream ss;
		std::string str;
		ss << pRoot->val;
		ss >> str;
		ret += str;
		Serialization(pRoot->left, ret);
		Serialization(pRoot->right, ret);
	}
};

int main()
{
	return 0;
}

