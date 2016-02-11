// FindPath.cpp : �������̨Ӧ�ó������ڵ㡣
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

//�ǵݹ�汾
//˼·��
//1.����������ѵ�ǰ�ڵ�cur������������ջͬʱ���浱ǰ�ڵ㣬ÿ�θ��µ�ǰ·���ĺ�sum��
//2.�жϵ�ǰ�ڵ��Ƿ���Ҷ�ӽڵ��Լ�sum�Ƿ����expectNumber������ǣ��ѵ�ǰ·���������С�
//3.����Ҷ�ӽڵ�cur����ΪNULL����ʱ��ջ��Ԫ�أ����ջ��Ԫ�صİ�ջ��Ԫ�ر�����last�����У�ͬʱ����ջ��Ԫ�أ�����·����ջ��Ԫ�ص�����sum����ջ��Ԫ�أ���һ���費����cur��ֵ��
//4.�������3�е�ջ��Ԫ�ص��Һ��Ӵ������Һ���֮ǰû�б���������ǰ�ڵ�cur����Ϊջ�����Һ��ӣ���ʱ�ı�cur = NULL�������

class Solution {
public:
	vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
		vector<vector<int> > res;
		if (root == NULL)
			return res;
		stack<TreeNode *> s;
		s.push(root);
		int sum = 0; //��ǰ��
		vector<int> curPath; //��ǰ·��
		TreeNode *cur = root; //��ǰ�ڵ�
		TreeNode *last = NULL; //������һ���ڵ�
		while (!s.empty()) {
			if (cur == NULL) {
				TreeNode *temp = s.top();
				if (temp->right != NULL && temp->right != last) {
					cur = temp->right; //ת��δ��������������
				}
				else {
					last = temp; //������һ���ѱ����Ľڵ�
					s.pop();
					curPath.pop_back(); //�ӵ�ǰ·��ɾ��
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
				cur = cur->left; //�������������������������
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

