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

//非递归版本
//思路：
//1.按先序遍历把当前节点cur的左孩子依次入栈同时保存当前节点，每次更新当前路径的和sum；
//2.判断当前节点是否是叶子节点以及sum是否等于expectNumber，如果是，把当前路径放入结果中。
//3.遇到叶子节点cur更新为NULL，此时看栈顶元素，如果栈顶元素的把栈顶元素保存在last变量中，同时弹出栈顶元素，当期路径中栈顶元素弹出，sum减掉栈顶元素，这一步骤不更改cur的值；
//4.如果步骤3中的栈顶元素的右孩子存在且右孩子之前没有遍历过，当前节点cur更新为栈顶的右孩子，此时改变cur = NULL的情况。

class Solution {
public:
	vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
		vector<vector<int> > res;
		if (root == NULL)
			return res;
		stack<TreeNode *> s;
		s.push(root);
		int sum = 0; //当前和
		vector<int> curPath; //当前路径
		TreeNode *cur = root; //当前节点
		TreeNode *last = NULL; //保存上一个节点
		while (!s.empty()) {
			if (cur == NULL) {
				TreeNode *temp = s.top();
				if (temp->right != NULL && temp->right != last) {
					cur = temp->right; //转向未遍历过的右子树
				}
				else {
					last = temp; //保存上一个已遍历的节点
					s.pop();
					curPath.pop_back(); //从当前路径删除
					sum -= temp->val;
				}
			}
			else {
				s.push(cur);
				sum += cur->val;
				curPath.push_back(cur->val);
				if (cur->left == NULL && cur->right == NULL && sum == expectNumber) {
					res.push_back(curPath);
				}
				cur = cur->left; //先序遍历，左子树先于右子树
			}
		}
		return res;
	}
};

//class Solution {
//	vector<vector<int> >allRes;
//	vector<int> tmp;
//	void dfsFind(TreeNode * node, int left) {
//		tmp.push_back(node->val);
//		if (left - node->val == 0 && !node->left && !node->right)
//			allRes.push_back(tmp);
//		else {
//			if (node->left) 
//				dfsFind(node->left, left - node->val);
//			if (node->right) 
//				dfsFind(node->right, left - node->val);
//		}
//		tmp.pop_back();
//	}
//public:
//	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
//		if (root) 
//			dfsFind(root, expectNumber);
//		return allRes;
//	}
//};

int main()
{
	TreeNode Node1(1);
	TreeNode Node2(2);
	TreeNode Node3(3);
	TreeNode Node4(4);
	TreeNode Node5(5);
	TreeNode Node6(6);
	TreeNode Node7(7);
	Node1.left = &Node2;
	Node1.right = &Node3;
	Node2.left = &Node4;
	Node2.right = &Node5;
	Node3.left = &Node6;
	Node3.right = &Node7;

	Solution dfs;
	vector<vector<int>> Result;
	Result = dfs.FindPath(&Node1,7);
	return 0;
}

