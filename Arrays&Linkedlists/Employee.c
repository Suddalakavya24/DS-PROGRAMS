#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{
      int id;
      char name[40];
      char dept[20];
      float salary;
};
typedef struct node
{
      struct employee e;
      struct node *next;
} node;
int array[6] = {0, 0, 0, 0, 0, 0};
node *head;
void Createemplist(int);
void displaydetails();
void Salgreater();
node *sortlist(node *);
int k;
int main()
{
      printf("Enter the number of employees in the organization\n");
      scanf("%d", &k);
      Createemplist(k);
      displaydetails(head);
      head = sortlist(head);
      displaydetails(head);
      printf("Details of employees whose salary is greater than 20000\n\n");
      Salgreater();
}
void Createemplist(int k)
{
      node *temp, *p;
      p = head;
      int i = 0;
      while (i < k)
      {
            temp = (node *)malloc(sizeof(node));
            printf("Enter the id: ");
            scanf("%d", &temp->e.id);
            printf("Enter the employee name: ");
            scanf("%s", temp->e.name);
            printf("Enter the dept name :{CSE,ECE,EEE,MECH,CIVIL,IT}");
            scanf("%s", temp->e.dept);
            printf("Enter the salary: ");
            scanf("%f", &temp->e.salary);
            if (head == NULL)
            {
                  head = temp;
                  p = temp;
            }
            else
            {
                  p->next = temp;
                  p = temp;
            }
            i++;
            if (i == k)
            {
                  p->next = NULL;
                  break;
            }
      }
}
void displaydetails()
{
      node *temp;
      temp = head;
      while (temp != NULL)
      {
            printf("Employee ID :  %d\tEmployee name: %s\tEmployee dept: %s\tEmp salary: %f\n", temp->e.id, temp->e.name, temp->e.dept, temp->e.salary);
            temp = temp->next;
      }
}
node *sortlist(node *head)
{
      node *current, *index;
      current = head;
      index = head;
      node *temp;
      temp = (node *)malloc(sizeof(node));
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
                        if (current->e.salary > index->e.salary)
                        {
                              temp->e.salary = current->e.salary;
                              strcpy(temp->e.dept, current->e.dept);
                              strcpy(temp->e.name, current->e.name);
                              temp->e.id = current->e.id;
                              current->e.salary = index->e.salary;
                              strcpy(current->e.dept, index->e.dept);
                              strcpy(current->e.name, index->e.name);
                              current->e.id = index->e.id;
                              index->e.salary = temp->e.salary;
                              strcpy(index->e.dept, temp->e.dept);
                              strcpy(index->e.name, temp->e.name);
                              index->e.id = temp->e.id;
                        }
                        index = index->next;
                  }
                  current = current->next;
            }
      }
      printf("Sorted successfully based on salaries!\n");
      return head;
}
void Salgreater()
{
      int c = 0;
      node *p = head;
      c = c + 1;
      node *temp;
      while (p != NULL)
      {
            c = c + 1;
            if (p->e.salary > 20000 && strcmp(p->e.dept, "CSE") == 0)
            {
                  array[0]++;
            }
            else if (p->e.salary > 20000 && strcmp(p->e.dept, "ECE") == 0)
            {
                  array[1]++;
            }
            else if (p->e.salary > 20000 && strcmp(p->e.dept, "EEE") == 0)
            {
                  array[2]++;
            }
            else if (p->e.salary > 20000 && strcmp(p->e.dept, "MECH") == 0)
            {
                  array[3]++;
            }
            else if (p->e.salary > 20000 && strcmp(p->e.dept, "CIVIL") == 0)
            {
                  array[4]++;
            }
            else if (p->e.salary > 20000 && strcmp(p->e.dept, "IT") == 0)
            {
                  array[5]++;
            }
            p = p->next;
            c = c + 19;
      }

      printf("No. of employees in CSE department whose salary is greater then 20000 is %d\n", array[0]);
      printf("No. of employees in ECE department whose salary is greater then 20000 is %d\n", array[1]);
      printf("No. of employees in EEE department whose salary is greater then 20000 is %d\n", array[2]);
      printf("No. of employees in MECH department whose salary is greater then 20000 is %d\n", array[3]);
      printf("No. of employees in CIVIL department whose salary is greater then 20000 is %d\n", array[4]);
      printf("No. of employees in IT department whose salary is greater then 20000 is %d\n", array[5]);
      printf("Time complexity is dependent on no. of nodes(n)  created in linked list-(20n+1) : %d", 20 * k + 7);
}
