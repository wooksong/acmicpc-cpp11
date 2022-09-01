#include <iostream>

constexpr size_t MAX_NUM_DATA = 10001;
constexpr size_t INVAL_POS = MAX_NUM_DATA + 1;

class Deque {
  public:
    Deque();
    void push_front(int32_t val);
    void push_back(int32_t val);
    int32_t pop_front();
    int32_t pop_back();
    int32_t front();
    int32_t back();
    bool empty();
    size_t size();

  private:
    int32_t m_data[MAX_NUM_DATA];
    size_t m_size;
    size_t m_pos_front;
    size_t m_pos_back;
};

Deque::Deque() {
    this->m_size = 0;
    this->m_pos_front = INVAL_POS;
    this->m_pos_back = INVAL_POS;
}

void Deque::push_front(int32_t val) {
    if (this->empty()) {
        this->m_pos_front = this->m_pos_back = MAX_NUM_DATA / 2;
    } else {
        if (this->m_pos_front == 0) {
            this->m_pos_front = MAX_NUM_DATA - 1;
        } else {
            this->m_pos_front--;
        }
    }
    this->m_data[this->m_pos_front] = val;
    this->m_size++;
}

void Deque::push_back(int32_t val) {
    if (this->empty()) {
        this->m_pos_front = this->m_pos_back = MAX_NUM_DATA / 2;
    } else {
        this->m_pos_back++;
        if (this->m_pos_back == MAX_NUM_DATA) {
            this->m_pos_back = 0;
        }
    }

    this->m_data[this->m_pos_back] = val;
    this->m_size++;
}

int32_t Deque::pop_front() {
    int32_t ret = -1;

    if (this->empty())
        return ret;

    this->m_size--;
    ret = this->m_data[this->m_pos_front];
    this->m_pos_front++;
    if (this->m_pos_front == MAX_NUM_DATA) {
        this->m_pos_front = 0;
    }

    if (this->size() == 1) {
        this->m_pos_back = this->m_pos_front;
    } else if (this->empty()) {
        this->m_pos_front = this->m_pos_back = INVAL_POS;
    }

    return ret;
}

int32_t Deque::pop_back() {
    int32_t ret = -1;

    if (this->empty())
        return ret;

    this->m_size--;
    ret = this->m_data[this->m_pos_back];
    if (this->m_pos_back == 0) {
        this->m_pos_back = MAX_NUM_DATA - 1;
    } else {
        this->m_pos_back--;
    }

    if (this->size() == 1) {
        this->m_pos_front = this->m_pos_back;
    } else if (this->empty()) {
        this->m_pos_front = this->m_pos_back = INVAL_POS;
    }

    return ret;
}

int32_t Deque::front() {
    return (this->empty() ? -1 : this->m_data[this->m_pos_front]);
}

int32_t Deque::back() {
    return (this->empty() ? -1 : this->m_data[this->m_pos_back]);
}

bool Deque::empty() { return (this->m_size == 0) ? true : false; }

size_t Deque::size() { return this->m_size; }

int main() {
    uint32_t N;
    Deque dq;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;
    for (uint32_t i = 0; i < N; ++i) {
        std::string cmd;

        std::cin >> cmd;
        if ((cmd == "push_front") || (cmd == "push_back")) {
            int32_t val;

            std::cin >> val;

            cmd == "push_front" ? dq.push_front(val) : dq.push_back(val);
        } else if (cmd == "pop_front") {
            std::cout << dq.pop_front() << "\n";
        } else if (cmd == "pop_back") {
            std::cout << dq.pop_back() << "\n";
        } else if (cmd == "front") {
            std::cout << dq.front() << "\n";
        } else if (cmd == "back") {
            std::cout << dq.back() << "\n";
        } else if (cmd == "size") {
            std::cout << dq.size() << "\n";
        } else {
            std::cout << (dq.empty() ? 1 : 0) << "\n";
        }
    }
    return 0;
}
