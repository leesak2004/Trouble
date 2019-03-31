#include <stdio.h>

int b[50000];
int t, n;
int main()
{
    int i, j, k, cnt;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            cnt = 0;
            scanf("%d", &b[j]);
            if (j == 0)
                printf("0 ");
            if (j > 0)
            {
                for (k = j-1; k >= 0; k--)
                {
                    if (b[k] >= b[j])
                    {
                        printf("%d ", k + 1);
                        cnt++;
                        break;
                    }
                }
                if (cnt == 0)
                    printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}

