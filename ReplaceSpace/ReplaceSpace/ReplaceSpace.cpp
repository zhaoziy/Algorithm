// ReplaceSpace.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class ReplaceSpace
{
public:
	void replaceSpace(char *str, int length)
	{
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
		i = length - 1;
		while (*(str + i))
		{
			if (*(str + i) != ' ')
			{
				*(str + newLength) = *(str + i);
				newLength--;
			}
			else
			{
				*(str + newLength) = '0';
				*(str + newLength) = '2';
				*(str + newLength) = '%';
				newLength = newLength - 3;
			}
			i--;
		}
	}
};

int main()
{
    return 0;
}

