#include <stdio.h>
int top = -1;
int stack[100];
int pop()
{
      if (top == -1)
      {
            printf("No elements to pop\n ");
      }
      else
      {
            int x = stack[top];
            top = top - 1;
            return x;
      }
}
void push(int x)
{
      if (top >= 100)
      {
            printf("No space to push\n");
      }
      else
      {
            top = top + 1;
            stack[top] = x;
      }
}
int main()
{
      int n, a[100];
      printf("Enter the length of array\n");
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }
      for (int i = 0; i < n; i++)
      {
            push(a[i]);
      }
      printf("Elements after reversing are:\n");
      for (int i = 0; i < n; i++)
      {
            int x = pop();
            a[i] = x;
            printf("%d ", a[i]);
      }
      return 0;
}
