#include <stdio.h>
#pragma warning(disable:4996)

int factorial(int n)
{
	int fac = 1;
	for (int i = n; i >= 1; --i)
		fac *= i;

	return fac;
}

int main()
{
	int x;
	printf("������ �Է��ϼ���: ");
	scanf("%d", &x);

	printf("%d! = %d \n", x, factorial(x >= 0 ? x : -x));

	return 0;
}