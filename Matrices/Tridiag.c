#include <stdio.h>
#include <stdlib.h>
int n, a[100];
void store(int row, int col, int x)
{
      if (row < 1 || row > n || col < 1 || col > n)
      {

            printf("Invalid position");
      }
      else
      {
            int diff = (row - col);
            switch (diff)
            {
            case 0:
                  a[n + row - 2] = x;
                  break;
            case 1:
                  a[row - 2] = x;
                  break;
            case -1:
                  a[2 * n + (row - 2)] = x;
                  break;
            default:
                  if (x != 0)
                        printf("Invalid element");
                  break;
            }
      }
}

int retrieve(int row, int col, int *x)
{
      int diff = row - col;
      if (row < 1 || row > n || col < 1 || col > n)
      {
            return 0;
      }
      else
      {

            switch (diff)
            {
            case 0:
                  *x = a[n + row - 2];
                  return 1;
                  break;
            case 1:
                  *x = a[row - 2];
                  return 1;
                  break;
            case -1:
                  *x = a[2 * n + (row - 2)];
                  return 1;
                  break;
            default:
                  *x = 0;
                  return 1;
                  break;
            }
      }
}
int main()
{
      int x;
      int ans;

      printf("Enter number of rows\n");
      scanf("%d", &n);
      printf("Enter contents of diagonal matrix\n");
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= n; j++)
            {
                  scanf("%d", &x);
                  store(i, j, x);
            }
      }
      printf("Contents of matrix are:\n");
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= n; j++)
            {
                  ans = retrieve(i, j, &x);
                  if (ans == 1)
                        printf("%d ", x);
                  else
                        printf("0");
            }
            printf("\n");
      }

      return 0;
}
