#include <stdlib.h>
#include <stdio.h>
void store(int *array, int n)
{
      printf("Enter diagonal elements : ");
      for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
}
void display(int **matrix, int n)
{
      for (int i = 0, j; i < n; i++)
      {
            for (j = 0; j < n; j++)
                  printf("%d ", matrix[i][j]);
            printf("\n");
      }
}
void main()
{
      int **matrix, *array, i, j, n;
      printf("Enter dimensions of matrix : ");
      scanf("%d", &n);
      matrix = (int **)calloc(n, sizeof(int *));
      array = (int *)calloc(n, sizeof(int));
      store(array, n);
      for (i = 0; i < n; i++)
      {
            matrix[i] = (int *)malloc(n * sizeof(int));
            for (j = 0; j < n; j++)
            {
                  if (i != j)
                        matrix[i][j] = 0;
                  else
                        matrix[i][j] = array[i];
            }
      }
      printf("Printing Diagonal matrix : \n");
      display(matrix, n);
}
