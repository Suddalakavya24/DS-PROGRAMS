#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee
{
      int id;
      char name[20];
      char dept[5];
      float sal;
} emp;
typedef struct trees
{
      emp e;
      struct trees *leftchild, *rightchild;
} tree;
tree *newNode(int id, char name[30], char dept[5], float sal)
{
      tree *t = (tree *)malloc(sizeof(tree));
      t->e.id = id;
      strcpy(t->e.name, name);
      strcpy(t->e.dept, dept);
      t->e.sal = sal;
      t->rightchild = NULL;
      t->leftchild = NULL;
      return t;
}
void inorder(tree *root)
{
      if (root != NULL)
      {
            inorder(root->leftchild);
            printf("%d %s %s %f\n", root->e.id, root->e.name, root->e.dept, root->e.sal);
            inorder(root->rightchild);
      }
}
int c = 0;
void searchbelowkey(tree *root, int key)
{
      if (root != NULL)
      {
            searchbelowkey(root->leftchild, key);
            if (root->e.id < key)
                  c++;
            searchbelowkey(root->rightchild, key);
      }
}

tree *insertion(tree *root, int id, char name[30], char dept[5], float sal)
{
      if (root == NULL)
      {
            return newNode(id, name, dept, sal);
      }
      if (id < root->e.id)
      {
            root->leftchild = insertion(root->leftchild, id, name, dept, sal);
      }
      else if (id > root->e.id)
      {
            root->rightchild = insertion(root->rightchild, id, name, dept, sal);
      }
      return root;
}
tree *search(tree *root, int key)
{
      if (root == NULL || root->e.id == key)
            return root;
      if (key < root->e.id)
      {
            return search(root->leftchild, key);
      }
      else if (key > root->e.id)
      {
            return search(root->rightchild, key);
      }
}
int main()
{
      int n, id;
      char name[30], dept[5];
      float sal;
      tree *root = NULL;
      printf("Enter number of employees\n");
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
            printf("Employee %d: Enter id,name,dept,salary\n", i + 1);
            scanf("%d%s%s%f", &id, name, dept, &sal);
            root = insertion(root, id, name, dept, sal);
      }
      printf("\nInorder Traversal\n");
      inorder(root);
      searchbelowkey(root, 1500);
      printf("The number employees whose id is less than 1500:%d", c);
}
