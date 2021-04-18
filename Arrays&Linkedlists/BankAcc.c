#include <stdio.h>
#include <stdlib.h>
struct bank
{
      int accnum;
      char accname[40];
      float balance;
};
typedef struct node
{
      struct bank b;
      struct node *next;
} node;
node *head;
void Createbankacclist();
void displaydetails();
void withdraw();
void deposit();
void acc_deletion();
int main()
{
      head = NULL;
      printf("Enter account details \n");
      Createbankacclist();
      displaydetails();
      int choice = -1;
      //withdraw();
      //deposit();
      // acc_deletion();
      // displaydetails();
      while (choice != 4)
      {
            printf("Select one of the operations:\n1.DEPOSIT\n2.WITHDRAW\n3.DELETE_ACCOUNT\n4.EXIT\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                  deposit();
                  break;
            case 2:
                  withdraw();
                  break;
            case 3:
                  acc_deletion();
                  break;
            case 4:
                  printf("EXIT\n");
                  break;
            default:
                  printf("Entered invalid option\n");
            }
      }
      return 0;
}
void Createbankacclist()
{
      node *temp, *p;
      p = head;
      int i = 0;
      while (i < 5)
      {
            temp = (node *)malloc(sizeof(node));
            printf("Enter the account number: ");
            scanf("%d", &temp->b.accnum);
            printf("Enter the account name: ");
            scanf("%s", temp->b.accname);
            printf("Enter the balance amount: ");
            scanf("%f", &temp->b.balance);
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
            if (i == 5)
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
            printf("Bank Account no. :  %d\tBank Account name: %s\tBank Balance: %f\n", temp->b.accnum, temp->b.accname, temp->b.balance);
            temp = temp->next;
      }
}
void withdraw()
{
      float amt;
      int num;
      printf("Enter your account number to withdraw amount\n");
      scanf("%d", &num);
      printf("Enter the amount you want to withdraw\n");
      scanf("%f", &amt);
      node *q;
      q = head;
      while (q != NULL)
      {
            if (q->b.accnum == num)
            {
                  if (amt <= q->b.balance)
                  {
                        printf("Amount withdrawn successfully!\n");
                        q->b.balance = (q->b.balance - amt);
                        printf("Current account details of account number: %d are:\nAccount name: %s\nBalance : %f\n", q->b.accnum, q->b.accname, q->b.balance);
                  }
                  else
                  {
                        printf("No sufficient amount to withdraw\n");
                  }
            }
            q = q->next;
      }
}
void deposit()
{
      float amt;
      int num;
      printf("Enter your account number to deposit amount\n");
      scanf("%d", &num);
      printf("Please enter the amount you want to deposit\n");
      scanf("%f", &amt);
      node *q;
      q = head;
      while (q != NULL)
      {
            if (q->b.accnum == num)
            {
                  q->b.balance = q->b.balance + amt;
                  printf("Amount deposited successfully!\n");
                  printf("Current account details of account number: %d are:\nAccount name: %s\nBalance : %f\n", q->b.accnum, q->b.accname, q->b.balance);
            }
            q = q->next;
      }
}
void acc_deletion()
{
      int num;
      node *temp;
      printf("Enter your account number to delete your account\n");
      scanf("%d", &num);
      node *q;
      q = head;
      while (q != NULL)
      {
            if (q->next->b.accnum == num)
            {
                  temp = q->next;
                  q->next = q->next->next;
                  free(temp);
                  break;
            }
            else if (q->b.accnum == num)
            {
                  temp = q;
                  q = q->next;
                  free(temp);
                  break;
            }
            q = q->next;
      }
      printf("Account has deleted successfully\n");
}
