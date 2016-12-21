#include <iostream>
#include <vector>
using namespace std;

typedef struct node{
  vector<node*> children;
  int value;
}node;

vector<node*> set_of_nodes;

int get_max_height(node* root)
{
  if(root->children.size() == 0) return 0;
  int ans = -100;
  for(int i = 0; i < root->children.size(); i++)
    ans = max(ans, get_max_height(root->children[i]) + 1);
  return ans;
}

int main()
{
  int n, value_of_parent;
  node* root = NULL;

  cin >> n;

  for(int i = 0; i < n; i++)
  {
    node* new_node = new node;
    new_node->value = i;
    set_of_nodes.push_back(new_node);
  }

  for(int i = 0; i < n; i++)
  {
    cin >> value_of_parent;

    if(value_of_parent == -1)
      root = set_of_nodes[i];
    else
      set_of_nodes[value_of_parent]->children.push_back(set_of_nodes[i]);
  }

  cout << get_max_height(root) + 1<< endl;

  return 0;
}