// 204B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;
#define N 100000

typedef struct InitCard
{
	int frontCard;
	int backCard;
};

typedef struct Card
{
	int Color;
	int num;
};

InitCard initcards[N];
Card cards[N];
int A[N];

int comp(const void*a, const void*b)
{
	struct Card*c = (Card*)a;
	struct Card*d = (Card*)b;
	return d->num - c->num;
}

int main()
{
	int Count = 0;
	while (scanf("%d", &Count) != EOF)
	{
		for (int i = 0; i < N; ++i)
		{
			initcards[i].backCard = -1;
			initcards[i].frontCard = -1;
			cards[i].Color = -1;
			cards[i].num = 0;
			A[i] = -1;
		}
		for (int i = 0; i < Count; ++i)
		{
			int a = 0, b = 0;
			scanf("%d %d", &a, &b);
			initcards[i].frontCard = a;
			A[i] = a;
			initcards[i].backCard = b;
		}
		int num = 0;
		for (int i = 0; i < Count; ++i)
		{
			if (A[i] != -1)
			{
				cards[num].Color = A[i];
				for (int j = i; j < Count; ++j)
				{
					if (A[j] == cards[num].Color)
					{
						cards[num].num++;
						A[j] = -1;
					}
				}
				num++;
			}
		}
		qsort(cards, num, sizeof(Card), comp);
		bool flag = false;
		for (int i = 0; i < num; ++i)
		{
			int ret_count = cards[i].num;
			if (Count % 2 == 0)
			{
				if (ret_count >= Count / 2)
				{
					printf("0\n");
					flag = true;
					break;
				}
			}
			else
			{
				if (ret_count > Count / 2)
				{
					printf("0\n");
					flag = true;
					break;
				}
			}
			
			for (int j = 0; j < Count; ++j)
			{
				if(initcards[j].frontCard == cards[i].Color)
					continue;
				else
				{
					if (initcards[j].backCard == cards[i].Color)
						ret_count++;
				}
				if (Count % 2 == 0)
				{
					if (ret_count >= Count / 2)
					{
						printf("%d\n", ret_count - cards[i].num);
						flag = true;
						break;
					}
				}
				else
				{
					if (ret_count > Count / 2)
					{
						printf("%d\n", ret_count - cards[i].num);
						flag = true;
						break;
					}
				}
			}
			if (flag == true)
				break;
		}
		if (flag == false)
		{
			int ret = initcards[0].backCard;
			int ret_num = 1;
			for (int i = 1; i < Count; ++i)
			{
				if (initcards[i].backCard == ret)
					ret_num++;
				else
					ret_num--;
				if (ret_num < 0)
				{
					ret = initcards[i].backCard;
					ret_num = 1;
				}
			}
			ret_num = 0;
			for (int i = 0; i < Count; ++i)
			{
				if (initcards[i].backCard == ret)
					ret_num++;
			}
			if (Count % 2 == 0)
			{
				if (ret_num >= Count / 2)
					printf("%d", ret_num);
				else
					printf("-1\n");
			}
			else
			{
				if (ret_num > Count / 2)
					printf("%d", ret_num);
				else
					printf("-1\n");
			}
		}	
	}
	return 0;
}