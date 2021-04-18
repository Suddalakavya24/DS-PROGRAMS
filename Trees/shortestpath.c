#include <stdio.h>
int n;
int arr[500][500], shortestpath[200][200];
int main()
{
      int n, m, q, u, v, w, p, r;
      scanf("%d %d %d", &n, &m, &q);
      int U[700], V[700];
      int i, j;
      for (i = 0; i < n; i++)
      {
            for (j = 0; j < n; j++)
            {
                  if (i == j)
                        arr[i][j] = 0;
                  else
                        arr[i][j] = -1;
            }
      }
      for (i = 0; i < m; i++)
      {
            scanf("%d %d %d", &u, &v, &w);
            arr[u][v] = w;
      }
      for (i = 0; i < q; i++)
      {
            scanf("%d %d", &U[i], &V[i]);
      }
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= n; j++)
            {
                  shortestpath[i][j] = arr[i][j];
            }
      }
      for (int k = 1; k < n; k++)
      {
            for (int i = 1; i <= n; i++)
            {
                  for (int j = 1; j <= n; j++)
                  {
                        if (shortestpath[i][k] == -1)
                              p = 999;
                        else if (shortestpath[k][j] == -1)
                              r = 999;
                        else if (shortestpath[i][k] == -1 && shortestpath[k][j] == -1)
                        {
                              p = 999;
                              r = 999;
                        }
                        else
                        {
                              p = shortestpath[i][k];
                              r = shortestpath[k][j];
                        }
                        if (shortestpath[i][j] > p + r)
                              shortestpath[i][j] = p + r;
                  }
            }
      }
      for (i = 0; i < q; i++)
      {
            printf("%d\n", shortestpath[U[i]][V[i]]);
      }
      return 0;
}
