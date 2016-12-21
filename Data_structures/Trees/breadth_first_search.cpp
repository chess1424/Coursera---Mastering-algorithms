#include <iostream>
#include <queue>

using namespace std;


typedef struct node{
  node *left = NULL;
  node *right = NULL;
  int value;
}node;

queue<node*> q;


void bfs(node *tree)
{
  if(!tree) return;

  q.push(tree);

  while(!q.empty())
  {
    node* n = q.front();

    cout << n->value << " ";
    if(n->left) q.push(n->left);
    if(n->right) q.push(n->right);

    q.pop();
  }
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

 bfs(tree);// print 1 2 3 4 5 6 7 8

  return 0;
}