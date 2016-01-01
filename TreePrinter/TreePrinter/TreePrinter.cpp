// TreePrinter.cpp : 定义控制台应用程序的入口点。
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

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		// write code here
	}
};

int main()
{
	return 0;
}

