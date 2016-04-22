// TreeLevel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class TreeLevel {
public:
	ListNode* getTreeLevel(TreeNode* root, int dep) {
		// write code here
		int level = 0;
		ListNode *right = NULL;
	}
};

int main()
{
	return 0;
}

