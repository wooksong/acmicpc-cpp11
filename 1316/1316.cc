#include <bitset>
#include <iostream>

constexpr int NUM_ALPHA = 26;
std::bitset<NUM_ALPHA> flag_alpha;

int main() {
    int num_words;
    int cnt;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_words;

    cnt = 0;
    for (int i = 0; i < num_words; ++i) {
        std::string word;
        char prev = '_';
        bool is_group_word;
        int idx;

        flag_alpha.reset();
        std::cin >> word;

        idx = 0;
        is_group_word = true;
        for (char letter : word) {
            int val = static_cast<int>(letter - 'a');

            if (idx != 0 && flag_alpha.test(val) && prev != letter) {
                is_group_word = false;
                break;
            }
            idx++;
            prev = letter;
            flag_alpha.set(val);
        }
        if (is_group_word)
            cnt++;
    }
    std::cout << cnt << "\n";

    return 0;
}
