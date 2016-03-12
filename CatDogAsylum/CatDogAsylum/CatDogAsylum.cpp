// CatDogAsylum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <deque>
using namespace std;

class CatDogAsylum {
public:
	vector<int> asylum(vector<vector<int> > ope) {
		// write code here
		vector<int> ret;
		deque<int> dog, cat, all;
		int size = (int)ope.size();
		for (int i = 0; i < size; ++i) {
			if (ope[i][0] == 1) {
				if (ope[i][1] > 0) {
					dog.push_back(ope[i][1]);
					all.push_back(ope[i][1]);
				}
				else if (ope[i][1] < 0) {
					cat.push_back(ope[i][1]);
					all.push_back(ope[i][1]);
				}
			}
			else if (ope[i][0] == 2) {
				if (ope[i][1] == 0) {
					
					if (all.front() > 0) {
						ret.push_back(all.front());
						dog.pop_front();
						for (deque<int>::iterator iter = all.begin(); iter <= all.end(); iter++) {
							if (*iter > 0) {
								all.erase(iter);
								break;
							}
						}
					}
					else if (all.front() < 0) {
						ret.push_back(all.front());
						cat.pop_front();
						for (deque<int>::iterator iter = all.begin(); iter <= all.end(); iter++) {
							if (*iter < 0) {
								all.erase(iter);
								break;
							}
						}
					}
				}
				else if (ope[i][1] == 1) {
					ret.push_back(dog[0]);
					dog.pop_front();
					all.pop_front();
				}
				else if (ope[i][1] == -1) {
					ret.push_back(cat[0]);
					cat.pop_front();
					all.pop_front();
				}
			}
		}
		return ret;
	}
};

int main()
{
    return 0;
}

