// IsContinuous.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if ((int)numbers.size() < 5)
			return false;
		int min = 14, max = 0;
		sort(numbers);
		for (int i = 0; i < (int)numbers.size(); ++i)
		{
			if (numbers[i] < min && numbers[i] != 0)
				min = numbers[i];
			if (numbers[i] > max && numbers[i] != 0)
				max = numbers[i];
			if (i != (int)numbers.size() - 1 && numbers[i] != 0 && numbers[i] == numbers[i + 1])
				return false;
		}
		return (max - min > 4) ? false : true;
	}

	void sort(vector<int> &numbers)
	{
		for (int i = 0; i < (int)numbers.size() - 1; ++i)
			for (int j = i + 1; j < (int)numbers.size(); ++j)
				if (numbers[i] > numbers[j])
					swap(numbers[i], numbers[j]);
	}
};

int main()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(0);
	numbers.push_back(0);
	numbers.push_back(1);
	numbers.push_back(0);
	Solution s;
	bool a = s.IsContinuous(numbers);
    return 0;
}

