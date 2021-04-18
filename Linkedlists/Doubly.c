#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
      int data;
      struct node *next;
      struct node *prev;
} node;
node *head = NULL;
void insertion_beg(int x)
{
      node *temp;
      temp = (node *)malloc(sizeof(node));
      if (head == NULL)
      {
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = x;
            head = temp;
            printf("Inserted successfully!\n");
      }
      else
      {
            temp->data = x;
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
            printf("Inserted successfully!\n");
      }
}
void insertion_end(int x)
{
      node *temp;
      temp = (node *)malloc(sizeof(node));
      if (head == NULL)
      {
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = x;
            head = temp;
            printf("Inserted successfully!\n");
      }
      else
      {
            node *q = head;
            while (q->next != NULL)
            {
                  q = q->next;
            }
            q->next = temp;
            temp->prev = q;
            temp->next = NULL;
            temp->data = x;
            printf("Inserted successfully!\n");
      }
}
void insertion_bet(int x, int pos)
{
      node *q;
      q = head;
      node *temp;
      temp = (node *)malloc(sizeof(node));
      for (int i = 1; i < pos - 1; i++)
      {
            q = q->next;
      }
      temp->data = x;
      temp->next = q->next;
      temp->prev = q;
      q->next = temp;
      q->next->prev = temp;
      printf("Inserted successfully\n");
}
void deletion_beg()
{
      node *temp;
      if (head->next == NULL)
      {
            head = NULL;
            free(head);
            printf("Deleted successfully!\n");
      }
      else
      {
            temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
            printf("Deleted successfully!\n");
      }
}
void deletion_end()
{
      node *temp;
      if (head->next == NULL)
      {
            head = NULL;
            free(head);
            printf("Deleted successfully!\n");
      }
      else
      {
            node *q = head;
            while (q->next != NULL)
            {
                  q = q->next;
            }
            q->prev->next = NULL;
            free(q);
            printf("Deleted successfully!\n");
      }
}
void deletion_between(int pos)
{
      node *q, *t;
      q = head;
      int i = 1;
      for (i = 1; i < pos - 1; i++)
      {
            q = q->next;
      }
      t = q->next;
      q->next->next->prev = q;
      q->next = q->next->next;
      free(t);
      printf("Deleted successfully!\n");
}
void display()
{
      printf("The elements in the list are :\n");
      node *q;
      q = head;
      while (q != NULL)
      {
            printf("%d  ", q->data);
            q = q->next;
      }
}
void reversebytakingdata()
{
      node *q;
      q = head;
      printf("The elements in the reversed order are:\n");
      printf("Reversed list is :\n");
      while (q->next != NULL)
      {
            q = q->next;
      }
      while (q->prev != NULL)
      {
            printf("%d->", q->data);
            q = q->prev;
      }
      printf("%d", q->data);
}
void reversebytakingreference(node **headref)
{
      node *q, *curr;
      q = (node *)malloc(sizeof(node));
      curr = *headref;
      while (curr != NULL)
      {
            q = curr->prev;
            curr->prev = curr->next;
            curr->next = q;
            curr = curr->prev;
      }
      if (q != NULL)
      {
            *headref = q->prev;
      }
}
int main()
{
      int c, x, pos;

      do
      {
            printf("\nChoose one of the operations:\n1.Insertion at beginning\n2.Insertion at the end\n3.Insertion in the middle\n4.Deletion at beg\n5.Deletion at the end\n6.Deletion in the middle\n7.Display\n8.Display reversed list\n9.Rev by ref\n10.Exit\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                  printf("Enter the element you want to insert\n");
                  scanf("%d", &x);
                  insertion_beg(x);
                  display();
                  break;
            case 2:
                  printf("Enter the element you want to insert\n");
                  scanf("%d", &x);
                  insertion_end(x);
                  display();
                  break;
            case 3:
                  printf("Enter the element you want to insert\n");
                  scanf("%d", &x);
                  printf("Enter the position\n");
                  scanf("%d", &pos);
                  insertion_bet(x, pos);
                  display();
                  break;
            case 4:
                  deletion_beg();
                  display();
                  break;
            case 5:
                  deletion_end();
                  display();
                  break;
            case 6:
                  printf("Enter the position\n");
                  scanf("%d", &pos);
                  deletion_between(pos);
                  display();
                  break;
            case 7:
                  display();
                  break;
            case 8:
                  reversebytakingdata();
                  break;
            case 9:
                  reversebytakingreference(&head);
                  break;
            case 10:
                  printf("Exit\n");
                  break;
            default:
                  printf("Enter valid option\n");
            }

      } while (c != 10);
}
