#include <stdio.h>
int stack[200], n, top = -1, choice = 0;
void pushValue();
void popValue();
void showstack();
void main()
{
      printf("Enter the number of elements in the stack ");
      scanf("%d", &n);
      while (choice != 4)
      {
            printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
            printf("\n Enter the choice \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
            {
                  pushValue();
                  break;
            }
            case 2:
            {
                  popValue();
                  break;
            }
            case 3:
            {
                  showstack();
                  break;
            }
            case 4:
            {
                  printf("Exit");
                  break;
            }
            default:
            {
                  printf(" Enter valid choice ");
            }
            };
      }
}

void pushValue()
{
      int value;
      if (top == n)
            printf("\n Overflow Occured!");
      else
      {
            printf("Enter the value?");
            scanf("%d", &value);
            top = top + 1;
            stack[top] = value;
      }
}

void popValue()
{
      if (top == -1)
            printf("\nUnderflow Occured!");
      else
            top = top - 1;
}
void showstack()
{
      if (top == -1)
      {
            printf("Stack is empty");
      }
      for (int i = top; i >= 0; i--)
      {
            printf("%d\n", stack[i]);
      }
}
