#include <stdio.h>
#define N 5
int dequeue[N];
int front = -1;
int rear = -1;
int Isempty()
{
      if (front == -1 && rear == -1)
      {
            return 1;
      }
      else
            return 0;
}
int Isfull()
{
      if (rear + 1 == front || rear == N - 1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
void Insert_beginning()
{
      int x;
      printf("Enter the element to u want to insert at the beg\n");
      scanf("%d", &x);
      if (Isfull() == 1)
      {
            printf("Queue is full\n");
      }
      else if (Isempty() == 1)
      {
            front = 0;
            rear = 0;
            dequeue[rear] = x;
            printf("Inserted successfully!\n");
      }
      else
      {
            front = (front - 1 + N) % N;
            dequeue[front] = x;
            printf("Inserted successfully!\n");
      }
}
void Insert_end()
{
      int x;
      printf("Enter the element to u want to insert at the end\n");
      scanf("%d", &x);
      if (Isempty() == 1)
      {
            front = 0;
            rear = 0;
            dequeue[rear] = x;
            printf("Inserted successfully!\n");
      }
      else if (Isfull() == 1)
      {
            printf("Queue is full\n");
      }
      else
      {
            rear = (rear + 1) % N;
            dequeue[rear] = x;
            printf("Inserted successfully!\n");
      }
}
void delete_front()
{
      int x;
      if (Isempty() == 1)
      {
            printf("Cannot delete as queue is empty\n");
      }
      else
      {
            x = dequeue[front];
            if (front == rear)
            {
                  front = -1;
                  rear = -1;
            }
            else
            {
                  front = (front + 1) % N;
            }
            printf("%d got deleted successfully!\n", x);
      }
}
void delete_end()
{
      int x;
      if (Isempty() == 1)
      {
            printf("Cannot delete as queue is empty\n");
      }
      else
      {
            x = dequeue[rear];
            if (front == rear)
            {
                  front = -1;
                  rear = -1;
            }
            else
            {
                  rear = (rear - 1 + N) % N;
            }

            printf("%d got deleted successfully!\n", x);
      }
}
int display()
{
      int i;
      printf("The elements in the queue are:\n");
      if (Isempty() == 1)
      {
            printf("Queueis empty\n");
      }
      else
      {
            for (i = front; i != rear; i = (i + 1) % N)
            {
                  printf("%d ", dequeue[i]);
            }
            printf("%d", dequeue[rear]);
      }
}
int main()
{
      int c;
      printf("__________DEQUEUE_________\n");
      do
      {
            printf("\nChoose one of the options:\n1.Insertion at beg\n2.Insertion at the end\n3.Deletion at beg\n4.Deltion at the end\n5.Display\n6.Exit\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                  Insert_beginning();
                  display();
                  break;
            case 2:
                  Insert_end();
                  display();
                  break;
            case 3:
                  delete_front();
                  display();
                  break;
            case 4:
                  delete_end();
                  display();
                  break;
            case 5:
                  display();
                  break;
            case 6:
                  printf("-----------Exiting----------");
                  break;
            }
      } while (c != 6);
}
