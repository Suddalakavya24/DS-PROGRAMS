#include <stdio.h>
#include <stdlib.h>

struct sparse
{
      int row;
      int col;
      int value;
};
int store(struct sparse *tab, int m, int n)
{
      int s, count = 0;
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {

                  scanf("%d", &s);
                  if (s != 0)
                  {
                        count++;
                        tab = (struct sparse *)realloc(tab, count * sizeof(struct sparse));
                        tab[count - 1].row = i;
                        tab[count - 1].col = j;
                        tab[count - 1].value = s;
                  }
            }
      }
      return count;
}
void display(struct sparse *tab, int c)
{
      printf("\nROW\t\tCOL\t\tVAL\n");
      for (int i = 0; i < c; i++)
      {
            printf("%d\t\t%d\t\t%d\n", tab[i].row, tab[i].col, tab[i].value);
      }
}
int main()
{
      int m, n, count;
      printf("Enter the number of rows and columns:\n");
      scanf("%d%d", &m, &n);

      struct sparse *tab = (struct sparse *)malloc(0 * sizeof(struct sparse));
      count = store(tab, m, n);
      display(tab, count);
}
