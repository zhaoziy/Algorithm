// DFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

typedef struct Graph
{
	int Vex[8];
	int Edge[8][8];
};

class DFS
{
private:
	bool edge[8][8] = { false };
public:
	void dfs(Graph MyGraph, int vex, vector<int> &result)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (MyGraph.Edge[vex][i] == 1 && edge[vex][i] == false)
			{
				result.push_back(i);
				for (int j = 0; j < 8; ++j)
				{
					if(j !=vex)
						edge[j][i] = true;
				}
				dfs(MyGraph, i, result);
			}
		}
	}

	void DFS_Main(Graph MyGraph, int vex, vector<int> &result)
	{
		for (int j = 0; j < 8; ++j)
		{
			edge[j][vex] = true;
		}
		dfs(MyGraph, vex, result);
	}
};

int main()
{
	Graph MyGraph = { {0},{{0}} };
	for (int i = 0; i < 8; ++i)
	{
		MyGraph.Vex[i] = i;
	}

	MyGraph.Edge[0][1] = 1;
	MyGraph.Edge[1][0] = 1;
	MyGraph.Edge[1][2] = 1;
	MyGraph.Edge[2][1] = 1;
	MyGraph.Edge[2][5] = 1;
	MyGraph.Edge[5][2] = 1;
	MyGraph.Edge[1][4] = 1;
	MyGraph.Edge[4][1] = 1;
	MyGraph.Edge[0][4] = 1;
	MyGraph.Edge[4][0] = 1;
	MyGraph.Edge[0][3] = 1;
	MyGraph.Edge[3][0] = 1;
	MyGraph.Edge[3][6] = 1;
	MyGraph.Edge[6][3] = 1;
	MyGraph.Edge[4][6] = 1;
	MyGraph.Edge[6][4] = 1;
	MyGraph.Edge[7][6] = 1;
	MyGraph.Edge[6][7] = 1;
	
	DFS dfs;
	vector<int> Result;
	Result.push_back(0);
	dfs.DFS_Main(MyGraph, 0, Result);

	for (int i = 0; i < Result.size(); ++i)
	{
		cout << Result[i] << " ";
	}
	cout << endl;
	return 0;
}
