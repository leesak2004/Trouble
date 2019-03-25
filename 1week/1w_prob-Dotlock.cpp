#include <stdio.h>
void find(int n, int q);
int arr[1000000];

void find(int n, int q)
{
	int i, j, k;
	int idx, s = 0, e = n;
	int find_num;
	for (i = 0; i < q; i++)
	{
		scanf("%d", &find_num);
		idx = n / 2;
		while(1)
		{
			if (arr[idx] == find_num)
			{
				printf("%d\n", idx + 1);
				break;
			}
			if (arr[idx] > find_num)
			{
				s = 0;
				e = idx;
				idx = (s + e) / 2;
			}
			else if (arr[idx] < find_num)
			{
				s = idx;
				e = n;
				idx = (s + e) / 2;
			}
		}
	}
}

int main()
{
	int t, n, q;
	int i, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &q);
		for (j = 0; j < n; j++)
			scanf("%d", &arr[j]);
		find(n, q);
	}
}
