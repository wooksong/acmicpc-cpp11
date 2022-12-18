#include <iostream>
#include <unordered_map>

constexpr size_t SIZE_DICT = 500000;

int main() {
    std::unordered_map<int, int> dict;
    int N, M;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    dict.reserve(SIZE_DICT);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int card;

        std::cin >> card;
        dict[card] = 1;
    }

    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int card;

        std::cin >> card;
        std::cout << (dict.find(card) == dict.end() ? 0 : 1) << " ";
    }

    std::cout << "\n";

    return 0;
}
