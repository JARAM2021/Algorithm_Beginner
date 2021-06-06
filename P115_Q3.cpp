#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int search_idx(const int a[], int n, int key, int idx[])
{
	int idx_i = 0;
	int num = 0;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == key)
		{
			idx[idx_i++] = i;
			++num;
		}
	}

	if (num == 0)
		return -1;
	return num;
}

int main()
{
	int i, nx, ky, num;
	int* x;
	int* idx_array;

	puts("���� �˻�(���ʹ�)");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = (int*)calloc(nx + 1, sizeof(int));
	idx_array = (int*)calloc(nx + 1, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("�˻���: ");
	scanf("%d", &ky);

	num = search_idx(x, nx, ky, idx_array);

	printf("\n");
	if (num == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
	{
		printf("�迭���� �� %d���� %d�� ������ \n", num, ky);
		printf("��ġ�� ");
		for (int i = 0; i < num; ++i)
			printf("%d ", idx_array[i]);
		printf("�Դϴ�. \n");
	}
	free(x);
	free(idx_array);
	return 0;
}