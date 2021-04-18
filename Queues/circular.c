#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void Insertion(int x)
{
      if ((rear + 1) % N == front)
      {
            printf("Queue is full\n");
            return;
      }
      else if (front == -1 && rear == -1)
      {
            front = 0;
      }
      rear = (rear + 1) % N;
      queue[rear] = x;
}
void deletion()
{
      if (front == -1)
      {
            printf("Queue is empty\n");
            return;
      }
      else if (front == rear)
      {
            front = -1;
            rear = -1;
      }
      else
      {
            front = (front + 1) % N;
      }
}
void display()
{
      if (front == -1 && rear == -1)
      {
            printf("Queue is empty\n");
      }
      else
      {
            int i;
            printf("Elements in the queue are:\n");
            for (i = front; i != rear; i = (i + 1) % N)
            {
                  printf("%d ", queue[i]);
            }
            printf("%d", queue[i]);
      }
}
int main()
{
      int c, x;
      do
      {
            printf("Choose any option:\n");
            printf("1.Insertion\n2.Deletion\n3.Display\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                  printf("Enter the element you want to insert:\n");
                  scanf("%d", &x);
                  Insertion(x);
                  display();
                  break;
            case 2:
                  deletion();
                  display();
                  break;
            case 3:
                  display();
                  break;
            }
            printf("\nWant to continue?(1/0)\n");
            scanf("%d", &c);
      } while (c != 0);
}
