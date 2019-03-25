#include <stdio.h>

int main()
{
	int t, n;
	int s, e;
	int delay = 0;
	int finish = 0;
	int i, j;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		finish = delay = 0;
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d %d", &s, &e);
			if (finish <= s)
				finish += e;
			else
			{
				delay += finish - s;
				finish += e + delay;
			}
		}
		printf("%d %d\n", delay / n, finish / n);
	}
	return 0;
}
