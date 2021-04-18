#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
      int data;
      struct node *link;
} node;
node *h;
void create()
{
      int n, i;
      node *q;
      q = h;
      printf("No of nodes : ");
      scanf("%d", &n);
      for (i = 0; i < n; i++)
      {
            node *t = (node *)malloc(sizeof(node));
            scanf("%d", &t->data);
            t->link = NULL;
            if (q == NULL)
            {
                  h = t;
                  q = t;
            }
            else
            {
                  q->link = t;
                  q = t;
            }
            if (i == n - 1)
            {
                  t->link = h;
            }
      }
      q->link = h;
}
void insert_Begin()
{
      node *t = (node *)malloc(sizeof(node));
      printf("Enter node to insert infront : ");
      scanf("%d", &t->data);
      t->link = h;
      node *q = h;
      while (q->link != h)
      {
            q = q->link;
      }
      q->link = t;
      h = t;
}
void insert_InBetween()
{
      int pos, i = -1;
      node *q = NULL, *t = (node *)malloc(sizeof(node));
      q = h;
      printf("Enter position (aray indexing) : ");
      scanf("%d", &pos);
      printf("Enter element to be inserted : ");
      scanf("%d", &t->data);
      while (i < pos - 2)
      {
            q = q->link;
            i++;
      }
      t->link = q->link;
      q->link = t;
}
void insert_End()
{
      node *q, *t = (node *)malloc(sizeof(node));
      printf("Enter node to insert at the end : ");
      scanf("%d", &t->data);
      t->link = h;
      q = h;
      while (q->link != h)
      {
            q = q->link;
      }
      q->link = t;
}
void delete_Begin()
{
      node *t, *q;
      t = h;
      // h=h->link;
      q = h;
      while (q->link != h)
      {
            q = q->link;
      }
      q->link = h->link;
      printf("deleting at Beginning %d \n", h->data);
      h = h->link;
      free(t);
}
void delete_InBetween()
{
      int pos, i = 0;
      node *q = NULL;
      printf("Enter position to delete (array indexing) : ");
      scanf("%d", &pos);
      q = h;
      while (i < pos - 1)
      {
            q = q->link;
            i++;
      }
      node *t;
      t = q->link;
      q->link = q->link->link;
      printf("deleting In Between %d \n", t->data);
      free(t);
}
void delete_End()
{
      node *q, *t;
      q = h;
      while (q->link->link != h)
      {
            q = q->link;
      }
      t = q->link;
      q->link = h;
      printf("deleting at End %d \n", t->data);
      free(t);
}
void display()
{
      node *q;
      q = h;
      int i = 0;
      while (q->link != h)
      {
            printf("%d->", q->data);
            q = q->link;
      }
      printf("%d\n", q->data);
}
void main()
{
      int choice, c;
      h = NULL;
      printf("CIRCULAR LINKED LIST:\n");
      printf(" 1 Create circular Linked List\n");
      printf(" 2 Insertion At the Beginning\n");
      printf(" 3 Insertion In Between\n");
      printf(" 4 Insertion At the End\n");
      printf(" 5 Deletion At the Beginning\n");
      printf(" 6 Deletion In Between\n");
      printf(" 7 Deletion At the End\n");
      printf(" 8 Display\n");
      do
      {
            printf("Enter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                  create();
                  break;
            case 2:
                  insert_Begin();
                  break;
            case 3:
                  insert_InBetween();
                  break;
            case 4:
                  insert_End();
                  break;
            case 5:
                  delete_Begin();
                  break;
            case 6:
                  delete_InBetween();
                  break;
            case 7:
                  delete_End();
                  break;
            case 8:
                  display();
                  break;
            default:
                  exit(1);
            }
            printf("Want to try again\n");
            printf("1- Yes\t0 - No\n");
            scanf("%d", &c);
      } while (c);
}
