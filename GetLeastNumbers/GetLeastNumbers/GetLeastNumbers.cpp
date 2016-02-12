// GetLeastNumbers.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ret;
		if (k > input.size())
			return ret;
		for (int i = 0; i < k; ++i)
		{
			BuildMinHeap(input, input.size() - i);      //����
			ret.push_back(input[0]);
			swap(input[0], input[input.size() - i - 1]);	
		}
		return ret;
	}

	void MinHeapIfy(vector<int> &A, int length, int i)  //ά��
	{
		int left = (i + 1) * 2 - 1;  //�ڵ�i������
		int right = (i + 1) * 2; //�ڵ�i���Һ��ӽڵ�
		int smallest = i;  //Ĭ�ϸ��ڵ�

		if (left < length && A[smallest] > A[left]) 
		{
			smallest = left;
		}

		if (right < length && A[smallest] > A[right]) 
		{
			smallest = right;
		}

		if (i != smallest) 
		{
			int temp = A[smallest]; //exchange
			A[smallest] = A[i];
			A[i] = temp;

			MinHeapIfy(A, length, smallest);  //����ά��
		}
	}

	void BuildMinHeap(vector<int> &A, int length)  //����
	{
		for (int i = length / 2 - 1; i >= 0; i--)
		{
			MinHeapIfy(A, length, i);
		}
	}
};

int main()
{
	vector<int> a;
	a.push_back(4);
	a.push_back(5);
	a.push_back(1);
	a.push_back(6);
	a.push_back(2);
	a.push_back(7);
	a.push_back(3);
	a.push_back(8);
	Solution b;
	b.GetLeastNumbers_Solution(a, 4);
	return 0;
}

