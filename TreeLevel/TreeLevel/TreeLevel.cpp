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
		if (root == NULL)
			return NULL;
		int level = 1;
		TreeNode *CurRight = root;
		TreeNode *NextRight = NULL;
		deque<TreeNode*> deq;
		deq.push_back(root);
		ListNode *head = new ListNode(0);
		ListNode *cur = head;
		while (!deq.empty())
		{
			TreeNode *Cur = deq.front();
			deq.pop_front();
			if (level == dep)
			{
				ListNode *curnode = new ListNode(Cur->val);
				cur->next = curnode;
				cur = curnode;
			}
			else if(level > dep)
			{
				break;
			}
			if (Cur->left != NULL)
			{
				deq.push_back(Cur->left);
				NextRight = Cur->left;
			}
			if (Cur->right != NULL)
			{
				deq.push_back(Cur->right);
				NextRight = Cur->right;
			}
			if (Cur == CurRight)
			{
				CurRight = NextRight;
				level++;
			}
		}
		return head->next;
	}
};

int main()
{
	return 0;
}

