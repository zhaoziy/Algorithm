// InsertValue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class InsertValue {
public:
	ListNode* insert(vector<int> A, vector<int> nxt, int val) {
		// write code here
		ListNode *head = NULL;
		ListNode *current = NULL;
		for (int i = 0; i < A.size(); ++i)
		{
			ListNode temp(A[i]);
			current = &temp;

		}
	}
};

int main()
{
	vector<int> A;
	vector<int> next;
	ListNode* result = NULL;
	A.push_back(1);
	A.push_back(3);
	A.push_back(4);
	A.push_back(5);
	A.push_back(7);
	next.push_back(1);
	next.push_back(2);
	next.push_back(3);
	next.push_back(4);
	next.push_back(0);
	InsertValue iv;
	result = iv.insert(A, next, 2);
	return 0;
}

