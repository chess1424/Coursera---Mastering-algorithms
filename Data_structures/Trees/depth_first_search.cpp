#include <iostream>

using namespace std;

typedef struct node{
  node *left = NULL;
  node *right = NULL;
  int value;
}node;

void dfs(node *tree)
{
  if(!tree) return;

  cout << tree -> value;
  dfs(tree -> left);
  dfs(tree -> right);
}

int main()
{
  node* tree = NULL;

  node *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;

  n1 = new node; n1->value = 1;
  n2 = new node; n2->value = 2;
  n3 = new node; n3->value = 3;
  n4 = new node; n4->value = 4;
  n5 = new node; n5->value = 5;
  n6 = new node; n6->value = 6;
  n7 = new node; n7->value = 7;
  n8 = new node; n8->value = 8;

  tree       =  n1;
  tree->left = n1;
  n1->left   = n2;
  n1->right  = n3;
  n2->left   = n4;
  n2->right  = n5;
  n4->left   = n8;
  n3->left   = n6;
  n3->right  = n7;

  /*
          n1
      n2      n3
    n4  n5  n6  n7
  n8
  */

 dfs(tree);// print 1 2 4 8 5 3 6 7

  return 0;
}