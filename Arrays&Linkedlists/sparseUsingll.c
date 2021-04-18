#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
      int row;
      int col;
      int value;
      struct node *link;
} sparse;
int m, n;
sparse *storeelements(sparse *h)
{
      int x;
      sparse *temp, *q;
      q = h;
      printf("Enter the row and col\n");
      scanf("%d%d", &m, &n);
      printf("Enter the elements of matrix\n");
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  scanf("%d", &x);
                  if (x != 0)
                  {
                        temp = (sparse *)malloc(sizeof(sparse));

                        temp->value = x;
                        temp->row = i;
                        temp->col = j;
                        temp->link = NULL;
                        if (q == NULL)
                        {
                              h = temp;
                              q = temp;
                        }
                        else
                        {
                              q->link = temp;
                              q = temp;
                        }
                  }
            }
      }
      return h;
}
void display(sparse *h, int l, int m, int n)
{
      if (l == 1)
      {
            printf("Elements of matrix 1:\n");
      }
      else
      {
            printf("Elements of matrix 2:\n");
      }
      sparse *q = h;
      if (q == NULL)
      {
            printf("All elements are zero\n");
      }
      else if (q->link == NULL)
      {
            printf("ROW\tCOL\tVAL\n");
            printf("%d\t%d\t%d\n", q->row, q->col, q->value);
      }
      else
      {
            printf("ROW\tCOL\tVAL\n");
            /* while(q!=NULL){
          printf("%d\t%d\t%d\n",q->row,q->col,q->value);
           q=q->link;*/
            for (int i = 0; i < m; i++)
            {
                  for (int j = 0; j < n; j++)
                  {
                        if (q->row == i && q->col == j && q->value != 0)
                        {
                              printf("%d\t%d\t%d\n", q->row, q->col, q->value);
                        }
                        else
                        {
                              printf("%d\t%d\t0\n", i, j);
                        }
                  }
            }
      }
}
int main()
{
      sparse *h1 = NULL;
      sparse *h2 = NULL;
      h1 = storeelements(h1);
      h2 = storeelements(h2);
      display(h1, 1, m, n);
      display(h2, 2, m, n);
}
