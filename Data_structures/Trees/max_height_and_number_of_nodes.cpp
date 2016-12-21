#include <iostream>

using namespace std;

typedef struct node{
  node *left = NULL;
  node *right = NULL;
  int value;
}node;

int get_max_height(node* tree)
{
  if(!tree) return 0;

  return max(get_max_height(tree -> left) , get_max_height(tree -> right)) + 1;
}

int get_number_of_nodes(node* tree)
{
  if(!tree) return 0;

  return get_number_of_nodes(tree -> left) + get_number_of_nodes(tree -> right) + 1;
}

int main()
{
  node* tree = NULL;

  node *n1, *n2, *n3, *n4, *n5;

  n1 = new node;
  n2 = new node;
  n3 = new node;
  n4 = new node;
  n5 = new node;

  tree = n1;
  tree->left = n1;
  n1->left = n2;
  n2->left = n3;
  n3->left = n4;
  n4->left = n5;

  cout << get_max_height(tree) << endl; //print 5
  cout << get_number_of_nodes(tree) << endl; //print 5

  return 0;
}