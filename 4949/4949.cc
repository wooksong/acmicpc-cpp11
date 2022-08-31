#include <iostream>

constexpr int32_t MAX_LEN_INPUT = 101;

class Stack {
  public:
    Stack();
    void push(char p);
    char pop();
    bool is_empty();
    void clear();

  private:
    size_t m_size;
    size_t m_pos;
    char m_data[MAX_LEN_INPUT];
};

Stack::Stack() {
    this->m_pos = 0;
    this->m_size = 0;
}

void Stack::push(char p) {
    this->m_data[this->m_pos++] = p;
    this->m_size++;
}

char Stack::pop() {
    this->m_size--;
    return this->m_data[--this->m_pos];
}

bool Stack::is_empty() { return this->m_size == 0 ? true : false; }

void Stack::clear() {
    this->m_pos = 0;
    this->m_size = 0;
}

int main() {
    Stack stck;
    std::string in_sentence;

    // freopen("input.txt", "r", stdin);
    while (std::getline(std::cin, in_sentence)) {
        bool is_balanced = true;
        char poped;

        stck.clear();
        if (in_sentence.size() == 1 && in_sentence[0] == '.') {
            break;
        }

        for (auto iter = in_sentence.begin(); *iter != '.'; ++iter) {
            switch (*iter) {
            case '(':
            case '[':
                stck.push(*iter);
                break;
            case ')':
            case ']':
                if (!stck.is_empty()) {
                    poped = stck.pop();
                    if (((*iter == ')' && poped != '(')) ||
                        ((*iter == ']' && poped != '['))) {
                        is_balanced = false;
                    }
                } else {
                    is_balanced = false;
                }
                break;
            default:
                break;
            }

            if (!is_balanced)
                break;
        }

        if (!stck.is_empty()) {
            is_balanced = false;
        }

        std::string msg = is_balanced ? "yes\n" : "no\n";
        std::cout << msg;
    }
    return 0;
}
