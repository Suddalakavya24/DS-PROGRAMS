#include <stdio.h>
char BT[100];
void root(char data)
{
      if (BT[0] != '\0')
      {
            printf("Root exists\n");
            printf("Do you want to modify?\n# - Yes\t\t0 -  No\n"); //# any non zero number
            int doModify;
            scanf("%d", &doModify);
            if (doModify)
            {
                  BT[0] = data;
            }
      }
      else
      {
            BT[0] = data;
      }
}
void leftChild(char data, int parent)
{
      if (BT[parent] == '\0')
      {
            printf("Parent doesn\'t exists\n");
      }
      else
      {
            BT[parent * 2 + 1] = data;
      }
}
void rightChild(char data, int parent)
{
      if (BT[parent] == '\0')
      {
            printf("Parent doesn\'t exists\n");
      }
      else
      {
            BT[parent * 2 + 2] = data;
      }
}
void displayBT()
{
      for (int i = 0; i < 32; i++)
      {
            if (BT[i] != '\0')
            {
                  printf(" %c ", BT[i]);
            }
            else
            {
                  printf(" - ");
            }
      }
}
void isPresent(int index)
{
      if (BT[index])
      {
            printf("Present at %d\tElement is : %c\n", index, BT[index]);
      }
      else
      {
            printf("Not Present at %d\n", index);
      }
}
void main()
{
      //Present at 1    Element is : B
      //Not Present at 7
      // A  B  C  D  E  F  G  -  -  -  -  H  I  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
      root('A');
      leftChild('B', 0);
      rightChild('C', 0);
      leftChild('D', 1);
      rightChild('E', 1);
      leftChild('F', 2);
      rightChild('G', 2);
      leftChild('H', 5);
      rightChild('I', 5);
      isPresent(1);
      isPresent(7);
      displayBT();
}
