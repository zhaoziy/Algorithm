// CountNodes.cpp : �������̨Ӧ�ó������ڵ㡣
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

class CountNodes {
public:
	int count(TreeNode* root) {
		// write code here
		int Icount= 1;
		TreeNode *leftNode = root;
		while (leftNode != NULL)
		{
			Icount++;
			leftNode = leftNode->left;
		}
		int i = 1;
		leftNode = root;
		while (leftNode != NULL)
		{
			if (i++ == Icount)
			{
				leftNode = leftNode->left;
			}
			else
			{
				leftNode = leftNode->right;
			}
		}
		if (leftNode != NULL)
		{
			//������Ϊ����
		}
		else
		{
			//������Ϊ����
		}
	}
};

int main()
{
	return 0;
}

