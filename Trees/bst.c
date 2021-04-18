#include <stdio.h>
#include <stdlib.h>
//Creation,Insertion,Deletion in BST
typedef struct trees
{
      int data;
      struct trees *rightchild, *leftchild;
} tree;
tree *newNode(int x)
{
      tree *t = (tree *)malloc(sizeof(tree));
      t->data = x;
      t->rightchild = NULL;
      t->leftchild = NULL;
      return t;
}
void inorder(tree *root)
{
      if (root != NULL)
      {
            inorder(root->leftchild);
            printf("%d\t", root->data);
            inorder(root->rightchild);
      }
}
tree *insertion(tree *root, int key)
{
      if (root == NULL)
      {
            return newNode(key);
      }
      if (key < root->data)
      {
            root->leftchild = insertion(root->leftchild, key);
      }
      else if (key > root->data)
      {
            root->rightchild = insertion(root->rightchild, key);
      }
      return root;
}
tree *Minvaluenode(tree *root)
{
      tree *curr = root;
      while (curr && curr->leftchild != NULL)
      {
            curr = curr->leftchild;
      }
      return curr;
}

tree *deletion(tree *root, int key)
{
      if (root == NULL)
      {
            return root;
      }
      if (key < root->data)
      {
            root->leftchild = deletion(root->leftchild, key);
      }
      else if (key > root->data)
      {
            root->rightchild = deletion(root->rightchild, key);
      }
      else
      {
            if (root->leftchild == NULL)
            {
                  tree *temp = root->rightchild;
                  free(root);
                  return temp;
            }
            else if (root->rightchild == NULL)
            {
                  tree *temp = root->leftchild;
                  free(root);
                  return temp;
            }

            tree *temp = Minvaluenode(root->rightchild);
            root->data = temp->data;
            root->rightchild = deletion(root->rightchild, temp->data);
      }
      return root;
}
int main()
{
      tree *root = newNode(12);
      root->leftchild = newNode(4);
      root->rightchild = newNode(20);
      root = insertion(root, 25);
      root = insertion(root, 1);
      inorder(root);
      printf("\n");
      root = deletion(root, 25);
      root = deletion(root, 4);
      inorder(root);
}
