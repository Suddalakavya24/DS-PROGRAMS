//queue using array
#include <stdio.h>
void enqueue();
int dequeue();
void display();
int front = -1;
int rear = -1;
#define n 50
int a[n];
int main()
{
      int choice;
      int x;
      display();
      while (choice != 4)
      {
            printf("Choose one of the options:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Quit\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                  enqueue();
                  display();
                  break;
            case 2:
                  x = dequeue();
                  printf("%d got deleted\n", x);
                  display();
                  break;
            case 3:
                  display();
                  break;
            case 4:
                  printf("Thankyou\n");
                  break;
            }
      }
}
void enqueue()
{
      int x;
      printf("Enter the element which you want to insert\n");
      scanf("%d", &x);
      if (rear == n - 1)
      {
            printf("Queue is full\n");
      }
      else if (front == -1 && rear == -1)
      {
            front++;
      }
      rear++;
      a[rear] = x;
}
int dequeue()
{
      int x;
      if (front == -1 && rear == -1)
      {
            printf("No elements to delete\n");
      }
      else if (front == rear)
      {
            front = -1;
            rear = -1;
      }
      else
      {
            x = a[front];
            front++;
            return x;
      }
}
void display()
{
      printf("Current elements of queue:\n");
      if (front == -1)
      {
            printf("queue is empty\n");
      }
      else
      {
            for (int i = front; i <= rear; i++)
            {
                  printf("%d\t", a[i]);
            }
      }
      printf("\n");
}
