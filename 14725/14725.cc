#include <iostream>
#include <map>

const int MAX_NUM_LAYERS = 20000;

using namespace std;

int cur_node = 1;

struct Node {
  string food;
  map<string, Node *> next_food;
} nodes[MAX_NUM_LAYERS];

static inline Node *
get_node ()
{
  Node *n = &nodes[cur_node++];

  return n;
}

Node *root = &nodes[0];

void
dfs (Node *n, int depth)
{
  for (int i = 1; i < depth; ++i) {
    cout << "--";
  }
  cout << (n->food.empty () ? "" : n->food + "\n");
  if (n->next_food.empty ())
    return;

  for (auto it = n->next_food.begin (); it != n->next_food.end (); ++it) {
    Node *cur = it->second;

    dfs (cur, depth + 1);
  }
}
int
main ()
{
  int N;
  int n_foods;

  root->food = string ("");

  // freopen ("input.txt", "r", stdin);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> n_foods;

    Node *cur = root;
    for (int j = 0; j < n_foods; ++j) {
      Node *next_node;
      string food;
      cin >> food;

      if (cur->next_food.find (food) == cur->next_food.end ()) {
        next_node = get_node ();
        next_node->food = food;
        cur->next_food[food] = next_node;
      } else {
        next_node = cur->next_food[food];
      }
      cur = next_node;
    }
  }

  dfs (root, 0);

  return 0;
}
