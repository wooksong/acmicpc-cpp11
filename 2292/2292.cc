#include <iostream>

int main() {
    uint32_t N;
    uint32_t room = 1;
    uint32_t i;
    uint32_t prev_room;

    std::cin >> N;
    for (i = 0;; ++i) {
        room += 6 * i;
        if (room > N) {
            break;
        }
        prev_room = room;
    }

    if (prev_room == N) {
        std::cout << i << "\n";
    } else {
        std::cout << i + 1 << "\n";
    }

    return 0;
}
