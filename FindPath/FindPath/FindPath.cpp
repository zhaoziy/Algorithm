// FindPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {

	}
};

int main()
{
	return 0;
}

