#include <iostream>

constexpr int MAX_SIZE_DEQUE = 51;

class Deque {
  private:
    int m_data[MAX_SIZE_DEQUE];
    int m_size;
    int m_head;
    int m_tail;

  public:
    Deque() {
        m_size = 0;
        m_head = -1;
        m_tail = -1;
    };

    bool empty();
    int size();
    void clear();
    void push_front(int val);
    void push_back(int val);
    int pop_front();
    int pop_back();
    int head();
    int tail();
    int find(int val);
};

bool Deque::empty() {
    if (this->m_size == 0 && this->m_head == -1 && this->m_tail == -1)
        return true;
    return false;
}

int Deque::size() { return this->m_size; }

void Deque::clear() {
    m_size = 0;
    m_head = -1;
    m_tail = -1;
}

void Deque::push_front(int val) {
    if (this->empty()) {
        this->m_head = 0;
        this->m_tail = 0;
        this->m_size = 1;
        this->m_data[0] = val;
        return;
    }

    this->m_size++;
    if (this->m_head == 0) {
        this->m_head = MAX_SIZE_DEQUE - 1;
    } else {
        --this->m_head;
    }

    this->m_data[this->m_head] = val;
}
void Deque::push_back(int val) {
    if (this->empty()) {
        this->m_head = 0;
        this->m_tail = 0;
        this->m_size = 1;
        this->m_data[0] = val;
        return;
    }

    this->m_size++;
    if (this->m_tail == (MAX_SIZE_DEQUE - 1)) {
        this->m_tail = 0;
    } else {
        ++this->m_tail;
    }

    this->m_data[this->m_tail] = val;
}

int Deque::pop_front() {
    int ret = this->m_data[this->m_head];

    --this->m_size;

    if (this->m_head == (MAX_SIZE_DEQUE - 1)) {
        this->m_head = 0;
    } else {
        ++this->m_head;
    }

    if (this->m_size == 1) {
        this->m_tail = this->m_head;
    } else if (this->empty()) {
        this->clear();
    }

    return ret;
}

int Deque::pop_back() {
    int ret = this->m_data[this->m_tail];

    --this->m_size;

    if (this->m_tail == 0) {
        this->m_tail = MAX_SIZE_DEQUE - 1;
    } else {
        --this->m_tail;
    }

    if (this->m_size == 1) {
        this->m_head = this->m_tail;
    } else if (this->empty()) {
        this->clear();
    }

    return ret;
}

int Deque::head() { return this->m_data[this->m_head]; }

int Deque::tail() { return this->m_data[this->m_tail]; }

int Deque::find(int val) {
    for (int i = 0; i < m_size; ++i) {
        int idx = this->m_head + i;

        if (idx > (MAX_SIZE_DEQUE - 1)) {
            idx -= MAX_SIZE_DEQUE;
        }

        if (m_data[idx] == val) {
            return i;
        }
    }
    return -1;
}

int main() {
    int N, M, cnt;
    Deque dq;

    // freopen("input.txt", "r", stdin);

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        dq.push_back(i + 1);
    }

    cnt = 0;
    for (int i = 0; i < M; ++i) {
        int val;

        std::cin >> val;
        if (val == dq.head()) {
            dq.pop_front();
        } else {
            int popped;
            int idx = dq.find(val);

            if ((dq.size() / 2) >= idx) {
                while (dq.head() != val) {
                    popped = dq.pop_front();
                    dq.push_back(popped);
                    ++cnt;
                }
            } else {
                while (dq.head() != val) {
                    popped = dq.pop_back();
                    dq.push_front(popped);
                    ++cnt;
                }
            }
            dq.pop_front();
        }
    }

    std::cout << cnt << "\n";
    return 0;
}
