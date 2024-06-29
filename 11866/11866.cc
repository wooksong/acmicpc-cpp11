#include <iostream>
#include <vector>

typedef struct _node_t {
  uint32_t n;
  _node_t *prev;
  _node_t *next;
} node_t;

constexpr size_t MAX_NUM_NODES = 1000;

node_t nodes[MAX_NUM_NODES];
node_t *head = nullptr;
node_t *tail = nullptr;
size_t size = 0;

node_t *
get_node ()
{
  static size_t cur = 0;

  node_t *nd = &nodes[cur];
  nd->n = 0;
  nd->next = nullptr;
  nd->prev = nullptr;
  cur++;

  return nd;
}

void
push_back (node_t *nd)
{
  if (head == tail) {
    if (head == nullptr && size == 0) {
      head = nd;
      tail = nd;
    } else if (size == 1) {
      head->next = nd;
      nd->prev = head;
      tail = nd;
    }
  } else {
    tail->next = nd;
    nd->prev = tail;
    tail = nd;
  }
  size++;
}

uint32_t
remove (node_t *nd)
{
  uint32_t ret;

  ret = nd->n;
  if (size == 1) {
    head = nullptr;
    tail = nullptr;
  } else if (nd == head) {
    head = nd->next;
    head->prev = nullptr;
  } else if (nd == tail) {
    tail = nd->prev;
    tail->next = nullptr;
  } else {
    nd->prev->next = nd->next;
    nd->next->prev = nd->prev;
  }

  nd->n = 0;
  nd->next = nullptr;
  nd->prev = nullptr;
  size--;

  return ret;
}

int
main ()
{
  uint32_t N, K;
  node_t *tnode, *cur;

  std::cin >> N >> K;

  for (uint32_t i = 1; i < N + 1; ++i) {
    node_t *nd = get_node ();
    nd->n = i;

    push_back (nd);
  }

  uint32_t i = K - 1;
  cur = head;
  std::cout << "<";
  while (size > 0) {
    for (node_t *iter = cur; iter != nullptr; --i) {
      if (i == 0) {
        i = K - 1;
        tnode = iter;
        break;
      }
      if (iter == tail) {
        iter = head;
      } else {
        iter = iter->next;
      }
    }
    cur = tnode->next;
    if (cur == nullptr && size > 0) {
      cur = head;
    }
    uint32_t removed = remove (tnode);
    if (size == 0) {
      std::cout << removed << ">\n";
    } else {
      std::cout << removed << ", ";
    }
  }

  return 0;
}
