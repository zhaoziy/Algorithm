// TreeToString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class TreeToString {
public:
	string toString(TreeNode* root) {
		// write code here
		string resultStr;
		preOrderTraverse(root, resultStr);
		return resultStr;
	}

	void preOrderTraverse(TreeNode* root, string &str)
	{
		if (root == NULL)
		{
			str += "#!";
			return;
		}

		stringstream Stringstream;
		string str_temp;
		Stringstream << root->val;
		Stringstream >> str_temp;

		str = str + str_temp + "!";
		preOrderTraverse(root->left, str);
		preOrderTraverse(root->right, str);
	}
};

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

	TreeToString treeToString;
	string Result;
	Result = treeToString.toString(&Node1);

	cout << Result << " ";

	cout << endl;
	return 0;
}
