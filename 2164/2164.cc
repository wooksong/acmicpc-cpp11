#include <iostream>
#include <vector>

size_t head, tail, size;

uint32_t pop(std::vector<uint32_t> &v);
void push(std::vector<uint32_t> &v, uint32_t n);
bool is_empty();

int main() {
    uint32_t N;
    std::vector<uint32_t> cards;

    std::cin >> N;
    cards = std::vector<uint32_t>(N);
    size = 0;
    for (uint32_t i = 0; i < N; ++i) {
        cards[i] = i + 1;
        size++;
    }

    head = 0;
    tail = N - 1;

    while (size > 1) {
        uint32_t to_push;
        pop(cards);
        to_push = pop(cards);
        push(cards, to_push);
    }

    std::cout << cards[head] << "\n";

    return 0;
}
bool is_empty() {
    if (size == 0)
        return true;
    return false;
}

uint32_t pop(std::vector<uint32_t> &v) {
    uint32_t ret;

    if (is_empty())
        return 0;

    ret = v[head];

    head++;
    size--;
    if (head == v.capacity()) {
        head = 0;
    }
    return ret;
}

void push(std::vector<uint32_t> &v, uint32_t n) {
    if (size == v.capacity())
        return;
    tail += 1;
    size++;
    if (tail == v.capacity()) {
        tail = 0;
    }

    v[tail] = n;
}
