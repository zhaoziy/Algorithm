// TwoStackDeque.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>

using namespace std;

class TwoStackDeque
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (stack1.empty() != true)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int temp = 0;
		temp = stack2.top();
		stack2.pop();
		while (stack2.empty() != true)
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return temp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
    return 0;
}

