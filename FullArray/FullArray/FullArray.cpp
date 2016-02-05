// FullArray.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>
inline void swap(T* array, unsigned int i, unsigned int j)
{
	T t = array[i];
	array[i] = array[j];
	array[j] = t;
}

/*
* �ݹ�������е�ȫ����
*/
void FullArray(char* array, size_t array_size, unsigned int index)
{
	if (index >= array_size)
	{
		for (unsigned int i = 0; i < array_size; ++i)
		{
			cout << array[i] << ' ';
		}

		cout << '\n';

		return;
	}

	for (unsigned int i = index; i < array_size; ++i)
	{
		swap(array, i, index);

		FullArray(array, array_size, index + 1);

		swap(array, i, index);
	}
}

int main()
{
	char array[] = "123";
	FullArray(array, 3, 0);
	return 0;
}

