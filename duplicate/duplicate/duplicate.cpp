// duplicate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//class Solution {
//public:
//	// Parameters:
//	//        numbers:     an array of integers
//	//        length:      the length of array numbers
//	//        duplication: (Output) the duplicated number in the array number
//	// Return value:       true if the input is valid, and there are some duplications in the array number
//	//                     otherwise false
//	bool duplicate(int numbers[], int length, int* duplication) {
//		int *hash = new int[length];
//		for (int i = 0; i < length; ++i)
//			hash[i] = 0;
//		for (int i = 0; i < length; ++i)
//			hash[numbers[i]]++;
//		for (int i = 0; i < length; ++i)
//			if (hash[i] > 1)
//			{
//				*duplication = i;
//				return true;
//			}
//		return false;
//	}
//};

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		for (int i = 0; i < length; ++i)
		{
			int index = numbers[i];
			if (index > length - 1)
			{
				index = numbers[i] - length;
			}
			if (numbers[index] > length - 1)
			{
				*duplication = index;
				return true;
			}
			else
			{
				numbers[index] += length;
			}
		}
		return false;
	}
};

int main()
{
	int a[] = { 2,1,3,1,4 };
	Solution s;
	int b = 0;
	s.duplicate(a, 5, &b);
    return 0;
}

