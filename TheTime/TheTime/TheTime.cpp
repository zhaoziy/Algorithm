// TheTime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	string input_Time;
	cin >> input_Time;
	string hour, minute;
	bool flag = false;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == ':')
		{
			flag = true;
		}
		else if (flag == false)
		{
			hour += input[i];
		}
		else
		{
			minute += input[i];
		}
	}
	int h = 0, m = 0, d = 0;
	istringstream in(hour);
	in >> h;
	istringstream in2(minute);
	in2 >> m;
	istringstream in3(input_Time);
	in3 >> d;
	m += d;
	while (m > 60)
	{
		m -= 60;
		h += 1;
		if (h > 23)
			h -= 24;
	}
	string ret;
	if (h == 0)
		ret += "00:";
	else if (h < 10)
		ret += "0" + to_string(h) + ":";
	else
		ret += to_string(h) + ":";

	if (m == 0)
		ret += "00:";
	else if (m < 10)
		ret += "0" + to_string(m);
	else
		ret += to_string(m);

	cout << ret;

    return 0;
}

