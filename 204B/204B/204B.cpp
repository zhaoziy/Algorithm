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
Card cards_Front[N];
Card cards_Back[N];

int comp(const void*a, const void*b)
{
	struct Card*c = (Card*)a;
	struct Card*d = (Card*)b;
	return d->num - c->num;
}
int comp1(const void*a, const void*b)
{
	struct InitCard*c = (InitCard*)a;
	struct InitCard*d = (InitCard*)b;
	return c->frontCard - d->frontCard;
}
int comp2(const void*a, const void*b)
{
	struct InitCard*c = (InitCard*)a;
	struct InitCard*d = (InitCard*)b;
	return c->backCard - d->backCard;
}

int main()
{
	int Count = 0;
	while (scanf("%d", &Count) != EOF)
	{
		for (int i = 0; i < Count; ++i)
		{
			int a = 0, b = 0;
			scanf("%d %d", &initcards[i].frontCard, &initcards[i].backCard);
		}
		int num_Front = 0;
		qsort(initcards, Count, sizeof(InitCard), comp1);
		int i = 0;
		while (i < Count)
		{
			cards_Front[num_Front].Color = initcards[i].frontCard;
			int begin = i, end = Count - 1;
			int mid = 0;
			int right = 0;
			while (begin < end)
			{
				mid = begin + (end - begin) / 2;
				if (initcards[mid].frontCard > cards_Front[num_Front].Color)
					end = mid - 1;
				else
					begin = mid + 1;
			}
			if (begin == end)
			{
				if (initcards[begin].frontCard == cards_Front[num_Front].Color)
					right = begin;
				else
					right = begin - 1;
			}
			else
				right = end;
			cards_Front[num_Front].num = right - i + 1;
			i = ++right;
			num_Front++;
		}
		qsort(cards_Front, num_Front, sizeof(Card), comp);

		int num_Back = 0;
		qsort(initcards, Count, sizeof(InitCard), comp2);
		i = 0;
		while (i < Count)
		{
			cards_Back[num_Back].Color = initcards[i].backCard;
			int begin = i, end = Count - 1;
			int mid = 0;
			int right = 0;
			while (begin < end)
			{
				mid = begin + (end - begin) / 2;
				if (initcards[mid].backCard > cards_Back[num_Back].Color)
					end = mid - 1;
				else
					begin = mid + 1;
			}
			if (begin == end)
			{
				if (initcards[begin].backCard == cards_Back[num_Back].Color)
					right = begin;
				else
					right = begin - 1;
			}
			else
				right = end;
			cards_Back[num_Back].num = right - i + 1;
			i = ++right;
			num_Back++;
		}
		qsort(cards_Back, num_Back, sizeof(Card), comp);

		if (Count % 2 == 0 && cards_Front[0].num >= Count / 2)
		{
			printf("0");
			break;
		}
		else if (Count % 2 == 1 && cards_Front[0].num > Count / 2)
		{
			printf("0");
			break;
		}

		bool flag = false;
		for (int i = 0; i < num_Front; ++i)
		{
			for (int j = 0; j < num_Back; ++j)
			{
				if (cards_Back[j].Color == cards_Front[i].Color)
				{
					if (Count % 2 == 0)
					{
						if (cards_Back[j].num + cards_Front[i].num >= Count / 2)
						{
							printf("%d\n", cards_Back[j].num - cards_Front[i].num);
							flag = true;
							break;
						}
					}
					else
					{
						if (cards_Back[j].num + cards_Front[i].num > Count / 2)
						{
							printf("%d\n", cards_Back[j].num - cards_Front[i].num + 1);
							flag = true;
							break;
						}
					}
				}
			}
			if (flag == true)
				break;
		}
		if (flag == true)
		{
			if (Count % 2 == 0 && cards_Front[i].num >= Count / 2)
			{
				printf("%d\n", Count / 2);
				break;
			}
			else if (Count % 2 == 1 && cards_Front[i].num > Count / 2)
			{
				printf("%d\n", Count / 2 + 1);
				break;
			}
		}
		else
			printf("-1");
	}
	return 0;
}