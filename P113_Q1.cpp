#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* --- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(���ʹ�) --- */
int search(int a[], int n, int key)
{
	int i = 0;
	a[n] = key;
	/*
	while (1)
	{
		if (a[i] == key)
			break;
		++i;
	}
	*/

	for (i = 0; i < n; ++i)
	{
		if (a[i] == key)
			break;
	}
	return i == n ? -1 : i;
}

int main()
{
	int i, nx, ky, idx;
	int* x;
	puts("���� �˻�(���ʹ�)");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = (int*)calloc(nx + 1, sizeof(int));
	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("�˻���: ");
	scanf("%d", &ky);

	idx = search(x, nx, ky);

	if (idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
	free(x);

	return 0;
}