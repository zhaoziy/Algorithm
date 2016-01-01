// TreePrinter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		// write code here
		vector<vector<int>> result;
		vector<int> temp;
		vector<TreeNode*>  EndNode;
		Deque.push_back(root);
		
		TreeNode* last = root;
		TreeNode* nlast = root;

		while (!Deque.empty())
		{
			if (Deque.front()->left != NULL)
			{
				Deque.push_back(Deque.front()->left);
				nlast = Deque.front()->left;
			}
			if (Deque.front()->right != NULL)
			{
				Deque.push_back(Deque.front()->right);
				nlast = Deque.front()->right;
			}
			
			if (Deque.front() == last)
			{
				temp.push_back(Deque.front()->val);
				result.push_back(temp);
				temp.clear();
				last = nlast;
			}
			else
			{
				temp.push_back(Deque.front()->val);
			}

			Deque.pop_front();
		}
		return result;
	}
private:
	deque<TreeNode *> Deque;
};

int main()
{
	TreeNode Node0(0);
	TreeNode Node1(1);
	TreeNode Node2(2);
	TreeNode Node3(3);
	TreeNode Node4(4);
	TreeNode Node5(5);
	TreeNode Node6(6);
	TreeNode Node7(7);
	Node0.left = &Node1;
	Node0.right = &Node2;
	Node1.left = &Node3;
	Node1.right = &Node4;
	Node2.left = &Node5;
	Node2.right = &Node6;
	Node3.left = &Node7;

	TreePrinter treePrinter;
	vector<vector<int>> Result;
	Result = treePrinter.printTree(&Node0);

	for (int i = 0; i < Result.size(); ++i)
	{
		for (int j = 0; j < Result[i].size(); ++j)
		{
			cout << Result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
