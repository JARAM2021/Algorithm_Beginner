#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
	int to; // ���������
	int distance; // �Ÿ�
};

vector<node> vec[10001];
bool check[10001];
int n;
int parent, child, dist;
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
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> parent >> child >> dist;
		vec[parent].push_back({ child, dist });
		vec[child].push_back({ parent, dist });
	}

	DFS(1, 0); // ������ ��带 �������� �ؼ� ���� �� ��带 �����Ѵ�

	memset(check, 0, sizeof(check));
	DFS(farthest_node, 0);
	cout << farthest_distance << endl;

	return 0;
}