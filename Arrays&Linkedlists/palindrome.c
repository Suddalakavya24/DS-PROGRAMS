#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
      int data;
      struct node *next;
} node;
node *Createlinkedlist(int n)
{
      node *head = NULL; //final linked list
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
void displaylist(node *head)
{
      node *q = head;
      while (q->next != NULL)
      {
            printf("%d->", q->data);
            q = q->next;
      }
      printf("%d", q->data);
}
node *reverse(node *head)
{
      node *prev, *curr;
      if (head != NULL)
      {
            prev = head;
            curr = head->next;
            head = head->next;
            prev->next = NULL;
            while (head != NULL)
            {
                  head = head->next;
                  curr->next = prev;
                  prev = curr;
                  curr = head;
            }
            head = prev;

            return head;
      }
}
int palindrome(node *head1, node *head2)
{
      node *q, *r;
      int k = 0;
      q = head1;
      r = head2;
      while (q != NULL && r != NULL)
      {
            if (q->data != r->data)
            {
                  k = 1;
                  break;
            }

            q = q->next;
            r = r->next;
      }
      return k;
}
int main()
{
      int m;
      node *head1;
      node *head2;
      printf("Enter the number of elements in list ");
      scanf("%d", &m);
      head1 = Createlinkedlist(m);
      printf("List is : ");
      displaylist(head1);
      head2 = reverse(head1);
      int k = palindrome(head1, head2);
      if (k != 1)
      {
            printf("\n1");
      }
      else
            printf("\n0");
}
