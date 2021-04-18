#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
      int data;
      struct node *next;
} node;

node *Createlinkedlist(node *head, int n)
{
      //final linked list
      node *temp = NULL; //to create a temperorynode
      node *q = NULL;    //used for iterating through linkedklist
      for (int i = 0; i < n; i++)
      {
            temp = (node *)malloc(sizeof(node *));
            printf("Enter data:  ");
            scanf("%d", &(temp->data));
            temp->next = NULL;
            if (head == NULL)
            { //if head is still empty
                  head = temp;
            }
            else
            {
                  q = head;
                  while (q->next != NULL)
                  {
                        q = q->next;
                  }
                  q->next = temp;
            }
      }
      return head;
}
node *insert(node *head, int element)
{
      if (head == NULL)
      {
            node *m;
            m = (node *)malloc(sizeof(node *));
            m->data = element;
            m->next = NULL;
            head = m;
            return head;
      }
      else
      {
            node *m;
            node *l;
            l = head;
            m = (node *)malloc(sizeof(node *));
            m->data = element;
            m->next = NULL;
            while (l->next != NULL)
            {
                  l = l->next;
            }
            l->next = m;

            return head;
      }
}
void display(node *head)
{
      printf("The elements in the list are:\n");
      node *q = head;
      while (q->next != NULL)
      {
            printf("%d->", q->data);
            q = q->next;
      }
      printf("%d", q->data);
}
node *sortlist(node *head)
{
      node *current, *index;
      current = head;
      index = head;
      int temp;
      if (head == NULL)
      {
            printf("No elements to sort\n");
      }
      else
      {
            while (current != NULL)
            {
                  index = current->next;
                  while (index != NULL)
                  {
                        if (current->data > index->data)
                        {
                              temp = current->data;
                              current->data = index->data;
                              index->data = temp;
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }

      return head;
}
void merge(node *head1, node *head2)
{
      node *head3 = NULL;
      node *q, *r;
      q = head1;
      int value;
      r = head2;
      while (q != NULL && r != NULL)
      {
            if (q->data > r->data)
            {
                  value = r->data;
                  r = r->next;
            }
            else
            {
                  value = q->data;
                  q = q->next;
            }
            head3 = insert(head3, value);
      }
      while (q != NULL)
      {
            head3 = insert(head3, q->data);
            q = q->next;
      }
      while (r != NULL)
      {
            head3 = insert(head3, r->data);
            r = r->next;
      }
      display(head3);
}

int main()
{
      node *head1 = NULL;
      node *head2 = NULL;
      int x, y;
      printf("Enter the number of contents of list 1:\n");
      scanf("%d", &x);
      head1 = (Createlinkedlist(head1, x));
      sortlist(head1);
      display(head1);
      printf("\nEnter the number of contents of list 2:\n");
      scanf("%d", &y);
      head2 = (Createlinkedlist(head2, y));
      sortlist(head2);
      display(head2);
      printf("\nSorted Merged list is:\n");
      merge(head1, head2);
}
