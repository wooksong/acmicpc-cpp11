#include <iostream>

constexpr int MAX_NUM_DATA = 100001;

class MinHeap {
  private:
    int m_data[MAX_NUM_DATA];
    int m_size;
    void heapify_up();
    void heapify_down();

  public:
    MinHeap();
    bool is_empty();
    int get_idx_parent_of(int idx);
    int get_idx_lchild_of(int idx);
    int get_idx_rchild_of(int idx);
    bool has_lchild(int idx);
    bool has_rchild(int idx);
    void insert(int n);
    int pop();
};

void MinHeap::heapify_up() {
    int idx;
    int n;

    if (this->m_size == 0 || this->m_size == 1)
        return;

    idx = this->m_size - 1;
    n = this->get_idx_parent_of(idx);
    while (this->m_data[idx] < this->m_data[n]) {
        std::swap(this->m_data[idx], this->m_data[n]);
        idx = n;
        if (idx == 0)
            break;
        n = this->get_idx_parent_of(idx);
    }
}

void MinHeap::heapify_down() {
    int idx;
    int l_idx, r_idx, c_idx = -1;

    if (this->m_size == 0 || this->m_size == 1)
        return;

    idx = 0;
    while (idx != -1) {
        l_idx = -1;
        r_idx = -1;
        c_idx = -1;
        if (this->has_lchild(idx))
            l_idx = this->get_idx_lchild_of(idx);
        if (this->has_rchild(idx))
            r_idx = this->get_idx_rchild_of(idx);

        if ((l_idx == -1) && (r_idx == -1))
            break;

        if (l_idx != -1) {
            c_idx = l_idx;
            if (r_idx != -1 &&
                this->m_data[c_idx] !=
                    std::min(this->m_data[l_idx], this->m_data[r_idx])) {
                c_idx = r_idx;
            }
        }
        if (c_idx != -1 && this->m_data[c_idx] < this->m_data[idx])
            std::swap(this->m_data[c_idx], this->m_data[idx]);
        idx = c_idx;
    }
}

MinHeap::MinHeap() { this->m_size = 0; }

bool MinHeap::is_empty() { return (this->m_size == 0 ? true : false); }
int MinHeap::get_idx_parent_of(int idx) { return (idx - 1) / 2; }
int MinHeap::get_idx_lchild_of(int idx) { return idx * 2 + 1; }
int MinHeap::get_idx_rchild_of(int idx) { return idx * 2 + 2; }

bool MinHeap::has_lchild(int idx) {
    return (get_idx_lchild_of(idx) < (this->m_size));
}

bool MinHeap::has_rchild(int idx) {
    return (get_idx_rchild_of(idx) < (this->m_size));
}

void MinHeap::insert(int n) {
    this->m_data[this->m_size++] = n;
    this->heapify_up();
}

int MinHeap::pop() {
    int popped;

    if (this->m_size == 0) {
        return 0;
    }
    popped = this->m_data[0];
    if (this->m_size != 1) {
        this->m_data[0] = this->m_data[this->m_size - 1];
    }
    this->m_size--;
    this->heapify_down();

    return popped;
}

int main() {
    MinHeap mh;
    int N;

    // reopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int x;

        std::cin >> x;
        if (x == 0) {
            std::cout << mh.pop() << "\n";
        } else {
            mh.insert(x);
        }
    }
    return 0;
}
