#include <stdio.h>
#include <stdlib.h>
#define BT Tree
typedef struct node
{
      int data;
      struct node *leftChild, *rightChild;

} Tree;
Tree *createNode(int value)
{
      Tree *newNode;
      newNode = (Tree *)malloc(sizeof(Tree));
      newNode->leftChild = NULL;
      newNode->data = value;
      newNode->rightChild = NULL;

      return newNode;
}
void preOrderTraversal(Tree *root)
{
      if (root != NULL)
      {
            printf(" %d ", root->data);
            preOrderTraversal(root->leftChild);
            preOrderTraversal(root->rightChild);
      }
}
void postOrderTraversal(Tree *root)
{
      if (root != NULL)
      {
            postOrderTraversal(root->leftChild);
            postOrderTraversal(root->rightChild);
            printf(" %d ", root->data);
      }
}
void inOrderTraversal(Tree *root)
{
      if (root != NULL)
      {
            inOrderTraversal(root->leftChild);
            printf(" %d ", root->data);
            inOrderTraversal(root->rightChild);
      }
}
int front = -1;
int rear = -1;
#define sz 50
Tree *a[sz];
void push(Tree *x)
{
      if (rear == sz - 1)
      {
            //
      }
      else if (front == -1 && rear == -1)
      {
            front++;
      }
      a[++rear] = x;
}
Tree *pop()
{
      Tree *x;
      if (front == -1 && rear == -1)
      {
            //
      }
      else if (front == rear)
      {
            front = -1;
            rear = -1;
      }
      else
      {
            x = a[front];
            front++;
            return x;
      }
}
void levelOrder(Tree *root)
{
      if (root == NULL)
            return;
      Tree *current;
      push(root);
      push(NULL);
      while (rear - front > 0)
      {
            current = pop();
            if (current == NULL)
            {
                  push(NULL);
                  printf(" \n");
            }
            else
            {
                  if (current->leftChild)
                        push(current->leftChild);
                  if (current->rightChild)
                        push(current->rightChild);
                  printf("%d ", current->data);
            }
      }
}
int isLeaf(Tree *node)
{
      if (node->leftChild == NULL && node->rightChild == NULL)
      {
            return 1;
      }
      return 0;
}
int max(int a, int b)
{
      return (a > b) ? a : b;
}
int height(Tree *node)
{
      if (node == NULL || isLeaf(node))
      {
            return 0;
      }
      return max(height(node->leftChild), height(node->rightChild)) + 1;
}
Tree *CommonAncestor(Tree *root, Tree *p, Tree *q)
{
      if (root == NULL)
            return NULL;
      if (root == p || root == q)
            return root;
      Tree *l = CommonAncestor(root->leftChild, p, q);
      Tree *r = CommonAncestor(root->rightChild, p, q);
      if (l && r)
            return root;
      return l ? l : r;
}
void main()
{
      BT *root;
      root = createNode(1);
      root->leftChild = createNode(2);
      root->rightChild = createNode(3);
      root->rightChild->leftChild = createNode(4);
      root->rightChild->rightChild = createNode(5);
      preOrderTraversal(root);
      printf("\n");
      inOrderTraversal(root);
      printf("\n");
      postOrderTraversal(root);
      printf("\n");
      if (isLeaf(root->leftChild))
      {
            printf("Yes\n");
      }
      else
      {
            printf("No\n");
      }
      printf("Height of the tree is : %d\n", height(root));
      printf("Common Ancestor of 2 , 3 is %d\n", CommonAncestor(root, root->rightChild->leftChild, root->leftChild)->data);
      printf("Level order\n\n");
      levelOrder(root);
}
