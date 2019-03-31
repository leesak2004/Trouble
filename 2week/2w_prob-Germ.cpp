#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[100][100];
queue<int> xq;
queue<int> yq;
int n;

void bfs()
{
	int nx[4] = { 0,0,-1,1 };
	int ny[4] = { -1,1,0,0 };
	int i, j, k, result = 0;
	while (1)
	{
		if (xq.empty() && yq.empty())
		{
			/*for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%5d ", arr[i][j]);
				}
				printf("\n");
			}*/
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					result = min(result, arr[i][j]);
					if (arr[i][j] == 0)
					{
						printf("-1\n");
						return;
					}
				}
			}
			printf("%d\n", -(result + 1));
			return;
		}
		for (i = 0; i < 4; i++)
		{
			int x = xq.front() + nx[i];
			int y = yq.front() + ny[i];
			if (x >= n || x < 0 || y >= n || y < 0)
				continue;
			else
			{
				if (arr[y][x] != 1 && arr[y][x] == 0)
				{
					arr[y][x] = arr[yq.front()][xq.front()] - 1;
					xq.push(x);
					yq.push(y);
				}
			}
		}
		xq.pop();
		yq.pop();
	}
}
int main()
{
	int t, m;
	int x, y;
	int i, j, k;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				scanf("%d", &arr[j][k]);

		for (j = 0; j < m; j++)
		{
			scanf("%d %d", &x, &y);
			arr[n-y-1][x] = -1;
			xq.push(x);
			yq.push(n - y - 1);
		}
		bfs();
	}
	return 0;
}
