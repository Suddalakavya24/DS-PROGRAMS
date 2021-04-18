#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
      int data;
      struct node *next;
} node;
node *front = NULL;
node *rear = NULL;
void enqueue();
int dequeue();
void display();
int main()
{
      int choice = 0, x;
      display();

      while (choice != 4)
      {
            printf("\nChoose one of the options:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Quit\n");
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
      printf("Enter the element you want to insert\n");
      scanf("%d", &x);
      node *temp;
      temp = (node *)malloc(sizeof(node *));
      if (front == NULL && rear == NULL)
      {
            temp->data = x;
            temp->next = NULL;
            front = temp;
            rear = temp;
      }
      else
      {
            temp->data = x;
            rear->next = temp;
            temp->next = NULL;
            rear = temp;
      }
}
int dequeue()
{
      int x;
      node *temp;
      if (front == NULL && rear == NULL)
      {
            printf("Queue is empty\n");
      }
      else if (front == rear)
      {
            x = front->data;
            temp = front;
            front = NULL;
            rear = NULL;
            free(temp);
            return x;
      }
      else
      {
            x = front->data;
            temp = front;
            front = front->next;
            free(temp);
            return x;
      }
}

void display()
{
      node *q = front;
      if (front == NULL && rear == NULL)
      {
            printf("Queue is empty\n");
      }
      else
      {
            printf("Current elements in the queue\n");
            while (q != NULL)
            {
                  printf("%d\t", q->data);
                  q = q->next;
            }
      }
}
