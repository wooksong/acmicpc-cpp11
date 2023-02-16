#include <iostream>

int main() {
    std::string line;
    int N;

    // freopen("input.txt", "r", stdin);

    std::cin >> N;
    std::cin.ignore();
    for (int i = 0; i < N; ++i) {
        std::string word;
        size_t len;

        std::getline(std::cin, line);
        len = line.length();
        for (size_t i = 0; i <= len; ++i) {
            if (i == len || line[i] == ' ' || line[i] == '\n') {
                for (auto riter = word.rbegin(); riter != word.rend();
                     ++riter) {
                    std::cout << *riter;
                }

                std::cout << (i == len || line[i] == '\n' ? '\n' : line[i]);
                word.clear();
            } else {
                word.push_back(line[i]);
            }
        }
    }

    return 0;
}
