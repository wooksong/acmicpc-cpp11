#include <iostream>
#include <vector>

struct Node {
  int key;

  Node *left;
  Node *right;

  Node ()
  {
    this->key = -1;
    this->left = nullptr;
    this->right = nullptr;
  }
};

constexpr int MAX_NUM_NODES = 10001;

std::vector<Node> nodes;
Node *root = nullptr;

void traverse_preorder (Node *n);
void traverse_postorder (Node *n);

void
insert (int key)
{
  static int num_nodes = 0;
  Node *n = &nodes[num_nodes++];
  Node *cur_node;

  n->key = key;

  if (!root) {
    root = n;
    return;
  }

  cur_node = root;
  while (cur_node) {
    if (cur_node->key > n->key) {
      if (!cur_node->left) {
        cur_node->left = n;
        break;
      }
      cur_node = cur_node->left;
    } else {
      if (!cur_node->right) {
        cur_node->right = n;
        break;
      }
      cur_node = cur_node->right;
    }
  }
}

int
main ()
{
  int key;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  nodes = std::vector<Node> (MAX_NUM_NODES);
  while (std::cin >> key) {
    if (std::cin.fail ())
      break;
    insert (key);
  }

  traverse_postorder (root);

  return 0;
}

void
traverse_postorder (Node *n)
{
  if (n->left) {
    traverse_postorder (n->left);
  }
  if (n->right) {
    traverse_postorder (n->right);
  }

  std::cout << n->key << "\n";
}

void
traverse_preorder (Node *n)
{
  std::cout << n->key << "\n";

  if (n->left) {
    traverse_preorder (n->left);
  }
  if (n->right) {
    traverse_preorder (n->right);
  }
}
