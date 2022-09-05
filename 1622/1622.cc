#include <iostream>
#include <vector>

constexpr size_t NUM_ALPHABET = 26;

int main() {
    std::vector<int> stat_string_a = std::vector<int>(NUM_ALPHABET, 0);
    std::vector<int> stat_string_b = std::vector<int>(NUM_ALPHABET, 0);
    std::string string_a, string_b;

    // freopen("input.txt", "r", stdin);
    while (std::getline(std::cin, string_a) &&
           std::getline(std::cin, string_b)) {
        for (auto iter = string_a.begin(); iter != string_a.end(); ++iter) {
            size_t idx = static_cast<size_t>(*iter - 'a');

            stat_string_a[idx]++;
        }

        for (auto iter = string_b.begin(); iter != string_b.end(); ++iter) {
            size_t idx = static_cast<size_t>(*iter - 'a');

            stat_string_b[idx]++;
        }

        for (size_t i = 0; i < NUM_ALPHABET; ++i) {
            for (int j = 0; j < std::min(stat_string_a[i], stat_string_b[i]);
                 ++j) {
                std::cout << static_cast<char>(i + 'a');
            }
        }

        std::cout << "\n";

        std::fill(stat_string_a.begin(), stat_string_a.end(), 0);
        std::fill(stat_string_b.begin(), stat_string_b.end(), 0);
    }

    return 0;
}
