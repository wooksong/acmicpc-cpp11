#include <iostream>

using namespace std;

constexpr int MAX_LEN = 10;
constexpr int MAX_NUMS = 10000 * 10;

int cur_node = 0;

struct Node {
  string num;
  int next[MAX_LEN];

  void init ()
  {
    num = "";
    fill_n (next, MAX_LEN, -1);
  }
} nodes[MAX_NUMS];

inline Node *
get_node ()
{
  return &nodes[cur_node++];
}

int
main ()
{
  int t, n;
  bool valid;

  // freopen ("input.txt", "r", stdin);

  cin >> t;

  for (int i = 0; i < t; ++i) {
    cur_node = 0;
    cin >> n;

    for (int j = 0; j < MAX_NUMS; ++j) {
      nodes[j].init ();
    }

    Node *root = get_node ();
    valid = true;

    for (int j = 0; j < n; ++j) {
      Node *cur = root;
      string tmp;
      cin >> tmp;

      if (!valid)
        continue;

      for (char c : tmp) {
        int hash = c - '0';
        Node *next_node = nullptr;

        if (cur->next[hash] == -1) {
          cur->next[hash] = cur_node;

          next_node = get_node ();
        } else {
          next_node = &(nodes[cur->next[hash]]);
          if (!next_node->num.empty ()) {
            valid = false;
            break;
          }
        }
        cur = next_node;
      }

      cur->num = tmp;
      for (int k = 0; k < MAX_LEN; ++k) {
        if (cur->next[k] != -1) {
          valid = false;
        }
      }
    }

    if (valid) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
