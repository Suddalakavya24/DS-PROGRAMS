#include <stdio.h>
#include <ctype.h>
int top = -1;
#define Max_size 100
int stack[Max_size];
char postfix[Max_size];
void push(int);
int pop();
void Postfix(char[]);
int main()
{
      printf("Enter the postfix expression followed by a fullstop \n");
      for (int i = 0; i < Max_size; i++)
      {
            scanf("%c", &postfix[i]);
            if (postfix[i] == '.')
            {
                  break;
            }
      }
      Postfix(postfix);
      return 0;
}
void push(int x)
{
      if (top >= Max_size - 1)
      {
            printf("stack is full\n");
            return;
      }
      else
      {
            top = top + 1;
            stack[top] = x;
      }
}
int pop()
{
      if (pop == -1)
      {
            printf("No elements to pop\n");
            return;
      }
      else
      {
            int x = stack[top];
            top = top - 1;
            return x;
      }
}
void Postfix(char postfix[])
{
      char ch;
      int result;
      for (int i = 0; postfix[i] != '.'; i++)
      {
            ch = postfix[i];
            if (isdigit(ch))
            {
                  push(ch - '0');
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            {
                  int x = pop();
                  int y = pop();
                  switch (ch)
                  {
                  case '+':
                        result = x + y;
                        push(result);
                        break;
                  case '-':
                        result = x - y;
                        push(result);
                        break;
                  case '*':
                        result = x * y;
                        push(result);
                        break;
                  case '/':
                        result = x / y;
                        push(result);
                        break;
                  case '^':
                        result = 1;
                        for (i = 1; i <= y; i++)
                        {
                              result = result * x;
                        }
                        push(result);
                        break;
                  }
            }
      }
      printf("The value of postfix expression is : %d", pop());
}
