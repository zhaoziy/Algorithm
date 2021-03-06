// BFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class BFS
{
public:
	vector<int> bfs(TreeNode* root)
	{
		vector<int> result;
		Deque.push_back(root);

		while (!Deque.empty())
		{
			result.push_back(Deque.front()->val);
			if (Deque.front()->left != NULL)
			{
				Deque.push_back(Deque.front()->left);
			}
			if (Deque.front()->right != NULL)
			{
				Deque.push_back(Deque.front()->right);
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
	
	BFS bfs;
	vector<int> Result;
	Result = bfs.bfs(&Node1);

	for (int i = 0; i < Result.size(); ++i)
	{
		cout << Result[i] << " ";
	}
	cout << endl;
	return 0;
}
