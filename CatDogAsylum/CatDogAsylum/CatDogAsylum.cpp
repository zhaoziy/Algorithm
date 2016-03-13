// CatDogAsylum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class CatDogAsylum
{
public:
	vector<int> asylum(vector<vector<int> > ope)
	{
		// write code here
		vector<int> ret, all;
		int size = (int)ope.size();
		for (int i = 0; i < size; ++i) 
		{
			if (ope[i][0] == 1) 
				all.push_back(ope[i][1]);
			else if (ope[i][0] == 2) 
			{
				if(all.empty())
					continue;
				if (ope[i][1] == 0)
				{
					ret.push_back(all[0]);
					all.erase(all.begin());
				}
				else if (ope[i][1] == 1)
				{
					for (int i = 0; i < (int)all.size(); ++i)
					{
						if (all[i] > 0)
						{
							ret.push_back(all[i]);
							all.erase(all.begin() + i);
							break;
						}
					}
				}
				else if (ope[i][1] == -1) 
				{
					for (int i = 0; i < (int)all.size(); ++i) 
					{
						if (all[i] < 0)
						{
							ret.push_back(all[i]);
							all.erase(all.begin() + i);
							break;
						}
					}
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> temp;
	vector<vector<int>> ope;
	
	int b[][2] = { { 1,-3 },{ 1,-6 },{ 1,10 },{ 1,3 },{ 2,0 },{ 1,19 },{ 2,-1 },{ 1,-81 },{ 1,36 },{ 2,0 },{ 2,1 },
	{ 1,66 },{ 2,0 },{ 1,-13 },{ 2,0 },{ 2,-1 },{ 2,0 },{ 1,29 },{ 2,1 },{ 2,1 },{ 2,1 },{ 1,56 },{ 1,-99 },
	{ 2,-1 },{ 2,-1 },{ 1,79 },{ 1,-25 },{ 1,-6 },{ 1,63 },{ 1,48 },{ 1,-40 },{ 1,56 },{ 2,1 },{ 1,28 },
	{ 1,78 },{ 1,20 },{ 1,18 },{ 1,20 },{ 1,-92 },{ 1,87 },{ 2,0 },{ 1,34 },{ 2,-1 },{ 1,96 },{ 1,38 },
	{ 2,0 },{ 2,-1 },{ 1,17 },{ 1,13 },{ 1,3 },{ 1,-26 },{ 2,0 },{ 2,0 },{ 2,-1 },{ 2,1 },{ 2,0 },{ 1,-78 },
	{ 1,57 },{ 1,71 },{ 1,-11 },{ 2,-1 },{ 1,-28 },{ 1,-28 },{ 1,-87 },{ 1,-86 },{ 1,-9 },{ 1,50 },{ 2,1 },
	{ 2,0 },{ 1,65 },{ 1,-98 },{ 1,-54 },{ 2,0 },{ 2,-1 },{ 1,84 },{ 1,-72 },{ 1,-42 },{ 1,77 },{ 1,-61 },
	{ 1,-61 },{ 1,-11 },{ 1,94 },{ 2,1 },{ 1,93 },{ 2,-1 },{ 2,-1 },{ 1,43 },{ 2,-1 },{ 1,-72 },{ 2,-1 },
	{ 1,-31 },{ 1,-41 },{ 1,-85 },{ 1,-2 },{ 2,0 },{ 1,94 },{ 1,80 },{ 1,-86 },{ 1,-83 },{ 1,-20 },{ 1,49 },
	{ 1,-47 },{ 1,46 },{ 1,34 },{ 2,1 },{ 2,0 },{ 1,-41 },{ 2,1 },{ 2,-1 },{ 1,-44 },{ 1,100 },{ 1,-85 },
	{ 1,-25 },{ 1,-8 },{ 1,-69 },{ 1,13 },{ 1,82 },{ 2,1 },{ 1,-41 },{ 1,-44 },{ 1,22 },{ 1,-72 },{ 1,-16 },
	{ 1,-11 },{ 1,65 },{ 1,-66 },{ 1,25 },{ 1,-31 },{ 1,-63 },{ 2,1 },{ 1,86 },{ 1,2 },{ 1,6 },{ 1,-42 },
	{ 1,-9 },{ 1,76 },{ 1,54 },{ 2,0 },{ 2,1 } };

	for (int j = 0; j < sizeof(b) / sizeof(int) / 2; ++j)
	{
			temp.push_back(b[j][0]);
			temp.push_back(b[j][1]);
			ope.push_back(temp);
			temp.clear();
	}
	
	vector<int> ret;
	CatDogAsylum a;
	ret = a.asylum(ope);
    return 0;
}

