#include <iostream>
#include <vector>

constexpr int NUM_ALPHA = 26;

std::vector<int> cnts_alpha(NUM_ALPHA);

int main() {
    int num_words;
    int num_teams;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> num_words;
    std::fill_n(cnts_alpha.begin(), NUM_ALPHA, 0);
    for (int i = 0; i < num_words; ++i) {
        std::string word;
        int idx;

        std::cin >> word;
        idx = static_cast<int>(word[0] - 'a');
        cnts_alpha[idx]++;
    }

    num_teams = 0;
    for (int i = 0; i < NUM_ALPHA; ++i) {
        if (cnts_alpha[i] >= 5) {
            num_teams++;
            std::cout << static_cast<char>(i + 'a');
        }
    }

    if (num_teams == 0) {
        std::cout << "PREDAJA";
    }
    std::cout << "\n";

    return 0;
}
