#include <stdio.h>
#include <stdlib.h>
void store(int *array, int n)
{
      printf("Enter elements of upper trangular matrix row wise : \n");
      for (int i = 0; i < n * (n + 1) / 2; i++)
            scanf("%d", &array[i]);
}
void display(int **matrix, int n)
{
      for (int i = 0, j; i < n; i++)
      {
            for (j = 0; j < n; j++)
                  printf("%d", matrix[i][j]);
            printf("\n");
      }
}
void main()
{
      int *array, **matrix, i, j, n, k = 0;
      printf("Enter dimensions of martix : ");
      scanf("%d", &n);
      matrix = (int **)malloc(n * sizeof(short int *));
      array = (int *)malloc((n * (n + 1) / 2) * sizeof(int));
      store(array, n);
      for (i = 0; i < n; i++)
      {
            matrix[i] = (int *)malloc(n * sizeof(int));
            for (j = 0; j < n; j++)
            {
                  if (j >= i)
                  {
                        matrix[i][j] = array[k];
                        k++;
                  }
                  else
                        matrix[i][j] = matrix[j][i];
            }
      }
      printf("Printing symmetric matrix : \n");
      display(matrix, n);
}
