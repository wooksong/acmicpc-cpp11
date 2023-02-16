#include <iostream>

int main() {
    std::string pattern;
    int N;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;
    std::cin.ignore();

    std::getline(std::cin, pattern);
    for (int i = 1; i < N; ++i) {
        std::string tmp;
        size_t pos;

        std::getline(std::cin, tmp);

        pos = 0;
        for (auto iter = tmp.begin(); iter != tmp.end(); ++iter, ++pos) {
            if (pattern[pos] == *iter)
                continue;
            pattern[pos] = '?';
        }
    }

    std::cout << pattern << "\n";

    return 0;
}
