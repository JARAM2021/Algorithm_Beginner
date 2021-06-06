#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;	// txt Ŀ��
	int pp = 0;	// pat Ŀ��
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			++pt;
			++pp;
		}
		else
		{
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	if (pat[pp] == '\0')
		return pt - pp;
	return -1;
}

int bf_matchr(const char txt[], const char pat[])
{
	int pt = 0;	// txt Ŀ��
	int pp = 0;	// pat Ŀ��
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			++pt;
			++pp;
		}
		else
		{
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	if (pat[pp] == '\0')
		return pt - pp + strlen(pat) - 1;
	return -1;
}

int main()
{
	int idx;
	char s1[256];	// �ؽ�Ʈ
	char s2[256];	// ����
	puts("���Ʈ-���� ��");
	printf("�ؽ�Ʈ: ");
	scanf("%s", s1);
	printf("����: ");
	scanf("%s", s2);

	idx = bf_matchr(s1, s2);

	if (idx == -1)
		printf("�ؽ�Ʈ�� ������ �����ϴ�.\n");
	else
		printf("%d��° ���ں��� �Ųٷ� match�մϴ�.\n", idx + 1);

	return 0;
}