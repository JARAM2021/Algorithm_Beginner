#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/* 버블 정렬 */
void bubble(int a[], int n)
{
	int i, j;

	for (i = n - 1; i > 0; --i)
	{
		for (j = 1; j <= i; ++j)
		{
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
		}
	}
}

int main()
{
	int i, nx;
	int* x;

	puts("버블 정렬");
	printf("요소 개수: ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] = ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; ++i)
		printf("x[%d] = %d \n", i, x[i]);

	free(x);

	return 0;
}