// MaxSubtree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//class MaxSubtree {
//public:
//	TreeNode* getMax(TreeNode* root) {
//		// write code here
//		TreeNode* headMax = NULL;
//		int nodeNum = 0;
//		int MinNum = 0;
//		int MaxNum = 0;
//		maxSubtree(root, headMax, nodeNum, MinNum, MaxNum);
//		return headMax;
//	}
//
//	void maxSubtree(TreeNode* head, TreeNode* headMax, int &nodeNum, int &MinNum, int &MaxNum)
//	{
//		if (head == NULL)
//			return;
//		TreeNode* LeftHeadMax = NULL;
//		int LeftNode = 0;
//		int LeftMin = -1;
//		int LeftMax = -1;
//
//		TreeNode* RightHeadMax = NULL;
//		int RightNode = 0;
//		int RightMin = -1;
//		int RightMax = -1;
//
//		maxSubtree(head->left, LeftHeadMax, LeftNode, LeftMin, LeftMax);
//		maxSubtree(head->right, RightHeadMax, RightNode, RightMin, RightMax);
//
//		if (LeftMax < head->val && head->val < RightMin)
//			headMax = head;
//		else if (LeftNode == 0 && RightNode == 0)
//			headMax = head;
//		else if (LeftNode < RightNode)
//			headMax = LeftHeadMax;
//		else
//			headMax = RightHeadMax;
//
//		nodeNum = LeftNode + RightNode + 1;
//
//		if (LeftMin >= 0 && RightMin >= 0)
//		{
//			MinNum = (LeftMin < RightMin) ? (LeftMin) : (RightMin);
//			MinNum = (MinNum < head->val) ? (MinNum) : (head->val);
//		}
//		else
//		{
//			MinNum = (LeftMin < 0) ? (RightMin) : (LeftMin);
//		}
//
//		if (LeftMax >= 0 && RightMax >= 0)
//		{
//			MaxNum = (LeftMax > RightMax) ? (LeftMax) : (RightMax);
//			MaxNum = (MaxNum > head->val) ? (MaxNum) : (head->val);
//		}
//		else
//		{
//			MaxNum = (LeftMax < 0) ? (RightMax) : (LeftMax);
//		}
//	}
//};

class MaxSubtree {
public:
	bool chk[550];
	void get(TreeNode* root, int *min, int *max, int *size, TreeNode *&ret, int &msz)
	{
		int v = root->val;
		min[v] = 10101010;
		max[v] = 0;
		chk[v] = false;
		int leftSize = 0, rightSize = 0, leftMax = 0, rightMax = 0, leftMin = 10101010, rightMin = 10101010;
		bool cl = true, cr = true;
		if (root->left)
		{
			get(root->left, min, max, size, ret, msz);
			leftSize = size[root->left->val];
			leftMin = min[root->left->val];
			leftMax = max[root->left->val];
			cl = chk[root->left->val];
		}
		if (root->right)
		{
			get(root->right, min, max, size, ret, msz);
			rightSize = size[root->right->val];
			rightMin = min[root->right->val];
			rightMax = max[root->right->val];
			cr = chk[root->right->val];
		}

		if (leftSize != -1 && rightSize != -1)
		{
			if (cl && cr && leftMax < v && v < rightMin)
			{
				int tmp = leftSize + rightSize + 1;
				chk[v] = true;
				if (tmp > msz || (tmp == msz && ret->val < v))
				{
					ret = root; msz = tmp;
				}
			}
			size[v] = leftSize + rightSize + 1;
			max[v] = (v > leftMax) ? (v) : (leftMax);
			min[v] = (v < leftMin) ? (v) : (leftMin);
		}
	}
	TreeNode* getMax(TreeNode* root) {
		TreeNode* ret = NULL;
		int mn[550], mx[550], sz[550], msz = 0;
		get(root, mn, mx, sz, ret, msz);
		return ret;
	}
};

int main()
{
	TreeNode* node0 = new TreeNode(0);
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);

	TreeNode* node10 = new TreeNode(10);
	TreeNode* node11 = new TreeNode(11);
	TreeNode* node12 = new TreeNode(12);
	TreeNode* node13 = new TreeNode(13);
	TreeNode* node14 = new TreeNode(14);
	TreeNode* node15 = new TreeNode(15);
	TreeNode* node16 = new TreeNode(16);

	TreeNode* node20 = new TreeNode(20);

	node6->left = node1;
	node6->right = node12;

	node1->left = node0;
	node1->right = node3;

	node12->left = node10;
	node12->right = node13;

	node10->left = node4;
	node10->right = node14;

	node4->left = node2;
	node4->right = node5;

	node14->left = node11;
	node14->right = node15;

	node13->left = node20;
	node13->right = node16;

	MaxSubtree c;
	TreeNode* a = c.getMax(node6);
	return 0;
}