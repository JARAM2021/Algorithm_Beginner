#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
	int to; // ���������
	int distance; // �Ÿ�
};

vector<node> vec[100001];
bool check[100001];
int v;
int cur, target_node, dist; // ������� ���� ���, ���� ������ �Ÿ��� ��Ÿ���� ���, �� ������ �Ÿ�
int farthest_node; // ������ ��忡�� ���� �� ���
int farthest_distance; // ������ ��忡�� ���� �� �Ÿ� �� �������� ����� ����

void DFS(int x, int dist)
{
	if (check[x])
		return;

	if (farthest_distance < dist)
	{
		farthest_distance = dist;
		farthest_node = x;
	}

	check[x] = true;

	for (int i = 0; i < vec[x].size(); ++i)
	{
		int y = vec[x][i].to;
		DFS(y, dist + vec[x][i].distance);
	}
}

int main()
{
	cin >> v;

	for (int i = 0; i < v; ++i)
	{
		cin >> cur;
		cin >> target_node;
		while (target_node != -1)
		{
			cin >> dist;
			vec[cur].push_back({ target_node, dist });
			cin >> target_node;
		}
	}

	DFS(1, 0); // ������ ��带 �������� �ؼ� ���� �� ��带 �����Ѵ�
	memset(check, 0, sizeof(check));
	DFS(farthest_node, 0);
	cout << farthest_distance << endl;

	return 0;
}