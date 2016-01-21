// LongestDistance.cpp : �������̨Ӧ�ó������ڵ㡣
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

class LongestDistance {
public:
	int findLongest(TreeNode* root) {
		// write code here
		int LongDisInTree = 0;
		int LongDisToHead = 0;
		findDistance(root, LongDisInTree, LongDisToHead);
		return LongDisInTree;
	}

	void findDistance(TreeNode* head, int &LongDisInTree, int &LongDisToHead)//��headΪͷ����ڵľ���
	{
		if (head == NULL)
		{
			LongDisInTree = 0;
			LongDisToHead = 0;
			return;
		}
		int LMax1 = 0;  //�������ϵ�������(��������)
		int LMax2 = 0;  //�������Ͼ���head���ӵ���Զ����
		int RMax1 = 0;  //�������ϵ�������(��������)
		int RMax2 = 0;  //�������Ͼ���head�Һ��ӵ���Զ����
		findDistance(head->left, LMax1, LMax2);
		findDistance(head->right, RMax1, RMax2);
		LongDisInTree = (LMax1 > RMax1) ? (LMax1) : (RMax1);
		LongDisInTree = (LongDisInTree > (LMax2 + RMax2 + 1)) ? (LongDisInTree) : (LMax2 + RMax2 + 1);
		LongDisToHead = (LMax2 > RMax2) ? (LMax2 + 1) : (RMax2 + 1);
	}
};

int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);

	node6->left = node4;
	//node6->right = node6;

	node4->right = node2;

	node2->left = node5;
	//node2->right = node9;

	node5->left = node1;

	node1->left = node3;
	//node8->left = node7;

	LongestDistance c;
	int a = c.findLongest(node6);
	return 0;
}

