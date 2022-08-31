#include <iostream>

constexpr size_t MAX_NUM_DATA = 100001;

class Stack {
  public:
    Stack() {
        this->m_pos = 0;
        this->m_size = 0;
    }
    bool empty();
    size_t size();
    int32_t pop();
    void push(int32_t v);
    int32_t top();

  private:
    int32_t m_data[MAX_NUM_DATA];
    size_t m_pos;
    size_t m_size;
};

bool Stack::empty() {
    if (this->m_size)
        return false;
    return true;
}

size_t Stack::size() { return this->m_size; }

int32_t Stack::pop() {
    if (this->empty())
        return -1;
    this->m_size--;
    return this->m_data[--this->m_pos];
}

void Stack::push(int32_t v) {
    this->m_size++;
    this->m_data[this->m_pos++] = v;
}

int32_t Stack::top() {
    if (this->empty())
        return -1;
    return this->m_data[this->m_pos - 1];
}

int32_t main() {
    uint32_t N;
    std::string cmd;
    Stack stck = Stack();

    /// freopen("input.txt", "r", stdin);
    std::cin >> N;
    std::cin.ignore();
    for (uint32_t i = 0; i < N; ++i) {

        std::getline(std::cin, cmd, '\n');

        if (cmd == "top") {
            std::cout << stck.top() << "\n";
        } else if (cmd == "size") {
            std::cout << stck.size() << "\n";
        } else if (cmd == "empty") {
            if (stck.empty()) {
                std::cout << "1\n";
            } else {
                std::cout << "0\n";
            }
        } else if (cmd == "pop") {
            std::cout << stck.pop() << "\n";
        } else {
            size_t pos = cmd.find(' ', 0);
            std::string subcmd = std::string(cmd, 0, pos);
            std::string arg = std::string(cmd, pos + 1);
            int32_t num_arg = 0;
            int32_t mul = 1;

            for (auto iter = arg.rbegin(); iter != arg.rend(); ++iter) {
                int32_t digit = static_cast<int32_t>(*iter - '0');

                digit *= mul;
                num_arg += digit;
                mul *= 10;
            }

            if (subcmd == "push") {
                stck.push(num_arg);
            }
        }
    }
}
