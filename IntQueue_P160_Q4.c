#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

// ť �ʱ�ȭ
int Initialize(IntQueue* q, int max)
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
	if ((q->que = (int*)calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

// ť�� �����͸� ��ť
int Enqueue(IntQueue* q, int x)
{
	if (q->num >= q->max)
		return -1;
	else
	{
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}

// ť�� �����͸� ��ť
int Dequeue(IntQueue* q, int* x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

// ť�� �����͸� ��ũ
int Peek(const IntQueue* q, int* x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

// ��� ������ ����
void Clear(IntQueue* q)
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}

// ť�� �ִ� �뷮
int Capacity(const IntQueue* q)
{
	return q->max;
}

// ť�� ����� ������ ����
int Size(const IntQueue* q)
{
	return q->num;
}

// ť�� ��� �ִ°�?
int IsEmpty(const IntQueue* q)
{
	return q->num <= 0;
}

// ť�� ���� á�°�?
int IsFull(const IntQueue* q)
{
	return q->num >= q->max;
}

// ť���� �˻�
int Search(const IntQueue* q, int x)
{
	int i, idx;

	for (i = 0; i < q->num; ++i)
	{
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

// ��� ������ ���
void Print(const IntQueue* q)
{
	int i;
	for (i = 0; i < q->num; ++i)
		printf("%d ", q->que[(i + q->front) % q->max]);
	putchar('\n');
}

// ť ����
void Terminate(IntQueue* q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = 0;
	q->num = 0;
	q->front = 0;
	q -> rear = 0;
}

// ������ �����͸� �˻�
int Search2(const IntQueue* q, int x)
{
	int idx;
	int i = q->front;
	int times = 0;

	while (times < q->num)
	{
		if (q->que[i] == x)
		{
			return times;
		}
		i = (i + 1) % q->num;
		++times;
	}

	
	return -1;
}