#include <stdio.h>
#pragma warning(disable:4996)

int gcd(int x, int y)
{
	for (int g = x <= y ? x : y; g > 1; --g)
	{
		if (x % g == 0 && y % g == 0)
			return g;
	}
}

int main()
{
	int x, y;
	puts("�� ������ �ִ������� ���մϴ�.");
	printf("������ �Է��ϼ���: ");
	scanf("%d", &x);

	printf("������ �Է��ϼ���: ");
	scanf("%d", &y);

	printf("�ִ������� %d�Դϴ�. \n", gcd(x, y));

	return 0;
}