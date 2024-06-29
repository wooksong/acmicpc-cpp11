#include <iostream>
#include <vector>

constexpr size_t DEFAULT_MAX_SIZE = 100001;
class MaxHeap
{
  public:
  MaxHeap (size_t max_size = DEFAULT_MAX_SIZE);
  bool is_empty ();
  size_t get_nums_data ();
  size_t get_parent_idx_of (size_t idx);
  size_t get_lchild_idx_of (size_t idx);
  size_t get_rchild_idx_of (size_t idx);
  bool has_lchild (size_t idx);
  bool has_rchild (size_t idx);
  void insert (int n);
  int pop ();

  private:
  size_t m_size;
  std::vector<int> m_data;
  void heapify_up ();
  void heapify_down ();
};

MaxHeap::MaxHeap (size_t max_size)
{
  this->m_size = 0;
  this->m_data = std::vector<int> (max_size, -1);
}
bool
MaxHeap::is_empty ()
{
  return (this->get_nums_data () == 0 ? true : false);
}
size_t
MaxHeap::get_nums_data ()
{
  return this->m_size;
}
size_t
MaxHeap::get_parent_idx_of (size_t idx)
{
  return (idx - 1) / 2;
}
size_t
MaxHeap::get_lchild_idx_of (size_t idx)
{
  return idx * 2 + 1;
}
size_t
MaxHeap::get_rchild_idx_of (size_t idx)
{
  return idx * 2 + 2;
}

bool
MaxHeap::has_lchild (size_t idx)
{
  return (this->get_lchild_idx_of (idx) < this->get_nums_data ());
}

bool
MaxHeap::has_rchild (size_t idx)
{
  return (this->get_rchild_idx_of (idx) < this->get_nums_data ());
}

void
MaxHeap::insert (int n)
{
  this->m_data[this->m_size++] = n;
  this->heapify_up ();
}

int
MaxHeap::pop ()
{
  int popped;

  if (this->is_empty ()) {
    return 0;
  }

  popped = this->m_data[0];
  this->m_size--;
  this->m_data[0] = -1;
  this->heapify_down ();

  return popped;
}

void
MaxHeap::heapify_up ()
{
  size_t idx;

  if (this->get_nums_data () == 1)
    return;

  idx = this->m_size - 1;
  while (idx != 0) {
    if (this->m_data[idx] < this->m_data[this->get_parent_idx_of (idx)]) {
      break;
    }
    std::swap (this->m_data[idx], this->m_data[this->get_parent_idx_of (idx)]);
    idx = this->get_parent_idx_of (idx);
  }
}

void
MaxHeap::heapify_down ()
{
  size_t idx;
  size_t r_idx, c_idx;

  if (this->is_empty ())
    return;

  idx = 0;
  std::swap (this->m_data[idx], this->m_data[this->get_nums_data ()]);

  while (this->has_lchild (idx)) {
    c_idx = this->get_lchild_idx_of (idx);
    r_idx = this->get_rchild_idx_of (idx);

    if (this->has_rchild (idx) && this->m_data[c_idx] < this->m_data[r_idx])
      c_idx = r_idx;

    if (this->m_data[c_idx] > this->m_data[idx]) {
      std::swap (this->m_data[idx], this->m_data[c_idx]);
    } else {
      break;
    }

    idx = c_idx;
  }
}

int
main ()
{
  MaxHeap mh;
  int N;

  // freopen("input.txt", "r", stdin);
  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int n;
    std::cin >> n;
    if (n == 0) {
      std::cout << mh.pop () << "\n";
    } else {
      mh.insert (n);
    }
  }
  return 0;
}
