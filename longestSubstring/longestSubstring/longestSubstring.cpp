// longestSubstring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class DistinctSubstring {
public:
	int longestSubstring(string A, int n) {
		// write code here
		int hash[256];
		int pre = -1;
		int result = 0;
		memset(hash, -1, 256 * sizeof(int));
		for (int i = 0; i < n; ++i)
		{
			pre = max(hash[A[i]], pre);
			result = max(result, i - pre);
			hash[A[i]] = i;
		}
		return result;
	}

	int max(int A, int B)
	{
		return (A > B) ? (A) : (B);
	}
};

int main()
{
	string A = "aabcb";
	DistinctSubstring ds;
	int result = ds.longestSubstring(A, 5);
	cout << result;
	return 0;
}

