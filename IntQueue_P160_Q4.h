#pragma once

#ifndef ___IntQueue
#define ___IntQueue

typedef struct
{
	int max;		// ť�� �ִ� �뷮
	int num;		// ������ ��� ����
	int front;		// ����Ʈ
	int rear;		// ����
	int* que;		// ť �� �� ��ҿ� ���� ������
}IntQueue;

// ť �ʱ�ȭ
int Initialize(IntQueue* q, int max);

// ť�� �����͸� ��ť
int Enqueue(IntQueue* q, int x);

// ť�� �����͸� ��ť
int Dequeue(IntQueue* q, int* x);

// ť�� �����͸� ��ũ
int Peek(const IntQueue* q, int* x);

// ��� ������ ����
void Clear(IntQueue* q);

// ť�� �ִ� �뷮
int Capacity(const IntQueue* q);

// ť�� ����� ������ ����
int Size(const IntQueue* q);

// ť�� ��� �ִ°�?
int IsEmpty(const IntQueue* q);

// ť�� ���� á�°�?
int IsFull(const IntQueue* q);

// ť���� �˻�
int Search(const IntQueue* q, int x);

// ��� ������ ���
void Print(const IntQueue* q);

// ť ����
void Terminate(IntQueue* q);

// ������ ������ �˻�
int Search2(const IntQueue* q, int x);

#endif