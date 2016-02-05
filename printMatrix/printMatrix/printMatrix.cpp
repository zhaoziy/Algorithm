// printMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ret;
		int startCol = 0;
		int startRow = 0;
		int endCol = matrix[0].size() - 1;
		int endRow = matrix.size() - 1;
		int i = startRow, j = startCol;
		while (startCol <= endCol && startRow <= endRow)
		{
			for (j = startCol; j <= endCol; ++j)
			{
				ret.push_back(matrix[i][j]);
			}
			j--;
			for (i = startRow + 1; i <= endRow; ++i)
			{
				ret.push_back(matrix[i][j]);
			}
			i--;

			if (startRow != endRow)
			{
				for (j--; j >= startCol; --j)
				{
					ret.push_back(matrix[i][j]);
				}
				j++;
			}

			if (startCol != endCol)
			{
				for (i--; i > startRow; --i)
				{
					ret.push_back(matrix[i][j]);
				}
				i++;
			}

			startCol++;
			startRow++;
			endCol--;
			endRow--;
		}
		return ret;
	}
};

int main()
{
	vector<int> a;
	vector<vector<int>> b;
	a.push_back(1);
	b.push_back(a);
	a.clear();

	a.push_back(2);
	b.push_back(a);
	a.clear();

	a.push_back(3);
	b.push_back(a);
	a.clear();

	a.push_back(4);
	b.push_back(a);
	a.clear();

	a.push_back(5);
	b.push_back(a);
	a.clear();

	Solution s;
	s.printMatrix(b);
	return 0;
}

