#include <cmath>
#include <iostream>
#include <vector>

class AbsHeap
{
  public:
  AbsHeap ();

  void insert (int n);
  int pop ();

  private:
  size_t m_size;
  std::vector<std::pair<int, int>> m_heap;

  bool has_rchild (size_t idx);
  bool has_lchild (size_t idx);
  size_t get_rchild_idx_of (size_t idx);
  size_t get_lchild_idx_of (size_t idx);
  size_t get_parent_idx_of (size_t idx);
  void heapify_up ();
  void heapify_down ();
};

AbsHeap::AbsHeap ()
{
  const size_t default_max_size = 100001;

  m_heap = std::vector<std::pair<int, int>> (default_max_size);
  m_size = 0;
}

void
AbsHeap::insert (int n)
{
  int n_abs = std::abs (n);

  m_heap[m_size++] = std::make_pair (n_abs, n);
  heapify_up ();
}

int
AbsHeap::pop ()
{
  std::pair<int, int> popped;

  if (m_size == 0) {
    return 0;
  }

  popped = m_heap[0];
  m_size--;

  heapify_down ();
  return popped.second;
}

bool
AbsHeap::has_lchild (size_t idx)
{
  return (get_lchild_idx_of (idx) < m_size);
}
bool
AbsHeap::has_rchild (size_t idx)
{
  return (get_rchild_idx_of (idx) < m_size);
}
size_t
AbsHeap::get_lchild_idx_of (size_t idx)
{
  return idx * 2 + 1;
}
size_t
AbsHeap::get_rchild_idx_of (size_t idx)
{
  return idx * 2 + 2;
}
size_t
AbsHeap::get_parent_idx_of (size_t idx)
{
  return (idx - 1) / 2;
}

void
AbsHeap::heapify_up ()
{
  size_t idx;
  size_t idx_p;

  if (m_size == 1)
    return;

  idx = m_size - 1;
  while (idx != 0) {
    idx_p = get_parent_idx_of (idx);
    if ((m_heap[idx_p].first > m_heap[idx].first)
        || ((m_heap[idx_p].first == m_heap[idx].first)
            && (m_heap[idx_p].second > m_heap[idx].second))) {
      std::swap (m_heap[idx_p], m_heap[idx]);
    } else {
      break;
    }

    idx = idx_p;
  }
}
void
AbsHeap::heapify_down ()
{
  size_t idx = 0;

  m_heap[idx] = m_heap[m_size];
  while (has_lchild (idx)) {
    size_t c_idx = get_lchild_idx_of (idx);

    if (has_rchild (idx)) {
      size_t r_idx = get_rchild_idx_of (idx);

      if ((m_heap[c_idx].first > m_heap[r_idx].first)
          || ((m_heap[c_idx].first == m_heap[r_idx].first)
              && (m_heap[c_idx].second > m_heap[r_idx].second))) {
        c_idx = r_idx;
      }
    }

    if ((m_heap[c_idx].first < m_heap[idx].first)
        || ((m_heap[c_idx].first == m_heap[idx].first)
            && (m_heap[c_idx].second < m_heap[idx].second))) {
      std::swap (m_heap[c_idx], m_heap[idx]);
    }

    idx = c_idx;
  }
}

int
main ()
{
  AbsHeap heap;
  int N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    int n;

    std::cin >> n;
    if (!n) {
      std::cout << heap.pop () << "\n";
    } else {
      heap.insert (n);
    }
  }

  return 0;
}
