// FoldPaper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class FoldPaper {
public:
	vector<string> foldPaper(int n) {
		// write code here
		vector<string> res;
		printFoldPaper("down", res, n);
		return res;
	}

	void printFoldPaper(string head, vector<string> &res, int n)
	{
		if (n == 0)
			return;
		printFoldPaper("down", res, n - 1);
		res.push_back(head);
		printFoldPaper("up", res, n - 1);
	}
};

int main()
{
	FoldPaper f;
	f.foldPaper(3);
    return 0;
}

