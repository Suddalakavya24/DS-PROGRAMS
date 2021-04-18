// dikstras algorithm
#include <stdio.h>
#define inf 9999
#define maxi 100
void dijkstra(int G[maxi][maxi], int n, int startnode, int k)
{
      int max = n;
      int cost[max][max], distance[max], pred[max], visited[max], count, mindistance, nextnode, i, j;
      for (i = 0; i < n; i++)
      {
            for (j = 0; j < n; j++)
            {
                  if (G[i][j] == 0)
                  {
                        cost[i][j] = inf;
                  }
                  else
                  {
                        cost[i][j] = G[i][j];
                  }
            }
      }
      for (i = 0; i < n; i++)
      {
            distance[i] = cost[startnode][i];
            pred[i] = startnode;
            visited[i] = 0;
      }
      distance[startnode] = 0;
      visited[startnode] = 1;
      count = 1;
      while (count < n - 1)
      {
            mindistance = inf;
            for (i = 0; i < n; i++)
            {
                  if (distance[i] < mindistance && !visited[i])
                  {
                        mindistance = distance[i];
                        nextnode = i;
                  }
            }
            visited[nextnode] = 1;
            for (i = 0; i < n; i++)
            {
                  if (!visited[i])
                  {
                        if (mindistance + cost[nextnode][i] < distance[i])
                        {
                              distance[i] = mindistance + cost[nextnode][i];
                              pred[i] = nextnode;
                        }
                  }
            }

            count++;
      }
      /*for(i=0;i<n;i++){
      if(i!=startnode){
          printf("%d-%d\n",i,distance[i]);
      }
  }*/

      printf("%d\n", distance[k]);
}
int main()
{
      /* int G[5][5]={0,10,0,30,100,
                 10,0,50,0,0,
                 0,50,0,20,10,
                 30,0,20,0,60,
                 100,0,10,60,0};
    dijkstra(G,5,0);
   */
      int n, m, q;
      scanf("%d%d%d", &n, &m, &q);
      int G[n][n];
      int p, t, r;
      for (int i = 0; i < m; i++)
      {
            scanf("%d%d%d", &p, &t, &r);
            G[p][t] = r;
      }
      p = 0, t = 0;
      for (int i = 0; i < q; i++)
      {
            scanf("%d%d", &p, &t);
            dijkstra(G, n, p, t);
      }
      return 0;
}
