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
	int f[15000];
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		string RootStr1, RootStr2;
		Serialization(pRoot1, RootStr1);
		Serialization(pRoot2, RootStr2);
		int ret = find(RootStr1, RootStr2, f);
		if (ret == -1)
			return false;
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

	void getFail(string P, int* f)
	{
		int m = P.size();
		f[0] = 0;
		f[1] = 0;
		for (int i = 1; i < m; i++)
		{
			int j = f[i];
			while (j && P[i] != P[j])
			{
				j = f[j];
			}
			f[i + 1] = P[i] == P[j] ? j + 1 : 0;
		}
	}

	int find(string T, string P, int *f)
	{
		int n = T.size();
		int m = P.size();
		getFail(P, f);
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			while (j && P[j] != T[i])
			{
				j = f[j];
			}
			if (P[j] == T[i])
			{
				j++;
			}
			if (j == m)
			{
				return i - m + 1;
			}
		}
		return -1;
	}
};

int main()
{
	return 0;
}

