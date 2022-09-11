#include <iostream>

constexpr int MAX_NUM_DOCS = 101;

struct Document {
    int idx;
    int priority;

    Document() {
        idx = -1;
        priority = -1;
    }

    Document(int i, int p) {
        idx = i;
        priority = p;
    }

    friend bool operator==(Document &lhs, Document &rhs);
    friend bool operator!=(Document &lhs, Document &rhs);
    friend bool operator>(Document &lhs, Document &rhs);
    friend bool operator<(Document &lhs, Document &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Document &d);
};

bool operator==(Document &lhs, Document &rhs) {
    return (lhs.priority == rhs.priority && lhs.idx == rhs.idx);
}

bool operator!=(Document &lhs, Document &rhs) { return !(lhs == rhs); }
bool operator>(Document &lhs, Document &rhs) {
    if (lhs.priority == rhs.priority)
        return lhs.idx < rhs.idx;
    if (lhs.priority > rhs.priority)
        return true;

    return false;
}

bool operator<(Document &lhs, Document &rhs) {
    if (lhs.priority == rhs.priority)
        return lhs.idx > rhs.idx;
    if (lhs.priority < rhs.priority)
        return true;

    return false;
}

std::ostream &operator<<(std::ostream &os, const Document &d) {
    std::cout << "(" << d.idx << "," << d.priority << ")";
    return os;
}
class PDeque {
  private:
    int m_head;
    int m_tail;
    int m_size;

    Document m_data[MAX_NUM_DOCS];

  public:
    bool empty();
    int size();
    void clear();
    Document pop();
    void push(Document &doc);
    void show();
    void clone(Document *dst) {
        std::copy(this->m_data, this->m_data + MAX_NUM_DOCS, dst);
    };
    Document first() { return this->m_data[m_head]; };
    Document last() { return this->m_data[m_tail]; };
    PDeque() { clear(); }
};

bool PDeque::empty() {
    if (this->m_size == 0)
        return true;
    return false;
}

int PDeque::size() { return this->m_size; }

void PDeque::clear() {
    this->m_head = -1;
    this->m_tail = -1;
    this->m_size = 0;
}

Document PDeque::pop() {
    Document ret = this->m_data[this->m_head];

    --this->m_size;
    ++this->m_head;
    if (this->m_head == MAX_NUM_DOCS) {
        this->m_head = 0;
    }

    if (this->m_size == 1) {
        this->m_tail = this->m_head;
    }

    return ret;
}

void PDeque::push(Document &dcmt) {
    ++this->m_size;
    ++this->m_tail;

    if (this->m_tail == MAX_NUM_DOCS) {
        this->m_tail = 0;
    }

    if (this->m_size == 1) {
        this->m_data[0] = dcmt;
        this->m_head = 0;
        this->m_tail = 0;
    } else {
        this->m_data[this->m_tail] = dcmt;
    }
}

void PDeque::show() {
    for (int i = 0; i < this->m_size; ++i) {
        int idx = i + this->m_head;
        if (idx >= MAX_NUM_DOCS) {
            idx -= MAX_NUM_DOCS;
        }
        std::cout << this->m_data[idx] << " ";
    }

    std::cout << "\n";
}

Document tmp[MAX_NUM_DOCS];
void merge(Document *dcmts, int s, int m, int e);
void sort(Document *dcmts, int s, int e);

int main() {
    int T, N, M, cnt, pos;
    PDeque queue = PDeque();
    Document sorted[MAX_NUM_DOCS];

    // freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        std::cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            Document d;

            d.idx = i;
            std::cin >> d.priority;
            queue.push(d);
        }

        queue.clone(sorted);
        sort(sorted, 0, N);
        cnt = 1;
        pos = 0;
        while (!queue.empty()) {
            Document popped;

            while ((queue.first().idx != sorted[pos].idx) &&
                   (queue.first().priority != sorted[pos].priority)) {
                Document d = queue.pop();

                queue.push(d);
            }
            popped = queue.pop();

            if (popped.idx == M)
                break;
            cnt++;
            pos++;
        }
        std::cout << cnt << "\n";
        queue.clear();
    }

    return 0;
}

void merge(Document *dcmts, int s, int m, int e) {
    int i, j, pos;
    i = s;
    j = m;
    pos = i;

    while (i < m && j < e) {
        if (dcmts[i] > dcmts[j]) {
            tmp[pos++] = dcmts[i++];
        } else {
            tmp[pos++] = dcmts[j++];
        }
    }

    for (int ii = i; ii < m; ++ii) {
        tmp[pos++] = dcmts[ii];
    }

    for (int jj = j; jj < e; ++jj) {
        tmp[pos++] = dcmts[jj];
    }

    for (int i = s; i < e; ++i) {
        dcmts[i] = tmp[i];
    }
}
void sort(Document *dcmts, int s, int e) {
    int m;

    if ((e - s) == 1) {
        return;
    }

    m = (e - s) / 2 + s;

    sort(dcmts, s, m);
    sort(dcmts, m, e);
    merge(dcmts, s, m, e);
}
