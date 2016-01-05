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

		if (kmp(Astr, Bstr))
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

	bool kmp(string target, string pattern)
	{
		int *next = NULL;
		next = getNext(pattern);
		int target_pt = 0;
		int pattern_pt = 0;
		while (target_pt < target.size() && pattern_pt < pattern.size())
		{
			if (target[target_pt] != pattern[pattern_pt])
			{
				pattern_pt = next[pattern_pt + 1];
				pattern_pt--;
			}
			else
			{
				target_pt++;
				pattern_pt++;
			}

			if (pattern_pt == -1)
			{
				target_pt++;
				pattern_pt++;
			}
		}
		if (pattern_pt >= pattern.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int* getNext(string Pattern)
	{
		string Temp = " " + Pattern;
		int *next = new int[Temp.size()];
		next[0] = next[1] = 0;
		int i = 1;
		int j = 0;
		while (i < Pattern.size())
		{
			if (j == 0 || Temp[i] == Temp[j])
			{
				i++;
				j++;
				if (Temp[i] == Temp[j])
				{
					next[i] = next[j];
				}
				else
				{
					next[i] = j;
				}
			}
			else
			{
				j = next[j];
			}
		}
		return next;
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

