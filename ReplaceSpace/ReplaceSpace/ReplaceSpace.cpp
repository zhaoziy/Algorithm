// ReplaceSpace.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class ReplaceSpace
{
public:
	void replaceSpace(char *str, int length)
	{
		if (str[0] == '\0')
			return;
		int count = 0;
		int i = 0;
		while (*(str + i))
		{
			if (*(str + i) == ' ')
			{
				count++;
			}
			i++;
		}

		int newLength = length + 2 * count;
		char *str_result = new char[newLength + 1];
		str_result[newLength] = '\0';
		for (int i = 0; i < newLength; ++i)
		{
			str_result[i] = '0';
		}
		i = length - 1;
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				str_result[newLength - 1] = str[i];
				newLength--;
			}
			else
			{
				str_result[newLength - 1] = '0';
				str_result[newLength - 2] = '2';
				str_result[newLength - 3] = '%';
				newLength = newLength - 3;
			}
		}
		strcpy(str, str_result);
	}
};

int main()
{
	//char *str = new char[12];
	char *str = "";
	//strncpy(str, "We Are Happy", 12);
	ReplaceSpace replace;
	replace.replaceSpace(str, 0);
	cout << str;
    return 0;
}

