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

//class InsertValue {
//public:
//	ListNode* insert(vector<int> A, vector<int> nxt, int val) {
//		// write code here
//		ListNode *pre = NULL;
//		ListNode *current = new ListNode(A[0]);
//		ListNode *head = current;
//		for (int i = 1; i < A.size(); ++i)
//		{
//			ListNode *node = new ListNode(A[i]);
//			current->next = node;
//			current = current->next;
//		}
//
//		current->next = head;
//		pre = current;
//		current = current->next;
//
//		for (int i = 0; i < A.size(); ++i)
//		{
//			pre = current;
//			current = current->next;
//			if (pre->val < val && current->val >= val)
//			{
//				ListNode *node = new ListNode(val);
//				pre->next = node;
//				node->next = current;
//				break;
//			}
//		}
//		if (current == head)
//		{
//			ListNode *node = new ListNode(val);
//			pre->next = node;
//			node->next = current;
//			if (val <= head->val)
//			{
//				head = node;
//				pre->next = NULL;
//			}
//			else
//			{
//				pre->next->next = NULL;
//			}
//		}
//		else
//		{
//			while (current->next != head)
//			{
//				current = current->next;
//			}
//			current->next = NULL;
//		}
//		return head;
//	}
//};

class InsertValue {
public:
	ListNode* insert(vector<int> A, vector<int> nxt, int val) {
		ListNode *NumNode = new ListNode(val);

		if (A.empty()) 
		{
			NumNode->next = NumNode;
			return  NumNode;
		}
		else 
		{
			ListNode *head = new ListNode(A[0]);
			if (A.size() == 1)
			{
				head->next = NumNode;
				NumNode->next = head;
				return head;
			}
			else 
			{
				ListNode *current = head;

				for (int i = 1; i < A.size(); i++) 
				{
					current->next = new ListNode(A[i]);
					current = current->next;
				}
				//current->next = head;

				current = head;
				ListNode *previous = head->next;
				for (int i = 1; i < A.size(); i++) 
				{
					if ((val >= current->val && val <= previous->val) ||
						(val <= current->val && val >= previous->val))
					{
						break;
					}
					current = previous;
					previous = previous->next;
				}

				NumNode->next = previous;
				current->next = NumNode;

				return head;
			}
		}
	}
};

int main()
{
	vector<int> A;
	vector<int> next;
	ListNode* result = NULL;
	A.push_back(4);
	A.push_back(8);
	A.push_back(9);
	next.push_back(1);
	next.push_back(2);
	next.push_back(0);
	InsertValue iv;
	result = iv.insert(A, next, 4);
	return 0;
}

