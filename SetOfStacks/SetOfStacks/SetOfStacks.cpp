// SetOfStacks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

//class SetOfStacks {
//public:
//	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
//		// write code here
//		vector<int> sta;
//		vector<vector<int>> ret;
//		for (int i = 0; i < (int)ope.size(); ++i) {
//			if (ope[i][0] == 1)
//				sta.push_back(ope[i][1]);
//			if (ope[i][0] == 2 && (int)sta.size() != 0)
//				sta.pop_back();
//		}
//		vector<int> temp;
//		int count = 0;
//		for (int i = 0; i < (int)sta.size(); ++i) {
//			if (count < size) {
//				temp.push_back(sta[i]);
//				count++;
//			}
//			else {
//				ret.push_back(temp);
//				temp.clear();
//				count = 0;
//				i--;
//			}
//		}
//		if (!temp.empty())
//			ret.push_back(temp);
//		return ret;
//	}
//};

class SetOfStacks {
public:
	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
		// write code here
		vector<int> vect;
		vector<vector<int>> A;
		int len = vect.size();
		for (int i = 0; i < ope.size(); i++){
			if (ope[i][0] == 1){
				if (A.size() == 0){
					if (vect.size() == size){
						A.push_back(vect);
						vect.clear();}
					vect.push_back(ope[i][1]);}
				else{
					if (A[A.size() - 1].size() < size)
						A[A.size() - 1].push_back(ope[i][1]);
					else{
						if (vect.size() == size){
							A.push_back(vect);
							vect.clear();}
						vect.push_back(ope[i][1]);}}}
			else{
				if (vect.empty()){
					A[A.size() - 1].pop_back();
					if (A[A.size() - 1].empty())
						A.pop_back();}
				else
					vect.pop_back();}}
		if (!vect.empty())
			A.push_back(vect);
		return A;
	}
};

int main()
{
	vector<int> temp;
	vector<vector<int>> B;
	temp.push_back(1);
	temp.push_back(97868);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(69995);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(28525);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(72341);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(86916);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(5966);
	B.push_back(temp);
	temp.clear();
	temp.push_back(2);
	temp.push_back(58473);
	B.push_back(temp);
	temp.clear();
	temp.push_back(2);
	temp.push_back(93399);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(84955);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(16420);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(96091);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(45179);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(59472);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(49594);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(67060);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(25466);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(50357);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(83509);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(39489);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(51884);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(34140);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(8981);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(50722);
	B.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(65104);
	B.push_back(temp);
	temp.clear();



	SetOfStacks s;
	s.setOfStacks(B, 2);
    return 0;
}

