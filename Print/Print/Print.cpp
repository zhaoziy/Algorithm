// Print.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
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
	
	vector<vector<int>> Print(TreeNode* pRoot) {
		deque<TreeNode*> deq;
		vector<int> temp;
		vector<vector<int>> ret;
		if (!pRoot)
			return ret;
		deq.push_back(pRoot);
		TreeNode* last = pRoot;
		TreeNode* nlast = NULL;
		while (!deq.empty())
		{
			TreeNode* cur = deq.front();
			deq.pop_front();
			if (cur->left)
			{
				deq.push_back(cur->left);
				nlast = cur->left;
			}
			if (cur->right)
			{
				deq.push_back(cur->right);
				nlast = cur->right;
			}
			temp.push_back(cur->val);
			if (cur == last)
			{
				ret.push_back(temp);
				temp.clear();
				last = nlast;
			}
		}
		return ret;
	}
};

int main()
{
	TreeNode *NODE0 = new TreeNode(0);
	TreeNode *NODE1 = new TreeNode(1);
	TreeNode *NODE2 = new TreeNode(2);
	TreeNode *NODE3 = new TreeNode(3);
	TreeNode *NODE4 = new TreeNode(4);
	TreeNode *NODE5 = new TreeNode(5);

	NODE0->left = NODE1;
	NODE1->left = NODE2;
	NODE1->right = NODE3;
	NODE2->left = NODE4;
	NODE2->right = NODE5;

	Solution s;
	s.Print(NODE5);
	return 0;
}

