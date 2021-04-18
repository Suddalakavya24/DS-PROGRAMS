#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{
      int id;
      char name[10];
      float salary;
      char dept[10];
};
typedef struct node
{
      struct employee e;
      struct node *next;
      struct node *prev;
} node;
node *head = NULL;
node *head1 = NULL;
node *head2 = NULL;
node *q = NULL;
node *r = NULL, *s = NULL;
void createdll()
{
      node *temp;

      temp = (node *)malloc(sizeof(node));
      printf("\nEnter the id: \n");
      scanf("%d", &temp->e.id);
      printf("Enter the employee name: \n");
      scanf("%s", temp->e.name);
      printf("Enter the dept name :{CSE,ECE,EEE,MECH,CIVIL,IT}:\n");
      scanf("%s", temp->e.dept);
      printf("Enter the salary: \n");
      scanf("%f", &temp->e.salary);
      if (head == NULL)
      {

            temp->prev = NULL;
            temp->next = NULL;
            head = temp;
            q = temp;
      }
      else
      {
            q->next = temp;
            temp->prev = q;
            temp->next = NULL;
            q = temp;
      }
}
void display()
{

      node *q;
      q = head;
      while (q != NULL)
      {
            printf("Name:%s\nId:%d\nDept:%s\nSalary:%f\n", q->e.name, q->e.id, q->e.dept, q->e.salary);
            q = q->next;
      }
}
void createlist1(node *q)
{
      node *temp;
      temp = (node *)malloc(sizeof(node));

      if (head1 == NULL)
      {
            temp->prev = NULL;
            temp->next = NULL;
            strcpy(temp->e.name, q->e.name);
            temp->e.id = q->e.id;
            strcpy(temp->e.dept, q->e.dept);
            temp->e.salary = q->e.salary;
            r = temp;
            head1 = temp;
      }
      else
      {
            r->next = temp;
            temp->prev = r;
            temp->next = NULL;
            strcpy(temp->e.name, q->e.name);
            temp->e.id = q->e.id;
            strcpy(temp->e.dept, q->e.dept);
            temp->e.salary = q->e.salary;
            r = temp;
      }
}
void createlist2(node *q)
{
      node *temp;
      temp = (node *)malloc(sizeof(node));

      if (head2 == NULL)
      {
            temp->prev = NULL;
            temp->next = NULL;
            strcpy(temp->e.name, q->e.name);
            temp->e.id = q->e.id;
            strcpy(temp->e.dept, q->e.dept);
            temp->e.salary = q->e.salary;
            s = temp;
            head2 = temp;
      }
      else
      {
            s->next = temp;
            temp->prev = s;
            temp->next = NULL;
            strcpy(temp->e.name, q->e.name);
            temp->e.id = q->e.id;
            strcpy(temp->e.dept, q->e.dept);
            temp->e.salary = q->e.salary;
            s = temp;
      }
}

void displaylist1()
{
      node *q;
      q = head1;
      printf("\nEmployees in list 1(CSE/ECE/IT) are:\n");
      if (head1 == NULL)
      {
            printf("\nNo employees exist in list 1\n");
      }
      while (q != NULL)
      {
            printf("Name:%s\nId:%d\nDept:%s\nSalary:%f\n", q->e.name, q->e.id, q->e.dept, q->e.salary);
            q = q->next;
      }
}
void displaylist2()
{
      node *q;
      q = head2;
      printf("\nEmployees in list 2(EEE/MECH/CIVIL) are:\n");
      if (head2 == NULL)
      {
            printf("\nNo employees exist in list 2\n");
      }

      while (q != NULL)
      {
            printf("Name:%s\nId:%d\nDept:%s\nSalary:%f\n", q->e.name, q->e.id, q->e.dept, q->e.salary);
            q = q->next;
      }
}
void list()
{
      node *q = head;
      while (q != NULL)
      {
            if (strcmp(q->e.dept, "CSE") == 0 || strcmp(q->e.dept, "IT") == 0 || strcmp(q->e.dept, "ECE") == 0)
            {
                  createlist1(q);
            }
            else if (strcmp(q->e.dept, "EEE") == 0 || strcmp(q->e.dept, "MECH") == 0 || strcmp(q->e.dept, "CIVIL") == 0)
            {
                  createlist2(q);
            }
            q = q->next;
      }
}
void sortbysalary()
{
      node *p1, *p2 = NULL;
      node *t;
      t = (node *)malloc(sizeof(node));
      int swap;
      do
      {
            swap = 0;
            p1 = head;
            while (p1->next != p2)
            {
                  if (p1->e.salary > p1->next->e.salary)
                  {
                        t->e.salary = p1->e.salary;
                        strcpy(t->e.name, p1->e.name);
                        strcpy(t->e.dept, p1->e.dept);
                        t->e.id = p1->e.id;

                        p1->e.salary = p1->next->e.salary;
                        strcpy(p1->e.name, p1->next->e.name);
                        strcpy(p1->e.dept, p1->next->e.dept);
                        p1->e.id = p1->next->e.id;

                        p1->next->e.salary = t->e.salary;
                        strcpy(p1->next->e.name, t->e.name);
                        strcpy(p1->next->e.dept, t->e.dept);
                        p1->next->e.id = t->e.id;
                        swap = 1;
                  }
                  p1 = p1->next;
            }
            p2 = p1;
      } while (swap);
}
void displaynamestartswithS()
{
      node *q = head;
      printf("\nEmployees whose names start with s:\n");
      short b = 0;
      while (q != NULL)
      {
            if (strncmp(q->e.name, "s", 1) == 0 || strncmp(q->e.name, "S", 1) == 0)
            {
                  printf("Name:%s\nId:%d\nDept:%s\nSalary:%f\n", q->e.name, q->e.id, q->e.dept, q->e.salary);
                  b = 1;
            }
            q = q->next;
      }
      if (b == 0)
      {
            printf("\nNo employee exists with initial letter of their name as S\n");
      }
}
int main()
{
      int n, i = 0;
      printf("Enter the number of employees in the organisation:\n");
      scanf("%d", &n);
      printf("Enter the details of %d employees:\n", n);
      while (i < n)
      {
            createdll();
            i++;
      }
      printf("\nEmployee details are :\n");
      display();
      list();
      displaylist1();
      displaylist2();
      sortbysalary();
      printf("\nSalaries of employees sorted salary wise:\n");
      display();
      displaynamestartswithS();
}
