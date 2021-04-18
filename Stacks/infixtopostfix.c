#include <stdio.h>
#include <ctype.h>
int top = -1;
int stack[100];
void push(char x)
{
      if (top >= 100)
      {
            printf("Stack is full\n");
      }
      else
      {
            top = top + 1;
            stack[top] = x;
      }
}
char pop()
{
      if (top == -1)
      {
            printf("No elements to pop out\n");
      }
      else
      {
            int k = stack[top];
            top = top - 1;
            return k;
      }
}
int precedence(char x)
{
      if (x == '(' || x == ')')
      {
            return 0;
      }
      else if (x == '+' || x == '-')
      {
            return 1;
      }
      else if (x == '*' || x == '/')
      {
            return 2;
      }
      else
            return -1;
}
int main()
{
      char exp[100];
      char c;
      printf("Enter the infix expression\n");
      scanf("%s", exp);
      char *infix;
      infix = exp;
      while (*infix != '\0')
      {
            if (isalnum(*infix))
                  printf("%c", *infix);
            else if (*infix == '(')
                  push('(');
            else if (*infix == ')')
            {
                  while ((c = pop()) != '(')
                  {
                        printf("%c", c);
                  }
            }
            else
            {
                  while (top != -1 & (precedence(stack[top]) >= precedence(*infix)))
                        printf("%c", pop());
                  push(*infix);
            }
            infix++;
      }
      while (top != -1)
      {
            printf("%c", pop());
      }

      return 0;
}
