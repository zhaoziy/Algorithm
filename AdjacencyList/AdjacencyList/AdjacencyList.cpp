// AdjacencyList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

typedef struct Node
{
	int dest;                    //�ڽӱߵĻ�ͷ������
	int weight;                    //Ȩֵ��Ϣ
	struct Node *next;            //ָ����һ���ڽӱ�
}Edge;                            //��������Ľṹ��

typedef struct
{
	DataType data;                //����һЩ���ݣ���������
	int sorce;                    //�ڽӱߵĻ�β������
	Edge *adj;                    //�ڽӱ�ͷָ��
}AdjHeight;                        //���������Ԫ�����͵Ľṹ��

typedef struct
{
	AdjHeight a[MaxVertices];    //�ڽӱ�����
	int numOfVerts;                //������
	int numOfEdges;                //�߸���
}AdjGraph;                        //�ڽӱ�ṹ��

int main()
{
    return 0;
}

