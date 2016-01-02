// IdenticalTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	/*TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}*/
};

class IdenticalTree 
{
public:
	bool chkIdentical(TreeNode* A, TreeNode* B) 
	{
		// write code here
		string Astr, Bstr;
		serialization(A, Astr);
		serialization(B, Bstr);

		if (Finder(Astr, Bstr))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void serialization(TreeNode *Node, string &str)
	{
		if (Node == NULL)
		{
			str += "#!";
			return;
		}

		stringstream Strstream;
		string strtemp;
		Strstream << Node->val;
		Strstream >> strtemp;

		str = str + strtemp + "!";
		serialization(Node->left, str);
		serialization(Node->right, str);
	}

	bool Finder(string A, string B)
	{
		for (int i = 0; i < A.size(); ++i)
		{
			int index = i;
			int count = 0;
			for (int j = 0; j < B.size(); ++j)
			{
				if (A[index++] == B[j])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if (count == B.size())
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	TreeNode node[7];
	node[0].val = 0;
	node[0].left = &node[1];
	node[0].right = &node[2];

	node[1].val = 1;
	node[1].left = &node[3];
	node[1].right = &node[4];

	node[2].val = 2;
	node[2].left = &node[5];
	node[2].right = &node[6];

	node[3].val = 3;
	node[3].left = NULL;
	node[3].right = NULL;

	node[4].val = 4;
	node[4].left = NULL;
	node[4].right = NULL;

	node[5].val = 5;
	node[5].left = NULL;
	node[5].right = NULL;

	node[6].val = 6;
	node[6].left = NULL;
	node[6].right = NULL;

	TreeNode nodeX[3];
	nodeX[0].val = 1;
	nodeX[0].left = &nodeX[1];
	nodeX[0].right = &nodeX[2];

	nodeX[1].val = 3;
	nodeX[1].left = NULL;
	nodeX[1].right = NULL;

	nodeX[2].val = 4;
	nodeX[2].left = NULL;
	nodeX[2].right = NULL;

	bool result = false;
	IdenticalTree identicalTree;
	result = identicalTree.chkIdentical(node, nodeX);

	cout << result << endl;

	return 0;
}

